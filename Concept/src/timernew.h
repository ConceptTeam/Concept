#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

class Timer
{
public:
    
    int second;
    int minute;
    int hour;
    int* current_second;
    int* current_minute;
    int* current_hour;
    bool counting;
    bool finished;

    Timer(int min=0, int h=0) : second(0), minute(min), hour(h),counting(0), finished(0), current_second(&second), current_minute(&minute) {}
    
    virtual ~Timer() {}
    // IMPLEMENT IF NECESSARY
    
    time_t get_time() { //for storing system time

        std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
        time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
        return currentTime_t;
    }

    time_t start_time = get_time();

    int total_time = 0;
    time_t last_start_time = start_time;
    time_t end_time;
    
    int storeTimer();
    int display();
    int activeCounting();
    int userPause();
    int userContinue();
    int stopTimer();
    
    virtual int update_time() {
        if (second != 59) {
            second ++;
        }
        else {
            second = 0;
            if (minute != 59) {
                minute ++;
            }
            else {
                minute = 0;
                hour ++;
            }
        }
        
    }

};

class CountUpTimer : public Timer {
public:

    CountUpTimer() : Timer() {};

};

class CountDownTimer : public Timer {
public:

    CountDownTimer(int focus_minutes, int focus_hours) : Timer(focus_minutes, focus_hours) {};

    virtual int update_time() {
        if (second != 0) {
            second --;
        }
        else {
            second = 59;
            if (minute != 0) {
                minute --;
            }
            else {
                minute = 59;
                hour --;
            }
        }
    }
};





#endif // TIMER_H
