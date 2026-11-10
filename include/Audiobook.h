#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Item.h"

class Audiobook : public Item {
private:
    std::string author;
    std::string narrator;
    int duration = 0;


public:
    void create_item() override;
    std::string display_item() const override;
};

#endif