#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include "database/timerElements.h"
#include "includes/Graph.h"



class StatisticsWindow : public QWidget {
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr);
    void initializeWindow();
    Q_INVOKABLE void openWindow();
    GraphWidget *graphWidget;
    QString formatTime(double totalSeconds) {
        int hours = static_cast<int>(totalSeconds) / 3600;
        int minutes = (static_cast<int>(totalSeconds) % 3600) / 60;
        int seconds = (static_cast<int>(totalSeconds) % 60);
        return QString("%1h %2m %3s").arg(hours).arg(minutes).arg(seconds);
    };

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
