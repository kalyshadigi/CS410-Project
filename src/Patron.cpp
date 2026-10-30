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