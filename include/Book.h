#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

class Book : public Item {
private:
    std::string author;
    int pages = 0; // should this be included?  same with everything commented out below
    /*
    std::string genre;
    
    
    */

public:
    void create_item() override;
    std::string display_item() const override;

};

#endif