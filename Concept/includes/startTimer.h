
/*
#ifndef STATSTIMER_H
#define STATSTIMER_H
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class StartTimer;
}

class StartTimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartTimer(QWidget *parent = nullptr);
    ~StartTimer();

public slots:
    void updateStatistics(); // Function to update statistics

private:
    Ui::StartTimer *ui;

    QTimer timer; // Assuming you have a QTimer for study time tracking
    QTime totalTime; // Total study time
    int studySessions; // Number of study sessions
};


#endif //STATSTIMER_H

*/
