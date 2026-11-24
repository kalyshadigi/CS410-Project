#include "Patron.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "Library.h"


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
        books.push_back(std::to_string(pair.first) + ". " + pair.second->display_short_name());
    }
    return books;
}

void Patron::borrowBook(int id, Item* book) {
    borrowedBooks[id] = book; // Placeholder title
}

void Patron::returnBook(int id, Item* book) {
    // if (getAccountDebt() > 0) {
    //     throw std::runtime_error("Please pay your account debt before returning books.");
    // }
    borrowedBooks.erase(id);
    if(book->isNextHold(this)){
        book->nextHold();
    }
}

void Patron::displayActions(Library* lib) {
    bool inLoop = true;
    std::string response;
    while (inLoop) {
        std::cout << std::endl << getUserName() << "'s Dashboard" << std::endl;
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
        getline(std::cin >> std::ws, response);
        std::cout << std::endl;

        if (response == "1"){ //pay fees
            std::cout << "============ PAY FEES ============" << std::endl;
            if (!accountDebt) {
                std::cout << "This account does not have any fees." << std::endl;
                continue;
            } 
            double amount;
            std::cout << "Enter amount to pay: $";
            std::cin >> amount;
            payAccountDebt(amount);
            amount = (accountDebt-amount > 0 ? 0 : amount-accountDebt);
            std::cout << "Transaction Complete! Amount returned: $" << amount << std::endl;

        } else if (response == "2"){ //view borrowed items
            std::cout << "======== BORRORWED ITEMS =========" << std::endl;
            for (auto& book : getBorrowedBooks()){
                std::cout << book << std::endl;
            }
            
        } else if (response == "3"){ //return an item
            std::cout << "=========== ITEM RETURN ==========" << std::endl;
            std::cout << "Enter Item ID to return: ";
            getline(std::cin, response);
            std::cout << std::endl;

            if (!lib->catalog->isValidItemId(stoi(response))){
                std::cout << "Invalid Item ID" << std::endl;
                continue;
            }
            returnBook(stoi(response), lib->catalog->getItem(stoi(response)));
        
        }else if (response == "4"){ //search items
            lib->catalog->search();

        }else if (response == "5"){ //sign out
            inLoop = false;
        }
    }
}