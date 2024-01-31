#include "StatsWindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

StatisticsWindow::StatisticsWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    totalTimeEverLabel = new QLabel(this);
    totalTimeTodayLabel = new QLabel(this);
    totalTimeLastWeekLabel = new QLabel(this);
    averagePerDayLastWeekLabel = new QLabel(this);
    increaseComparedToYesterdayLabel = new QLabel(this);

    layout->addWidget(totalTimeEverLabel);
    layout->addWidget(totalTimeTodayLabel);
    layout->addWidget(totalTimeLastWeekLabel);
    layout->addWidget(averagePerDayLastWeekLabel);
    layout->addWidget(increaseComparedToYesterdayLabel);

    setLayout(layout);
}

void StatisticsWindow::initializeWindow() {
    // Now perform database operations or other initializations
    calculateStatistics();
    // Any other initialization code that requires a fully set up application
}

void StatisticsWindow::calculateStatistics() {
    double totalTimeEver = 0.0, totalTimeToday = 0.0, totalTimeLastWeek = 0.0;
    double averagePerDayLastWeek = 0.0, increaseComparedToYesterday = 0.0;
    QMap<QDate, double> dailyTimes;
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
    totalTimeEverLabel->setText("Total Study Time Ever: " + QString::number(totalTimeEver) + " seconds");
    totalTimeTodayLabel->setText("Total Study Time Today: " + QString::number(totalTimeToday) + " seconds");
    totalTimeLastWeekLabel->setText("Total Study Time Last Week: " + QString::number(totalTimeLastWeek) + " seconds");
    averagePerDayLastWeekLabel->setText("Average Per Day (Last 7 Days): " + QString::number(averagePerDayLastWeek) + " seconds");
    increaseComparedToYesterdayLabel->setText("Increase Compared to Yesterday: " + QString::number(increaseComparedToYesterday) + " seconds");
}







void StatisticsWindow::openWindow() {
    calculateStatistics();  // Recalculate stats each time the window is opened
    this->show();           // Show the statistics window
}
