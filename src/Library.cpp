#include "Library.h"

Library::Library(){
    Catalog* catalog = new Catalog();
    Clock* clock = new Clock();

    std::unordered_map<std::string, Person> users;
    // users["admin"] = Librarian("admin", "password");
}


bool Library::personExists(std::string user_id){
    return users.count(user_id);
};

Person Library::getPerson(std::string user_id){
    return users[user_id];
};

// will be majorly revised once the Person class docs are in
void Library::createPatron(){
    std::string user_id;
    std::string password;

    std::cout << "\n========= CREATE PATRON ==========" << std::endl;
    // std::cout << "Enter user_id: ";
    // std::getline(std::cin, user_id);
    // if (personExists(user_id)) {
    //     std::cout << "\nThis user already exists." << std::endl;
    //     return;
    // }
    // std::cout << "Enter ...password?: ";
    // std::getline(std::cin, password);
    // users[user_id] = Patron(user_id, password);

    // getPerson(user_id).dashboard(); //displayUserActions
};

// will be majorly revised once the Person class docs are in
void Library::createLibrarian(){
    std::string user_id;
    std::string password;

    std::cout << "\n======== CREATE LIBRARIAN ========" << std::endl;
    // std::cout << "Enter user_id: ";
    // std::getline(std::cin, user_id);
    // if (personExists(user_id)) {
    //     std::cout << "\nThis user already exists." << std::endl;
    //     return;
    // }
    // std::cout << "Enter ...password?: ";
    // std::getline(std::cin, password);
    // users[user_id] = Librarian(user_id, password);
    
    // std::cout << "\nAccount created!" << std::endl;
};

// will be majorly revised once the Person class docs are in
void Library::signin(){
    std::string user_id;
    std::string password;

    std::cout << "\n============ SIGN IN =============" << std::endl;
    // std::cout << "Enter user_id: ";
    // std::getline(std::cin, user_id);
    // if (!personExists(user_id)) {
    //     std::cout << "\nThis user does not exist." << std::endl;
    //     return;
    // }
    // std::cout << "\nEnter ...password?: ";
    // std::getline(std::cin, password);
    // if (!getPerson(user_id).checkPassword(password)){
    //     std::cout << "\nIncorrect password." << std::endl;
    //     return;
    // }
    // getPerson(user_id).dashboard(); //displayUserActions
};

// will be revised once the Clock class docs are in
void Library::incrementClock(){
    int daysToAdd;
    
    std::cout << "\n======== INCREMENT CLOCK =========" << std::endl;
    // std::cout << "It is currently Day " << clock->getDay() << std::endl;
    // std::cout << "Enter number of days to add: ";
    // std::cin >> daysToAdd;
    // clock->increment(daysToAdd);
    // std::cout << "\n Success! It is now Day " << clock->getDay() << std::endl;
};