#include <string>
#include <iostream>
#include <bankAccount.h>
using namespace std;


int main() {
    cout << "-------------------" << endl;
    cout << "\n" << endl;
    cout << "What would you like to do? \n" << endl;
    cout << "[1] Open an Account" << endl;
    cout << "[2] Login to An Existing Account" << endl;
    cout << "[3] Exit the banking program" << endl;
    cout << "\n" << endl;
    cout << "-------------------" << endl;
    int userInput;
    cin >> userInput; 
    
    switch(userInput) {
        case 1: {
            
        }
        case 2: {
            
        }
        case 3: {
            cout << "Goodbye!" << endl;
            // add destruction of pointers, mem allocation here, etc.
            exit(1);
        }
        default: {
            cout << "Try another input!" << endl;
            cin.ignore();
            cin.clear();
            main();
        }
    }
    main();
}