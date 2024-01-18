#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <string>
#include <iostream>
#include <QString>
class Timer: public QWidget
{
public:
    Timer(QWidget *parent = nullptr);
    ~Timer();
    void addStyle();
private:
    QLabel* Title ;
    QLabel* TimerDisplay;
    int seconds;
    int minutes;
    int hours;
    QPushButton* startButton;
    QPushButton* stopButton;
    QString timeString{"00:00"};
    void updateTimeString();


public slots:
 // add public member functions;

private slots:
void startTimer();
void stopTimer();
bool timerRunning{false};

protected:
void resizeEvent(QResizeEvent *event) override;
};



#endif //TIMER_H
