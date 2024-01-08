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
    int* current_second;
    int* current_minute;
    bool counting;
    bool finished;


    Timer(int min=0) : second(0), minute(min), counting(0), finished(0), current_second(&second), current_minute(&minute) {}
    
    virtual ~Timer() {}
    // IMPLEMENT IF NECESSARY
    
    time_t get_time() { //for storing time at which timer was created and ended

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
            minute ++;
        }
        return 0;
    }


};

class CountUpTimer : public Timer {
public:

    CountUpTimer() : Timer() {};

};

class CountDownTimer : public Timer {
public:

    CountDownTimer(int focus_period) : Timer(focus_period) {};

    virtual int update_time() {
        if (second != 0) {
            second --;
        }
        else {
            if (minute == 0) {
                finished = 1;
            }
            else {
                second = 59;
                minute --;
            }
        }
        return 0;
    }
};




#endif // TIMER_H
