#ifndef CATALOG_H
#define CATALOG_H

#include "Item.h"
#include <unordered_map>
#include <string>

class Catalog {
private:
    std::unordered_map<int, Item*> items;
    int nextIndex = 1;

    /**
     * @returns a list of possible Items that match search term
     *          in the catalog; UP TO 3 RESULTS (for now)
     * @param input search term
     */
    std::vector<Item*> searchForItem(std::string input);

    bool isValidItemId(int id);

    /**
     * Displays the entire catalog, including IDs and titles
     */
    void displayEverything();

public:
    Catalog() = default;

    /**
     * Blocking function, allowing user to search catalog
     */
    void search();

    /**
     * Blocking function, allowing user to add item to catalog
     */
    void addItem();

    /**
     * Blocking function, allowing user to remove item to catalog
     */
    void removeItem();

    
};

#endif