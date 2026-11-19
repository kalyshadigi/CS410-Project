#ifndef PATRON_H
#define PATRON_H
#include <vector>
#include <string>
#include <unordered_map>

#include "Person.h"

class Patron : public Person {
private:
    double accountDebt;
    std::unordered_map<int, Item*> borrowedBooks; // Id, Title

public:
    Patron(int personId, std::string personName, std::string personEmail, std::string personPassword);
    double getAccountDebt();
    double payAccountDebt(double amount);
    std::vector<std::string> getBorrowedBooks() const;
    void borrowBook(int id, Item* book);
    void returnBook(int id, Item *book);

    /**
     * Blocking function that displays the user options
     * for a patron
     */
    void displayActions(Library* lib) override;
};

#endif