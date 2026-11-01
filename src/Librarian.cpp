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

void Librarian::displayActions(Catalog* cat) {
    bool inLoop = true;
    std::string response;
    while (inLoop) {
        std::cout << getUserName() << "'s Dashboard" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "============== MENU ==============" << std::endl;
        std::cout << "1) Search Catalog" << std::endl;
        std::cout << "2) Checkout Item for Patron" << std::endl;
        std::cout << "3) Add to Catalog" << std::endl;
        std::cout << "4) Remove from Catalog" << std::endl;
        std::cout << "5) SIGN OUT" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "Enter an integer: ";
        getline(std::cin, response);
        std::cout << std::endl;

        if (response == "1"){ //search catalog
            std::cout << "**TODO: search catalog**" << std::endl;
            // cat->searchItems(); //blocking func in catalog class
            // or possibly ask for search keyword and pass into catalog.searchItem()
            // adjust based on catalog docs ofc

        } else if (response == "2"){ //checkout item
            std::cout << "**TODO: checkout item**" << std::endl;
            // TODO ask for patron id, item id, and handle checkout
            
        } else if (response == "3"){ //add to catalog
            std::cout << "**TODO: add to catalog**" << std::endl;
            // TODO ask for info and pass into catalog.addItem()
        
        }else if (response == "4"){ //remove from catalog
            std::cout << "**TODO: remove from catalog**" << std::endl;
            // TODO ask for info and pass into catalog.removeItem()

        }else if (response == "5"){ //sign out
            inLoop = false;
        }
    }
}