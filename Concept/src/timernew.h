#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>

using Minute = std::chrono::minutes;
using Second = std::chrono::seconds;

class Timer
{
public:



    int second = 0;
    int minute = 0;
    int* current_second = &second;
    int* current_minute = &minute;

    virtual void update_time();

    bool counting = false;
    bool finished = false;

    std::time_t get_time() {

        std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
        std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
        return currentTime_t;
    }

};


class CountUpTimer : public Timer {
public:

    CountUpTimer();

    virtual void update_time() {
        if (*current_second != 59) {
            *current_second ++;
        }
        else {
            *current_second = 0;
            *current_minute ++;
        }
    }
};

class CountDownTimer : public Timer {
public:

    CountDownTimer(int focus_period) {
        *current_minute = focus_period;

    }

    virtual void update_time() {
        if (*current_second != 0) {
            *current_second --;
        }
        else {
            if (*current_minute == 0) {
                finished = true;
            }
            else {
                *current_second = 59;
                *current_minute --;
            }
        }
    }
};




#endif // TIMER_H
