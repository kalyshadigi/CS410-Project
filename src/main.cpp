#include <iostream>
#include <string>
#include <Library.h>

using namespace std;

enum State {
    MENU, EXIT
};

int main() {
    State state = MENU;
    string choice;
    Library* library = new Library();
    
    while(state != EXIT){
        // cout << "=================================" << endl;
        cout << endl;
        cout << "Welcome to the library main page!" << endl;
        cout << "============== MENU ==============" << endl;
        cout << "1) Sign In" << endl;
        cout << "2) Create Patron Account" << endl;
        cout << "3) Create Librarian Account" << endl;
        cout << "4) Increment Day" << endl;
        cout << "5) EXIT" << endl;
        cout << "==================================" << endl;
        cout << "Enter an integer: ";
        getline(cin, choice);
        cout << endl;

        if (choice == "1"){
            library->signin();
        } else if (choice == "2"){
            library->createAccount(false);
        } else if (choice == "3"){
            library->createAccount(true);
        }else if (choice == "4"){
            library->incrementClock();
        } else if (choice == "5"){
            state = EXIT;
        } 
        
        
    
    }

    return 0;
}