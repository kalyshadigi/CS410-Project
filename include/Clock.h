//Kalysha


#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>

#include "Patron.h"
#include "Catalog.h"

class Clock {
private:
    int counter;
    Patron* customer;
    Catalog* customerItem;
    std::chrono::system_clock::time_point checkedoutTime;

public:
    Clock();
    
    int getDay();
    void increment(int num);
    bool isDay(int num);
    bool isPast(int num);

    // Member functions
    void customerCheckingOut(Patron* currentPatron, Catalog* item);
    void clockStatus();
};

#endif