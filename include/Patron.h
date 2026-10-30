#ifndef PATRON_H
#define PATRON_H
#include <vector>
#include <string>
#include <unordered_map>

#include "Person.h"

class Patron : public Person {
private:
    double accountDebt;
    std::unordered_map<int, std::string> borrowedBooks; // Id, Title

public:
    Patron(int personId, std::string personName, std::string personEmail, std::string personPassword);
    double getAccountDebt();
    double payAccountDebt(double amount);
    std::vector<std::string> getBorrowedBooks() const;
    void borrowBook(const int bookId);
    void returnBook(const int bookId);

};

#endif