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
    std::unordered_map<std::string, Person> users;
public:
    Catalog* catalog;
    Clock* clock;
    
    Library();
    // Library(std::string csvToLoad);

    Catalog getCatalog();
    bool personExists(std::string user_id);
    Person getPerson(std::string user_id);

    /**
     * Blocking function that allows user to create and
     * sign in to a new patron account
     */
    void createPatron();

    /**
     * Blocking function that allows user to create and
     * sign in to a new librarian account
     * Should only be called from librarian actions?
     * like only available for librarian to make a new
     * librarian an account
     */
    void createLibrarian();

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