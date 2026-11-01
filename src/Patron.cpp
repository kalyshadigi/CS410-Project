#include "Patron.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

Patron::Patron(int personId, std::string personName, std::string personEmail, std::string personPassword)
    : Person(personId, personName, personEmail, personPassword), accountDebt(0.0) {}

double Patron::getAccountDebt() {
    // Enter logic for calculating account debt, based off clock and borrowed books.
    return accountDebt;
}
double Patron::payAccountDebt(double amount) {
    if (amount > accountDebt) {
        amount = accountDebt;
    }
    accountDebt -= amount;
    return amount;
}

std::vector<std::string> Patron::getBorrowedBooks() const {
    std::vector<std::string> books;
    for (const auto& pair : borrowedBooks) {
        books.push_back(pair.second);
    }
    return books;
}

void Patron::borrowBook(const int bookId) {
    borrowedBooks[bookId] = "Book " + std::to_string(bookId); // Placeholder title
}

void Patron::returnBook(const int bookId) {
    if (getAccountDebt() > 0) {
        throw std::runtime_error("Please pay your account debt before returning books.");
    }
    borrowedBooks.erase(bookId);
}

void Patron::displayActions(Catalog* cat) {
    bool inLoop = true;
    std::string response;
    while (inLoop) {
        std::cout << getUserName() << "'s Dashboard" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "Email: " << getEmail() << std::endl;
        std::cout << "Fees: " << getAccountDebt() << std::endl;
        std::cout << "============== MENU ==============" << std::endl;
        std::cout << "1) Pay Fees" << std::endl;
        std::cout << "2) View Borrowed Items" << std::endl;
        std::cout << "3) Return Item" << std::endl;
        std::cout << "4) Search Catalog" << std::endl;
        std::cout << "5) SIGN OUT" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "Enter an integer: ";
        getline(std::cin, response);
        std::cout << std::endl;

        if (response == "1"){ //pay fees
            if (!accountDebt) {
                std::cout << "This account does not have any fees." << std::endl;
            } else {
                std::cout << "**TODO: pay account fees**" << std::endl;
                // TODO pay account fees
            }

        } else if (response == "2"){ //view borrowed items
            std::cout << "**TODO: view borrowed items**" << std::endl;
            // TODO display borrowed items
            
        } else if (response == "3"){ //return an item
            std::cout << "=========== ITEM RETURN ==========" << std::endl;
            std::cout << "Enter ITEM ID to return: ";
            getline(std::cin, response);
            std::cout << std::endl;
            std::cout << "**TODO: return an item**" << std::endl;
            // TODO ask for item id and handle return
        
        }else if (response == "4"){ //search items
            std::cout << "**TODO: search catalog**" << std::endl;
            // cat->searchItems(); //blocking func in catalog class
            // or possibly ask for search keyword and pass into catalog.searchItem()
            // adjust based on catalog docs ofc

        }else if (response == "5"){ //sign out
            inLoop = false;
        }
    }
}