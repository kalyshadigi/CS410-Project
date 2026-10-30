#include "Librarian.h"

Librarian::Librarian(int personId, std::string personName, std::string personEmail, std::string personPassword)
    : Person(personId, personName, personEmail, personPassword) {}

    // Logic for checking out and adding/removing books, and managing the hold list will be implemented once book, catalog, item are defined.
void Librarian::checkoutBook() {
    // Implement logic for checking out a book
}

void Librarian::returnBook() {
    // Implement logic for returning a book
}

void Librarian::addBook() {
    // Implement logic for adding a book
}

void Librarian::removeBook() {
    // Implement logic for removing a book
}

void Librarian::addToHoldList() {
    // Implement logic for adding a book to the hold list
}

void Librarian::removeFromHoldList() {
    // Implement logic for removing a book from the hold list
}