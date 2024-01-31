/*
#include "starttimer.h"


StartTimer::StartTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartTimer)
{
    ui->setupUi(this);

    // Initialize variables
    totalTime.setHMS(0, 0, 0);
    studySessions = 0;

    // Connect the QTimer timeout signal to the updateStatistics slot
    connect(&timer, &QTimer::timeout, this, &StartTimer::updateStatistics);

    // Set up the timer to update statistics every second
    timer.start(1000);
}

StartTimer::~StartTimer()
{
    delete ui;
}

void StartTimer::updateStatistics()
{
    // Assuming you have a function in your timer class to get the current study time
    int currentStudyTimeInSeconds = getCurrentStudyTimeInSeconds();

    // Update total study time
    totalTime = totalTime.addSecs(currentStudyTimeInSeconds);

    // Update the display with the statistics
    ui->totalTimeLabel->setText("Total Study Time: " + totalTime.toString("hh:mm:ss"));
    ui->sessionsLabel->setText("Study Sessions: " + QString::number(++studySessions));
}
*/
