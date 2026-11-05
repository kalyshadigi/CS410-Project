//Kalyshas  
// this is not finished yet


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
    void customerCheckingOut(Patron* currentPatron,Catalog* item){
        customer = currentPatron;
        customerItem = item;
        checkedoutTime = std::chrono::system_clock::now();
    }
    // these can be changed if they go to fast
    void clockStatus(){
        // these get the current time and then give me the current seconds cause a
        //simulated day will only be 10 seconds this could be adjusted later
        auto now = std::chrono::system_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - checkedoutTime).count();
        long days = elapsedSeconds/10;

        bool overdue = false;
        //taken out day is just a place holder for now since the catalog area hasnt been 
        //finished yet
        if(days > customerItem->takenOutDays){
            overdue = true;
        }
        // think I might a item type and title for those cases of games and other items 
        std::cout << "\r Customer: " << customer->personName() << " " << customer->personId() <<endl;
                  << " Item: " << customerItem->getTitle() << endl;
                  << " Days Left to Return: " << simulatedDays << endl;
    }
};

#endif
