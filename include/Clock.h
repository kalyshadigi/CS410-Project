//Kalysha


#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <chrono>

#include "Patron.h"
#include "Catalog.h"

class Clock {
private:

    Patron* customer;
    Catalog* customerItem;
    std::chrono::system_clock::time_point checkedoutTime;

public:
    Clock();

    // Member functions
    void customerCheckingOut(Patron* currentPatron, Catalog* item);
    void clockStatus();
};

#endif