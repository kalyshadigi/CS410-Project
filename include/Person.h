#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <unordered_map>
#include "Catalog.h"
#include <iostream>

class Person {
    private:
        int id;
        std::string userName;
        std::string email;
        std::string password;
        bool isSignedIn;
    public:
        Person(int personId, std::string personName, std::string personEmail, std::string personPassword);
        virtual ~Person() = default;
        int getId();
        std::string getUserName() const;
        std::string getEmail() const;
        std::string getPassword() const;

        bool signIn(std::string email, std::string password);
        void signOut();

        /**
         * Blocking function that displays the user options
         * for a patron or librarian
         * Patron and Librarian Classes have their own versions
         */
        virtual void displayActions(Catalog* cat);
};

#endif