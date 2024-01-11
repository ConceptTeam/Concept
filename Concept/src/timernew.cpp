#include "timernew.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

int Timer::storeTimer() {

    // not relevant for UI

    time_t end_time = get_time();

    // attributes to store in database:
    // start_timeis attribute of object
    // total_time attribute of object
    // end_time declared here

    // IMPLEMENT STORING TIMER INTO DATABASE with the 4 attributes above
    // Klaara will do this

    return 0;
}

int Timer::stopTimer() {

    // for octave 
    // connect to user clicking the stop button
    // the function automatically stops the timer and stores the timer into the database

    counting = 0;
    time_t time = get_time();
    total_time += difftime(time, last_start_time);
    storeTimer();

    return 0;

}

int Timer::display() {

    cout << "Time: " << minute << ":" << second << endl;
    // for octave
    // when called, the displayed time will be updated to the attributes second and minute of the timer object
    // should work for minutes with more than 2 digits
    
    return 0;
}

int Timer::activeCounting() {

    // not relevant for UI

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

    // Octave: connect to user clicking the pause button
    
    counting = 0;
    std::time_t time = get_time();
    total_time += difftime(time, last_start_time);
    display();

    return 0;
}

int Timer::userContinue() {

    // Octave: Connect to user clicking the continue button

    counting = 1;
    last_start_time = get_time();

    while (counting) {
        activeCounting();
    }

    return 0;

}

int startTimer(Timer *timer_pointer) {

    // not relevant for UI

    (*timer_pointer).last_start_time = (*timer_pointer).get_time();

    (*timer_pointer).counting = 1;
    while ((*timer_pointer).counting) {
        (*timer_pointer).activeCounting();
    }

    return 0;
}


CountUpTimer* initializeZeroTimer() {
    // not relevant for UI
    return new CountUpTimer();
}

CountDownTimer* initializeFocusTimer(int &focus_minutes, int &focus_hours) {
    // not relevant for UI
    return new CountDownTimer(focus_minutes, focus_hours);
}

int userStartsZeroTimer() {

     //octave: connect to user clicking the start button when there is no focus period set

    CountUpTimer* timer = initializeZeroTimer();
    startTimer(timer);

    return 0;
}

int userStartsFocusTimer(int &focus_minutes, int &focus_hours) {

    // octave: connect to user clicking the start button when there is a focus period set (hours and minutes)
    // the focus period chosen by the user is passed as an argument to this function
    // i dont know how that works

    CountDownTimer* timer = initializeFocusTimer(focus_minutes, focus_hours);
    startTimer(timer);

    return 0;
}

int testFocusTimer() {

    // not relevant for UI

    int focus_period = 25;
    CountDownTimer* timer = initializeFocusTimer(focus_period, focus_period);
    startTimer(timer);

    return 0;
}


