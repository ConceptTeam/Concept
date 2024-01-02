#include "timernew.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>


int Timer::storeTimer() {

    std::cout << "storing timer" << std::endl;

    std::time_t end_time = get_time();

    // id = ???
    // total_time = ?? add functionality to calculate this
    // start_time declared when initializing object
    // end_time declared here


    // IMPLEMENT STORING TIMER INTO DATABASE with these members HERE

    return 0;
}

int Timer::stopTimer() {

    counting = 0;
    storeTimer();

    return 0;

}

int Timer::display() {

    std::cout << minute << " mins, " << second << " secs. " << std::endl;

    // IMPLEMENT CHANGING THE TIME DISPLAYED IN THE APP HERE
    
    return 0;
}

int Timer::activeCounting() {

    // std::cout << "counting" << std::endl;

    if (finished) {
        stopTimer();
    }
    else {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        display();
        update_time();
    }

    return 0;

}

int Timer::userPause() {
    
    std::cout << "paused" << std::endl;
    
    counting = 0;
    display();

    return 0;
}

int Timer::userContinue() {

    std::cout << "continued" << std::endl;

    counting = 1;

    while (counting) {
        activeCounting();
    }

    return 0;

}

int startTimer(Timer *timer_pointer) {

    (*timer_pointer).counting = 1;
    while ((*timer_pointer).counting) {
        (*timer_pointer).activeCounting();
    }

    return 0;
}

int testZeroTimer(Timer *timer_pointer) {

    (*timer_pointer).counting = 1;
    while ((*timer_pointer).counting) {
        (*timer_pointer).activeCounting();
        if ((*timer_pointer).second == 8) {
            (*timer_pointer).userPause();
            std::this_thread::sleep_for(std::chrono::seconds(3));
            (*timer_pointer).userContinue();
        }
        else if ((*timer_pointer).second == 10) {
            (*timer_pointer).stopTimer();
    }
    }

    return 0; }

CountUpTimer* initializeZeroTimer() {
    return new CountUpTimer();
}

CountDownTimer* initializeFocusTimer(int &focus_period) {
    return new CountDownTimer(focus_period);
}




