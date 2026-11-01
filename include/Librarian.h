#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include "Library.h"

class Librarian : public Person {
public:
    Librarian(int personId, std::string personName, std::string personEmail, std::string personPassword);
    
    void checkoutBook();
    void returnBook();

    void addBook();
    void removeBook();

    void addToHoldList();
    void removeFromHoldList();

    /**
     * Blocking function that displays the user options
     * for a librarian
     */
    void displayActions(Catalog *cat) override;
};

#endif