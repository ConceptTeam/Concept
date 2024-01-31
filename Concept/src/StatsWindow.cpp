#include "StatsWindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QVector>
#include <QDate>


#include "includes/Graph.h"





StatisticsWindow::StatisticsWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Initialize labels with styles and add them to the layout
    QString labelStyle = "QLabel { "
                         "font-family: 'Arial'; "
                         "font-size: 18px; "
                         "color: ##b38f4d;"
                         "margin: 5px 0;"
                         "}";
    totalTimeEverLabel = new QLabel(this);
    totalTimeEverLabel->setStyleSheet(labelStyle);

    layout->addWidget(totalTimeEverLabel);

    totalTimeTodayLabel = new QLabel(this);
    totalTimeTodayLabel->setStyleSheet(labelStyle);
    layout->addWidget(totalTimeTodayLabel);

    totalTimeLastWeekLabel = new QLabel(this);
    totalTimeLastWeekLabel->setStyleSheet(labelStyle);
    layout->addWidget(totalTimeLastWeekLabel);

    averagePerDayLastWeekLabel = new QLabel(this);
    averagePerDayLastWeekLabel->setStyleSheet(labelStyle);
    layout->addWidget(averagePerDayLastWeekLabel);

    increaseComparedToYesterdayLabel = new QLabel(this);
    increaseComparedToYesterdayLabel->setStyleSheet(labelStyle);
    layout->addWidget(increaseComparedToYesterdayLabel);

    // Initialize and add the GraphWidget to the layout
    graphWidget = new GraphWidget(this);
    graphWidget->setFixedSize(400, 300);
    layout->addWidget(graphWidget);

    setLayout(layout);





}


void StatisticsWindow::initializeWindow() {
    // Now perform database operations or other initializations
    calculateStatistics();

}

void StatisticsWindow::calculateStatistics() {




    double totalTimeEver = 0.0, totalTimeToday = 0.0, totalTimeLastWeek = 0.0;
    double averagePerDayLastWeek = 0.0, increaseComparedToYesterday = 0.0;
    QMap<QDate, double> dailyTimes;
    QVector<double> studyTimeLastSevenDays(7, 0.0);
    QDate currentDate = QDate::currentDate();
    QDate weekAgo = currentDate.addDays(-7);
    QDate yesterday = currentDate.addDays(-1);

    std::vector<timerElements> listTimerElements;
    QSqlError daoError = qx::dao::fetch_all(listTimerElements);

    if (daoError.isValid()) {
        qDebug() << "Error fetching timer data: " << daoError.text();
        return;
    }

    for (const timerElements &element : listTimerElements) {
        QDateTime startTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(element.startTime));
        QDate startDate = startTime.date();
        int dayDiff = currentDate.daysTo(startDate);

        if (dayDiff >= -1 && dayDiff <= 0) {
            studyTimeLastSevenDays[dayDiff+6] += element.totalFocusTime;
        }
    }
    graphWidget->setData(studyTimeLastSevenDays);


    for (const timerElements &element : listTimerElements) {
        QDateTime startTime = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(element.startTime));
        QDate startDate = startTime.date();
        double focusTime = element.totalFocusTime;

        totalTimeEver += focusTime;
        if (startDate == currentDate) {
            totalTimeToday += focusTime;
        }
        if (startDate > weekAgo && startDate <= currentDate) {
            totalTimeLastWeek += focusTime;
            dailyTimes[startDate] += focusTime;
        }
    }

    if (!dailyTimes.isEmpty()) {
        averagePerDayLastWeek = totalTimeLastWeek / dailyTimes.size();
        increaseComparedToYesterday = dailyTimes[currentDate] - dailyTimes[yesterday];
    }

    displayStatistics(totalTimeEver, totalTimeToday, totalTimeLastWeek,
                      averagePerDayLastWeek, increaseComparedToYesterday);
}

void StatisticsWindow::displayStatistics(double totalTimeEver, double totalTimeToday,
                                         double totalTimeLastWeek, double averagePerDayLastWeek,
                                         double increaseComparedToYesterday) {

    totalTimeEverLabel->setText("Total Study Time Ever: " + formatTime(totalTimeEver));
    totalTimeTodayLabel->setText("Total Study Time Today: " + formatTime(totalTimeToday));
    totalTimeLastWeekLabel->setText("Total Study Time Last Week: " + formatTime(totalTimeLastWeek));
    averagePerDayLastWeekLabel->setText("Average Per Day (Last 7 Days): " + formatTime(averagePerDayLastWeek));
    increaseComparedToYesterdayLabel->setText("Increase Compared to Yesterday: " + formatTime(increaseComparedToYesterday));
    ;
}







void StatisticsWindow::openWindow() {
    calculateStatistics();  // Recalculate stats each time the window is opened
    this->show();           // Show the statistics window
}



