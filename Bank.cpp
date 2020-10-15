#include <string>
#include <iostream>
#include <time.h>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <vector>
#include <ctime>

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
                exit(0);
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
    CheckingAccount cAccount;
    SavingsAccount sAccount;
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
            cAccount =checkingAccounts.at(i);
            accNum = cAccount.accNum;
            if(accNum == userLogin)
            {
                
                do{ 
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Withdraw" << endl;
                    cout << "[2] Deposit" << endl;
                    cout << "[3] Check Balance" << endl;
                    cout << "[4] Close Account" << endl;
                    cout << "[5] Exit the account" << endl;
                    cin >> userInput;
                    switch(userInput){
                        double amount;
                        case 1: { //withdraw
                                cout << "How much would you like to withdraw?\n";
                                cin >> amount;
                                cAccount.withdraw(amount);
                        }
                        case 2: { // deposit
                                cout << "How much would you like to deposit?\n";
                                cin >> amount;
                                cAccount.deposit(amount);
                        }
                        case 3: { //check balance
                                cout << "Here is your current balance.\n";
                                cout << cAccount.accBalance;
                        }
                        case 4: { // delete
                                cout << "Deleting account...";
                        }
                        case 5:{
                            cout << "Exiting...\n";
                        }
                        default: {
                            cout << "Try another input!" << endl;
                        }
                    }
                            
                            
                }while(userInput != 5);
            }
    }
}
    else if(character == "S")
    {
        
        for(int i; i < savingsAccounts.size(); i++)
        {
            sAccount = savingsAccounts.at(i);
            accNum = sAccount.accNum;
            if(accNum == userLogin)
            {
                
                do{ 
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Withdraw" << endl;
                    cout << "[2] Deposit" << endl;
                    cout << "[3] Check Balance" << endl;
                    cout << "[4] Close Account" << endl;
                    cout << "[5] Exit the account" << endl;
                    cin >> userInput;
                    switch(userInput){
                        double amount;
                        case 1: { //withdraw
                                cout << "How much would you like to withdraw?\n";
                                cin >> amount;
                                sAccount.withdraw(amount);
                        }
                        case 2: { // deposit
                                cout << "How much would you like to deposit?\n";
                                cin >> amount;
                                sAccount.deposit(amount);
                        }
                        case 3: { //check balance
                                cout << "Here is your current balance.\n";
                                sAccount.accBalance;
                        }
                        case 4: { // delete
                                cout << "Deleting account...";
                                
                        case 5:{
                            cout << "Exiting...\n";
                        }
                        default: {
                            cout << "Try another input!" << endl;
                        }
                    }
                            
                            
                }while(userInput != 5);
             }
          }
       }    
}
 
int getTotalCheckingAccounts() {
    int totalAccounts = 0;
    string text;
    ifstream inFile("checkingAcc.txt");

    if (!inFile)
    {
        cout << "student file not found" << endl;
        return -1;
    }

    while (getline(inFile, text))
        totalAccounts++;


    inFile.close();

    return totalAccounts/2;
}

int getTotalSavingAccounts() {
    int totalAccounts = 0;
    string text;
    ifstream inFile("savingAcc.txt");

    if (!inFile)
    {
        cout << "student file not found" << endl;
        return -1;
    }

    while (getline(inFile, text))
        totalAccounts++;


    inFile.close();

    return totalAccounts/2;

}
    
 void loadFile() {
    int totalCheckings = getTotalCheckingAccounts();
    int totalSavings = getTotalSavingAccounts();
    
    SavingsAccount sAccounts[totalSavings];
    CheckingAccount cAccounts[totalCheckings];

    ifstream inFile;
    string text;
    // FILL checking ACCOUNTS WITH INFO
    inFile.open("savingAcc.txt");
    if(!inFile) {
        cout << "Error reading file..." << endl;
        return;
    }

    if (inFile)
    {
        long double balance;
        string accNum;
        double interestRate = 1.0; // CHANGE THIS IN THE FUTURE
        while (getline(inFile, text))
        {
            int count = 0;
            if (text.find("C") == 0)
            {
                accNum = text;
                
            }
            getline(inFile,text);
             try{
                 balance = stod(text);
             }catch(...) {
                 break;
                 
             }
            count++;
        sAccounts[count].accNum = accNum;
        sAccounts[count].accBalance = balance;
        sAccounts[count].annualIR = interestRate;
    }

    // FILL checking ACCOUNTS WITH INFO
    ifstream nFile;
    string text;
    nFile.open("checkingAcc.txt");
    if(!nFile) {
        cout << "hello" << endl;
        cout << "Error reading file..." << endl;
        return;
    }

    if (nFile)
    {
        long double balance;
        string accNum;

        while (getline(inFile, text))
        {
            int count = 0;
            if (text.find("C") == 0)
            {
                accNum = text;
                
            }
            getline(inFile,text);
             try{
                 balance = stod(text);
             }catch(...) {
                 break;
                 
             }
            count++;
        cAccounts[count].accNum = accNum;
        cAccounts[count].accBalance = balance;
      }
    }

    }
}

}
