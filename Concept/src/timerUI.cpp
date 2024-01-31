//timerUI.cpp

#include <QAction>
#include "timerUI.h"
#include <QDebug>
#include <QCursor>
#include <QQmlContext>
#include <iostream>
#include "QtQml/qqmlapplicationengine.h"
#include "studytimer.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWidget>
#include <QMenu>




timerStart::timerStart(QObject *parent) :
    QObject(parent),
    startAction("Start", this),
    pauseAction("Pause", this),
    continueAction("Continue", this),
    stopAction("Stop", this),
    started(0),
    paused(0)

{

    QAction *action15 = new QAction("15 Minutes", this);
    QAction *action30 = new QAction("30 Minutes", this);
    QAction *action45 = new QAction("45 Minutes", this);
    QAction *action60 = new QAction("1 Hour", this);
    QAction *action1 = new QAction("1 min", this);

    QAction *break5 = new QAction("5 Minutes", this);
    QAction *break10 = new QAction("10 Minutes", this);
    QAction *break15 = new QAction("15 Minutes", this);
    QAction *break20 = new QAction("20 Minutes", this);
    QAction *breakUntil = new QAction("Until continued", this);
    QAction *break10s = new QAction("10 Seconds", this);

    connect(&startAction, &QAction::triggered, this, &timerStart::startTheTimer);
    connect(&pauseAction, &QAction::triggered, this, &timerStart::pauseTimer);
    connect(&continueAction, &QAction::triggered, this, &timerStart::continueTimer);
    connect(&stopAction, &QAction::triggered, this, &timerStart::stopTimer);

    connect(action15, &QAction::triggered, this, [=]() { chooseTime(15); });
    connect(action30, &QAction::triggered, this, [=]() { chooseTime(30); });
    connect(action45, &QAction::triggered, this, [=]() { chooseTime(45); });
    connect(action60, &QAction::triggered, this, [=]() { chooseTime(60); });
    connect(action1, &QAction::triggered, this, [=]() { chooseTime(1); });


    connect(break5, &QAction::triggered, this, [=]() { chooseBreak(0, 5); });
    connect(break10, &QAction::triggered, this, [=]() { chooseBreak(0, 10); });
    connect(break15, &QAction::triggered, this, [=]() { chooseBreak(0, 15); });
    connect(break20, &QAction::triggered, this, [=]() { chooseBreak(0, 20); });
    connect(break10s, &QAction::triggered, this, [=]() { chooseBreak(10, 0); });
    connect(breakUntil, &QAction::triggered, this, &timerStart::chooseBreakUntil);

    q_timer = new QTimer(this);
    q_timer->start(1000);
    connect(q_timer, &QTimer::timeout, this, &timerStart::qTimerTimeout);
    connect(this, &timerStart::timerFinished, this, &timerStart::onTimerFinished);

    time_menu.addAction(action15);
    time_menu.addAction(action30);
    time_menu.addAction(action45);
    time_menu.addAction(action60);
    time_menu.addAction(action1);

    break_menu.addAction(break10s);
    break_menu.addAction(break5);
    break_menu.addAction(break10);
    break_menu.addAction(break15);
    break_menu.addAction(break20);
    break_menu.addAction(breakUntil);
}

void startTimer(QApplication* app) {
    qmlRegisterType<timerStart>("Custom Controls", 1, 0, "TimerStart");

    QQmlApplicationEngine engine;
    timerStart myTimerStart;
    engine.rootContext()->setContextProperty("TimerStart", &myTimerStart);

    engine.load(QUrl(QStringLiteral("qrc:/Main/main.qml")));
    if (engine.rootObjects().isEmpty())
        exit(-1);

    app->exec();
}


void timerStart::chooseTime(int minutes) {

    if (started) {
        emit timerFinished();
    }
    delete timer;
    timer = new CountDownTimer(0, minutes, 0);
    timer->countdowntimer = 1;
    time_string = createTimeString(timer->hour, timer->minute, timer->second);
    emit timeChanged();

}

void timerStart::startTheTimer() {


    if (!started) {
        qDebug() << "starting timer";
        timer->counting = 1;
        started = 1;
        start_time = get_time();
        last_go_time = get_time(); }

    else {
        //emit errorMessage();
    }
}

bool timerStart::update_time(Timer *t) {

    // qDebug() << "updating time";

    if (!t->countdowntimer) {
        if (t->second != 59) {t->second ++;}
        else {t->second = 0;
            if (t->minute != 59) {t->minute ++;}
            else {t->minute = 0;
                t->hour ++;}
        }
    } else {
        if (t->second != 0) {t->second --;}
        else {t->second = 59;
            if (t->minute != 0) {t->minute --;}
            else {t->minute = 59;
                t->hour --;}
        }
    }

    time_string = createTimeString(t->hour, t->minute, t->second);
    emit timeChanged();

    if (t->second == 0 && t->minute == 0 && t->hour == 0) {
        qDebug() << "timer zeroed";
        // if (break_timer.counting) {
        //     break_timer.counting = 0;
        //     if (started) {
        //         timer.counting = 1;
        //     }
        // } else {
        //     emit timerFinished();
        // }
        t->counting = 0;
    }

    return t->counting;
}

void timerStart::qTimerTimeout () {

    // qDebug() << "qTimerTimeout";
    // qDebug() << "timer.counting: " << timer.counting;

    if (timer->counting) {
        timer->counting = update_time(timer);
    }

    else if (break_timer->counting) {
        break_timer->counting = update_time(break_timer);
        if (break_timer->counting == 0) {
            qDebug() << "break timer finished";
            if (!started) {
                emit timerFinished();
            } else {
                continueTimer();
            }
            delete break_timer;
            break_timer = new CountUpTimer();
            set_time_string(timer);       }
    }

    else if (started) {
        emit timerFinished();
    }



}

void timerStart::showTimeMenu() {
    time_menu.exec(QCursor::pos());
}

void timerStart::showBreakMenu() {
    break_menu.exec(QCursor::pos());
}

void timerStart::chooseBreak(int s, int m) {
    pauseTimer();
    delete break_timer;
    break_timer = new CountDownTimer(s, m, 0);
    break_timer->counting = 1;
    set_time_string(break_timer);

    if (started == 0) {
        last_stop_time = get_time();
    }
}

void timerStart::chooseBreakUntil() {
    pauseTimer();
    delete break_timer;
    break_timer = new CountUpTimer();
    break_timer->counting = 1;
    set_time_string(break_timer);

    if (started == 0) {
        last_stop_time = get_time();
    }
}

void timerStart::pauseTimer() {

    if (started) {
        timer->counting = 0;
        last_stop_time = get_time();
        total_focus_time += difftime(last_stop_time, last_go_time);
        paused = 1;
    } else {
        //error
    }
}

void timerStart::continueTimer() {

    if (!timer->counting) {

        if (started) {
            timer->counting = 1;
            last_go_time = get_time();
            total_break_time += difftime(last_go_time, last_stop_time);
            paused = 0; }

        if (break_timer->counting) {
            delete break_timer;
            break_timer = new CountUpTimer();
            set_time_string(timer);
        }

    }
}

void timerStart::stopTimer() {
    emit timerFinished();
}

void timerStart::onTimerFinished() {

    finishing_time = get_time();

    if (started) {

        if (!paused) {
            total_focus_time += difftime(finishing_time, last_go_time);
        } else {
            total_break_time += difftime(finishing_time, last_stop_time);
        }
    }

    else if (break_timer->countdowntimer) {
        total_break_time = difftime(finishing_time, last_stop_time);
        total_focus_time = 0;
    }

    else {
        total_break_time = 0;
        total_focus_time = 0;
    }

    qDebug() << "focus: " << total_focus_time;
    qDebug() << "break: " << total_break_time;

    //store total_focus_time and total_break_time here
    timerElements timerStats = timerElements();

    timerStats.totalFocusTime = total_focus_time;
    timerStats.totalBreakTime = total_break_time;
    timerStats.startTime = start_time;
    QSqlError daoError = qx::dao::insert(timerStats);

    started = 0;
    paused = 0;
    delete timer;
    delete break_timer;
    timer = new CountUpTimer();
    break_timer = new CountUpTimer();
    set_time_string(timer);
    total_focus_time = 0;
    total_break_time = 0;
    last_go_time = get_time();
    last_stop_time = get_time();
    start_time = get_time();
    finishing_time = get_time();

    qDebug() << "timer finished";

}
