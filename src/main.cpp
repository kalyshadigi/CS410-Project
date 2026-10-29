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
        cout << "\nWelcome to the library main page!" << endl;
        cout << "===============MENU===============" << endl;
        cout << "1) Create Account" << endl;
        cout << "2) Sign In" << endl;
        cout << "3) Increment Day" << endl;
        cout << "4) EXIT" << endl;
        cout << "==================================" << endl;
        cout << "Enter an integer: ";
        getline(cin, choice);

        if (choice == "1"){
            library->createPatron();
        } else if (choice == "2"){
            library->signin();
        } else if (choice == "3"){
            library->incrementClock();
        } else if (choice == "4"){
            state = EXIT;
        } 
        
        
    
    }

    return 0;
}