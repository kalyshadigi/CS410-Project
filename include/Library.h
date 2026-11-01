#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <unordered_map>
#include <string>

#include <Person.h>
#include <Catalog.h>
#include <Clock.h>

class Library {
private:
    /**
     * Initializes with one default account:
     * Librarian w credentials ("admin", "password")
     */
    std::unordered_map<std::string, Person*> users;
    int totalUsers = 0;
public:
    Catalog* catalog;
    Clock* clock;
    
    Library();
    // Library(std::string csvToLoad);

    bool personExists(std::string email);
    bool personExists(int user_id);

    /**
     * Blocking function that allows user to create and
     * sign in to a new account
     */
    void createAccount(bool isLibrarian);

    /**
    * Blocking function that allows user to sign into
    * their account
    */
    void signin();

    /**
    * Blocking function that allows user to insert
    * however many days they want to increment the 
    * clock by
    */
    void incrementClock();
};

#endif