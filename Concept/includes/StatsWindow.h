#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include "database/timerElements.h" // Your timerElements class

class StatisticsWindow : public QWidget {
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr);
    void initializeWindow();
    Q_INVOKABLE void openWindow();

private:
    QLabel *totalTimeEverLabel;
    QLabel *totalTimeTodayLabel;
    QLabel *totalTimeLastWeekLabel;
    QLabel *averagePerDayLastWeekLabel;
    QLabel *increaseComparedToYesterdayLabel;



    void calculateStatistics();
    void displayStatistics(double totalTimeEver, double totalTimeToday,
                           double totalTimeLastWeek, double averagePerDayLastWeek,
                           double increaseComparedToYesterday);
};

#endif // STATISTICSWINDOW_H
