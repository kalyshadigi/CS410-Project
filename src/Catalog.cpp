#include "Catalog.h"
#include <iostream>

#include "Book.h"
#include "Audiobook.h"
#include "Game.h"

/**
 * things to update: 
 * - std::unordered_map<int, std::unique_ptr<Item>> items instead
 * - search only returns 3 items - refactor to allow for more/less/scroll
 * - find better way to remove item
 * - figure out how to handle multiple copies
 */

std::vector<Item *> Catalog::searchForItem(std::string input) {
    std::vector<Item*> output;
    for (auto& pair : items){
        if (output.size() < 3 && pair.second->matchesSearch(input)) {
            output.push_back(pair.second);
        }
    }
    return output;
}

bool Catalog::isValidItemId(int id) {
    return items.count(id);
}

void Catalog::search() {
    std::string input;
    std::vector<Item *> outputs;
    std::string name;

    std::cout << "========= SEARCH CATALOG =========" << std::endl;
    std::cout << "Enter search keyword: ";
    std::getline(std::cin, input);
    std::cout << std::endl;
    
    outputs = searchForItem(input);
    if (outputs.empty()){
        std::cout << "No matching item could be found." << std::endl;
        return;
    }
    for(int i = 0; i < outputs.size(); i++){
        std::cout << (i+1) << ". " << outputs[i]->display_short_name() << std::endl;
    }

    std::cout << "Enter an integer if you would like more information on an item: ";
    std::getline(std::cin, input);
    std::cout << std::endl;

    //given that searchForItem only returns top 3 (temp)
    if (input == "1" || input == "2" || input == "3"){ 
        if (stoi(input) <= outputs.size())
            std::cout << outputs[stoi(input)-1]->display_item() << std::endl;
    }

    // else just exits
}

void Catalog::addItem() {
    std::string response;
    std::cout << "============ ADD ITEM ============" << std::endl;
    std::cout << "1) Add Book" << std::endl;
    std::cout << "2) Add Audiobook" << std::endl;
    std::cout << "3) Add Game" << std::endl;
    std::cout << "4) EXIT" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Enter an integer: ";
    getline(std::cin, response);
    std::cout << std::endl;

    if (response != "1" && response != "2" && response != "3"){
        std::cout << "Exiting" << std::endl;
        return;
    }

    Item* item;

    if (response == "1"){
        item = new Book();
    } else if (response == "2"){
        item = new Audiobook();
    } else {
        item = new Game();
    }

    item->create_item();
    items[nextIndex] = item;
    nextIndex++;

    std::cout << "Success! Added " << item->display_short_name() << std::endl;
}

void Catalog::removeItem() {
    int itemId;
    std::cout << "========== REMOVE ITEM ===========" << std::endl;
    displayEverything();
    
    std::cout << "Enter item id: ";
    std::cin >> itemId;
    std::cout << std::endl;

    auto it = items.find(itemId);
    
    if (it == items.end()){
        std::cout << itemId << " does not exist; exiting." << std::endl;
        return;
    }

    delete it->second;
    items.erase(it);

    std::cout << "Success! Removed Item #" << itemId << std::endl;
    
}

void Catalog::displayEverything() {
    std::cout << "========= CATALOG START ==========" << std::endl;

    for (auto& pair : items){
        std::cout << pair.first << ". " << pair.second->display_short_name() << std::endl;
    }

    std::cout << "========== CATALOG END ===========" << std::endl;
}