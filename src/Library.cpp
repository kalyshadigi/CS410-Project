#include "Library.h"
#include "Person.h"
#include "Patron.h"
#include "Librarian.h"

Library::Library(){
    Catalog* catalog = new Catalog();
    Clock* clock = new Clock();
}


bool Library::personExists(std::string email){
    return users.count(email);
};

void Library::createAccount(bool isLibrarian){
    std::string email;
    std::string password;
    std::string name;

    std::cout << "========= CREATE ACCOUNT =========" << std::endl;
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << std::endl;
    if (personExists(email)) {
        std::cout << "This user already exists." << std::endl;
        return;
    }
    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    std::cout << std::endl;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << std::endl;

    totalUsers += 1;
    if (isLibrarian) {
        users[email] = new Librarian(totalUsers, name, email, password);
    }else {
        users[email] = new Patron(totalUsers, name, email, password);
    }
    std::cout << "Account Creatation Successful!" << std::endl;
    users[email]->displayActions(catalog); //blocking func
};

void Library::signin(){
    std::string email;
    std::string password;

    std::cout << "============ SIGN IN =============" << std::endl;
    std::cout << "Enter email: ";
    std::getline(std::cin, email);
    std::cout << std::endl;
    if (!personExists(email)) {
        std::cout << "This email is not associated with an account." << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::getline(std::cin, password);
    std::cout << std::endl;
    if (!users[email]->signIn(email, password)){
        std::cout << "Incorrect password." << std::endl;
        return;
    }

    users[email]->displayActions(catalog); //blocking func
};

// will be revised once the Clock class docs are in
void Library::incrementClock(){
    int daysToAdd;
    
    std::cout << "======== INCREMENT CLOCK =========" << std::endl;
    // std::cout << "It is currently Day " << clock->getDay() << std::endl;
    // std::cout << "Enter number of days to add: ";
    // std::cin >> daysToAdd;
    // clock->increment(daysToAdd);
    // std::cout << "\n Success! It is now Day " << clock->getDay() << std::endl;
};