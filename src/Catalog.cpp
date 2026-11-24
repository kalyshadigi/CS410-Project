#include "Catalog.h"
#include <iostream>
include <string>

Catalog::Catolog(){}

void Catalog::addItem(Item* newItem){
    if(newItem == NULL){
        std::cout << "new Item is empty" << std::endl;
        return;
    }
    
    listOfItems.push_back(newItem);
}

Item* Catalog::findItem(std::string itemTitle){
    for(int i = 0; i < listOfItems; i++){
        Item* itemPtr = listOfItems[i];
        if(itemPtr != NULL && itemPtr->getTitle() == itemTitle){
            return itemPtr;
        }
    }
    return NULL;
}

bool Catalog::removeItem(std::string itemTitle){
    for(int i = 0; i < listOfItems.size(); i++){
        Item* itemPtr = listofItem[i];
        if(itemPtr != NULL && itemPtr->getTitle() == itemTitle){
            //remove the item 
            listOfItems.erase(listOfItems.begin() + i);
            return true;
        }
    }
    return false;
}

void Catalog::displayCatalog() const{
    if(listOfItems.empty()){
        std::cout << "Catalog is empty" << std::endl;
        return;
    }
    for(int i = 0; i < listOfItems.size(); i++){
        Item* itemPtr = listOfItems[i];
        if(itemPtr != NULL){
            itemPtr->display();
        }
    }
}
