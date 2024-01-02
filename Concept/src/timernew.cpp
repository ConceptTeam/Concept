#include "timernew.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>


int Timer::storeTimer() {
    std::cout << "storing timer" << std::endl;
    return 0;

}

int Timer::display() {

    std::cout << minute << " mins, " << second << " secs. " << std::endl;
    return 0;
}

int Timer::activeCounting() {
    std::cout << "counting" << std::endl;
    if (this->finished) {
        this->stopTimer();
    }
    else {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        this->display();
        this->update_time();
    }

    return 0;

}
int startZeroTimer() {
    std::cout << "started zero timer" << std::endl;
    CountUpTimer current_timer = CountUpTimer();
    CountUpTimer* timer_pointer = &current_timer;
    current_timer.counting = true;

    while (current_timer.counting) {
        (*timer_pointer).activeCounting();
    }

    return 0;

}

int startFocusTimer(int focus_period) {

    std::cout << "started focus timer" << std::endl;
    CountDownTimer current_timer = CountDownTimer(focus_period);

    std::cout << current_timer.counting << std::endl;
    std::cout << current_timer.finished << std::endl;
    CountDownTimer* timer = &current_timer;
    current_timer.counting = true;
    current_timer.finished = false;


    while (current_timer.counting && current_timer.finished==false) {
        current_timer.activeCounting();
    };

    if (current_timer.finished) {
        (*timer).storeTimer();
    }

    return 0;
}



int Timer::userPause() {
    std::cout << "paused" << std::endl;
    this->counting = false;
    this->display();

    return 0;
}

int Timer::userContinue() {
    std::cout << "continue" << std::endl;
    this->counting = true;
    while (this->counting) {
        this->activeCounting();
    }

    return 0;

}

int Timer::stopTimer() {
    this->finished = true;
    this->storeTimer();

    return 0;

}



// struct FocusTime
// {
//     int id;
//     std::time_t creation_time;
//     std::time_t time_spent;

//     FocusTime() = default;
// };

// class FocusTimer


