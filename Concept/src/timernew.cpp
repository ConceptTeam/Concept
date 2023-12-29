#include "timernew.h"
#include <iostream>



void storeTimer(Timer *my_timer) {
    std::cout << "storing timer" << std::endl;
}

void display(Timer *timer) {
    std::cout << (timer)->minute << " mins, " << timer->second << " secs. " << std::endl;
}

void activeCounting(Timer&timer) {
    if (timer.finished) {
        storeTimer(timer);
    }
    else {
        std::this_thread::sleep_for(Second(1));
        timer.update_time();
        display(timer);
    }

}
void startZeroTimer() {
    CountUpTimer current_timer = CountUpTimer();
    CountUpTimer* timer_pointer = &current_timer;
    current_timer.counting = true;

    while (current_timer.counting) {
        activeCounting(*timer_pointer);
    }

}

void startFocusTimer(int &focus_period) {
    CountDownTimer current_timer = CountDownTimer(focus_period);
    CountDownTimer* timer = &current_timer;
    *timer->counting = true;

    while (current_timer.counting && !current_timer.finished) {
        activeCounting(*timer);
    };

    if (current_timer->finished) {
        storeTimer(*timer);
    }
}

void userPause(Timer *timer) {
    *timer->counting = false;
}

void userContinue(Timer *timer) {
    *timer-> counting = true;
    while (*timer->counting) {
        activeCounting(*timer);
    }

}

void stopTimer(Timer *timer) {
    *timer->finished = true;
}




