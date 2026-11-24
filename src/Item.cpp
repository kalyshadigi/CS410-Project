#include "Item.h"
#include "Patron.h"

void Item::addHold(Patron* p) {holdQueue.push_back(p); }

Patron* Item::nextHold() {
    if(holdQueue.empty()) return nullptr;
    Patron* p = holdQueue.front();
    holdQueue.pop_front();
    return p;
}

bool Item::hasHolds() const { return !holdQueue.empty(); }

std::string Item::display_short_name() const{
    return title.substr(0,15);
}

bool Item::isNextHold(Patron* p){
    if(holdQueue.empty()) return false;
    if(p->getEmail() == holdQueue.front()->getEmail()){
        return true;
    }
    return false;
}

bool Item::matchesSearch(std::string term){
    return title.find(term) != std::string::npos;
}