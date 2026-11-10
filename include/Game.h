#ifndef GAME_H
#define GAME_H

#include "Item.h"

class Game : public Item {
private:
    std::string rating;

public:
    void create_item() override;
    std::string display_item() const override;

};

#endif