#include <iostream>
#include <chrono>
#include "timernew.cpp"

int testCountUpTimer() {
    CountUpTimer* timer = new CountUpTimer();
    testZeroTimer(timer);
    return 0;
}

int main() {
    testCountUpTimer();
    return 0;}