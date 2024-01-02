#include <iostream>
#include <chrono>
#include "timernew.cpp"

int testStartZeroTimer() {
    std::cout << "started zero timer" << std::endl;
    CountUpTimer current_timer = CountUpTimer();
    CountUpTimer* timer_pointer = &current_timer;
    current_timer.counting = true;

    while (current_timer.counting) {
        (*timer_pointer).activeCounting();
        if (current_timer.second == 8) {
            current_timer.stopTimer();
        }
    }

    return 0;
}

int main() {
    testStartZeroTimer();
}