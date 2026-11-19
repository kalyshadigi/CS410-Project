#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <deque>

class Patron;

class Item {
protected:
    std::string title;
    std::deque<Patron*> holdQueue;

public:
    Item() = default;
    virtual ~Item() = default;

    void addHold(Patron* p);
    Patron* nextHold();
    bool hasHolds() const;

    virtual void create_item() = 0;
    virtual std::string display_item() const = 0;
    virtual std::string display_short_name() const;

    /**
     * returns true if this item matches the search input 
     * @param term search word, must be substr of title exactly (for now)
     */
    bool matchesSearch(std::string term);
};

#endif