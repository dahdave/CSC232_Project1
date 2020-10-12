#include <string>
#include <iostream>
#include <bankAccount.h>
using namespace std;

void openAccount();
void login(string accountNumber);

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
        case 1: { // create accounts
            
        }
        case 2: { // login
            string accountNumber;
            cout << "\n";
            do {
            cout << "Enter an 8 digit account number: ";
            cin >> accountNumber;
            }while(accountNumber.length() != 8); // make sure the length is 8. 

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

void login(string accountNumber) {
    
}