#include "Person.h"
#include <string>
#include <stdexcept>

Person::Person(int personId, std::string personName, std::string personEmail, std::string personPassword) {
        if (personId <= 0) {
            throw std::invalid_argument("Person ID must be positive");
        }
        if (personName.empty() || personEmail.empty() || personPassword.empty()) {
            throw std::invalid_argument("Empty person name, email, or password");
        }
    id = personId;
    userName = personName;
    email = personEmail;
    password = personPassword;
    isSignedIn = false;
}

int Person::getId() {
    return id;
}

std::string Person::getUserName() const {
    return userName;
}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getPassword() const {
    return password;
}

bool Person::signIn(std::string email, std::string password){
    if (this->email == email && this->password == password) {
        isSignedIn = true;
        return true;
    }
    return false;
}
        
void Person::signOut() {
    isSignedIn = false;
}

