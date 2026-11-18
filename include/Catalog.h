#ifndef CATALOG_H
#define CATALOG_H

#include "Item.h"
#include <unordered_map>
#include <string>

class Catalog {
private:
    std::unordered_map<int, Item*> items;
    int totalItems = 0;
public:
    Catalog();

    /**
     * Blocking function, allowing user to search catalog
     */
    void searchItem();

    /**
     * Blocking function, allowing user to add item to catalog
     */
    void addItem();

    bool isValidItemId(int id);
    void removeItem(Item* item);
};

#endif