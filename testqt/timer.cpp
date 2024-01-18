#include "timer.h"
#include <iostream>
#include <chrono>
#include <QApplication> 
Timer::Timer(QWidget *parent):QWidget(parent)
{
Title = new QLabel("Study Timer",this);
Title->setGeometry(0,0,this->width(),80);
TimerDisplay = new QLabel(timeString, this);
TimerDisplay->setGeometry(0,80,this->width(),80);
startButton = new QPushButton("Start",this);
stopButton = new QPushButton("Stop", this);
connect(startButton,&QPushButton::clicked, this, &Timer::startTimer);
connect(stopButton,&QPushButton::clicked, this, &Timer::stopTimer);

}

Timer::~Timer(){}

void Timer::startTimer(){
timerRunning = true;
const auto duration = std::chrono::seconds(1);
auto start_time = std::chrono::steady_clock::now();
while(timerRunning){

	QCoreApplication::processEvents();
	auto end_time = std::chrono::steady_clock::now(); 
	auto time_passed1 = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
	int time_passed2 = static_cast<int>(time_passed1.count());
	seconds = time_passed2 % 60;
	minutes = (time_passed2 / 60) % 60;
	hours = (time_passed2 / 3600);
	updateTimeString();
}
}

void Timer::stopTimer(){timerRunning = false;}

void Timer::updateTimeString(){
std::string secondString = std::to_string(seconds);
std::string minuteString = std::to_string(minutes);
if (seconds < 10){
	secondString = "0" + std::to_string(seconds); 
}

if (minutes < 10){
	minuteString = "0" + std::to_string(minutes); 
}

if(hours == 0 ){
	timeString = QString::fromStdString(minuteString + ":" + secondString);
}

else{
timeString = QString::fromStdString(std::to_string(hours) + ":" + minuteString + ":" + secondString);
}
TimerDisplay->setText(timeString);
}

void Timer::resizeEvent(QResizeEvent *event){
Title->setGeometry(0,0,this->width(),80);
TimerDisplay->setGeometry(0,80,this->width(),80);
startButton->setGeometry(this->width()/16,160,this->width()/4,20);
stopButton->setGeometry(this->width()*5/8,160,this->width()/4,20);
TimerDisplay->setStyleSheet("text-align: center; font-size: 50;");
Title->setStyleSheet("text-align: center; font-size: 50;");

}
void Timer::addStyle(){
TimerDisplay->setStyleSheet("text-align: center; font-size: 50;");
Title->setStyleSheet("text-align: center; font-size: 50;");
}
