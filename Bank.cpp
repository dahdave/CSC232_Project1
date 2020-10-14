#include <string>
#include <iostream>
#include <time.h>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <vector>

using namespace std;

void openAccount();
void login(string accountNumber);

int main() {
    for(;;) {
        cout << "-------------------" << endl;
        cout << "What would you like to do? \n" << endl;
        cout << "[1] Open an Account" << endl;
        cout << "[2] Login to An Existing Account" << endl;
        cout << "[3] Exit the banking program" << endl;
        cout << "-------------------" << endl;
        int userInput;
        cin >> userInput; 
        switch(userInput) {
            case 1: { // create accounts
                openAccount();
                continue;
            }
            case 2: { // login
                string accountNumber;
                cout << "\n";
                do {
                cout << "Enter an 8 digit account number: ";
                cin >> accountNumber;
                }while(accountNumber.length() != 8); // make sure the length is 8. 
                }
                continue;
            case 3: {
                cout << "Goodbye!" << endl;
                // add destruction of pointers, mem allocation here, etc.
                exit(1);
            }
            default: {
                cout << "Try another input!" << endl;
                cin.ignore();
                cin.clear();
                continue;
            }
            break;
        }

    }
}

void openAccount() {
    srand((unsigned) time(0));
    double deposit;
    double interest = 1;
    string accNumber;
    int random;
    cout << "Creating your checkings and savings...." << endl;
    for(int i = 0; i < 7; i++) {
        random = 1 + (rand() % 9);
        accNumber += to_string(random);
    }
    cout << "Your Checking Account number is: #C" << accNumber << endl;

    cout << "Your Savings Account number is: #S" << accNumber << endl;
    
    cout << "How much would you like to deposit into your checking account " << endl;
    
    cin >> deposit;
    
    

    CheckingAccount acc = CheckingAccount(accNumber, deposit, interest);
    
}

void login(string accountNumber) {
    
    vector<CheckingAccount> checkingAccounts;
    vector<CheckingAccount> savingsAccounts;
    string userLogin;
    string character;
    string accNum;
    int userInput;
    
    // write from file to vectors here
    
    cout << "Enter your account number to login: ";
    cin >> userLogin;
    character = userLogin.substr(0);
 
    if ( character == "C")
    {
        for(int i; i < checkingAccounts.size(); i++)
        {
            accNum =checkingAccounts[i].accNum;
            if(accNum == userLogin)
            {
                
                do{ 
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Withdraw" << endl;
                    cout << "[2] Deposit" << endl;
                    cout << "[3] Exit the account" << endl;
                    cin >> userInput;
                    switch(userInput){
                        double amount;
                        case 1: { //withdraw
                                cout << "How much would you like to withdraw?\n";
                                cin >> amount;
                                checkingAccounts[i].withdraw(amount);
                        }
                        case 2: { // deposit
                                cout << "How much would you like to deposit?\n";
                                cin >> amount;
                                checkingAccounts[i].deposit(amount);
                        }
                        case 3:{
                            cout << "Exiting...\n";
                        }
                        default: {
                            cout << "Try another input!" << endl;
                        }
                    }
                            
                            
                }while(userInput != 3);
            }
    }
}
    else if(character == "S")
    {
        
        for(int i; i < savingsAccounts.size(); i++)
        {
            accNum =savingsAccounts[i].accNum;
            if(accNum == userLogin)
            {
                
                do{ 
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Withdraw" << endl;
                    cout << "[2] Deposit" << endl;
                    cout << "[3] Exit the account" << endl;
                    cin >> userInput;
                    switch(userInput){
                        double amount;
                        case 1: { //withdraw
                                cout << "How much would you like to withdraw?\n";
                                cin >> amount;
                                savingsAccounts[i].withdraw(amount);
                        }
                        case 2: { // deposit
                                cout << "How much would you like to deposit?\n";
                                cin >> amount;
                                savingsAccounts[i].deposit(amount);
                        }
                        case 3:{
                            cout << "Exiting...\n";
                        }
                        default: {
                            cout << "Try another input!" << endl;
                        }
                    }
                            
                            
                }while(userInput != 3);
             }
          }
       }    
}
