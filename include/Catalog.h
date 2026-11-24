#ifndef CATALOG_H
#define CATALOG_H

#include "Item.h"
#include <string>
#include <vector>

class Catalog {
private:
    std::vector<Item*> listOfItems;
public:
    Catalog();

    void addItem(Item* newItem);
    bool removeItem(std::string itemTitle);
    Item* findItem(std::string itemTitle);
    void displayCatalog() const;
};

#endif