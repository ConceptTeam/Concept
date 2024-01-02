#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <thread>
#include <ctime>

using namespace std::chrono;
using namespace std::this_thread;
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

    //Timer(int min=0) : second(0), minute(min), counting(0), finished(0), current_second(&second), current_minute(&minute) {}
    Timer(int sec=0) : second(sec), minute(0), counting(0), finished(0), current_second(&second), current_minute(&minute) {}
    
    virtual ~Timer() {}
    
    std::time_t get_time() {

        std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
        std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
        return currentTime_t;
    }

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
                finished = true;
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
