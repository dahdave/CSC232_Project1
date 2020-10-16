#include <string>
#include <iostream>
#include <time.h>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
#include <vector>



using namespace std;

// Functions
void openAccount();

void login(CheckingAccount *cAccounts, SavingsAccount *sAccounts);
void loadFile(CheckingAccount *cAccounts, SavingsAccount *sAccounts);
void reloadFile(CheckingAccount *cAccounts, SavingsAccount *sAccounts);

int getTotalCheckingAccounts();
int getTotalSavingAccounts();


int main() {
    for(;;) { // loop for the main menu 
        int totalCheckings = getTotalCheckingAccounts();           // Reload the array with the new account information 
        int totalSavings = getTotalSavingAccounts();               // everytime the main menu restarts
        SavingsAccount sAccounts[totalSavings];                    
        CheckingAccount cAccounts[totalCheckings];
        loadFile(cAccounts, sAccounts);

        cout << "-------------------" << endl;
        cout << "What would you like to do? \n" << endl;         // main menu
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
                login(cAccounts, sAccounts);
                }
                reloadFile(cAccounts, sAccounts);
                continue;
            case 3: { // exit
                cout << "Goodbye!" << endl;
                exit(1);
            }
            default: { // if any other input was inputted; restart
                cout << "Try another input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            break;
        }
    }
}

void openAccount() { 
    srand((unsigned) time(0)); // random number account ID 
    string accNumber;
    int random;
    cout << "Creating your checkings and savings...." << endl;
    for(int i = 0; i < 7; i++) { // creates the digits
        random = 1 + (rand() % 9);
        accNumber += to_string(random);
    }
    SavingsAccount newSavings;
    CheckingAccount newChecking;
    cout << "Your Checking Account number is: #C" << accNumber << endl;
    newChecking.accNum = "C" + accNumber;
    cout << "Your Savings Account number is: #S" << accNumber << endl;
    newSavings.accNum = "S" + accNumber;
    for(;;) { // loop to deposit x amount of money into each account until they wish to stop
        cout << "How much would you like to deposit into the checking account?: " << endl;
        long double depositAmt;
        cin >> depositAmt;
        newChecking.deposit(depositAmt);
        cout << "How much would you like to deposit into the savings account?: " << endl;
        cin >> depositAmt;
        newSavings.deposit(depositAmt);
        cout << "Would you like to deposit more? 1 = YES || 2 = NO:" << endl;
        int choice;
        cin >> choice;
        // Input validation
        while (choice > 2)
        {
            cout << "Would you like to deposit more? 1 = YES || 2 = NO:" << endl;
            cin.clear();
            cin.ignore(123,'\n');
            cin >> choice;
        }
        while(choice < 1)
        {
            cout << "Would you like to deposit more? 1 = YES || 2 = NO:" << endl;
            cin.clear();
            cin.ignore(123,'\n');
            cin >> choice;
        }
        while(cin.fail())
        {
            cout << "Would you like to deposit more? 1 = YES || 2 = NO:" << endl;
            cin.clear();
            cin.ignore(123,'\n');
            cin >> choice;  
        }
        if(choice == 2) {
            break;
        }
    }
    cout << "\n\n" << endl;
    cout << "Checkings Account ID: " << newChecking.accNum << endl;
    cout << "Checkings Balance: " << newChecking.accBalance << endl;
    cout << "Savings Account ID: " << newSavings.accNum << endl;
    cout << "Savings Balance: " << newSavings.accBalance << endl;
    cout << "\n\n" << endl;
    // Append to the file accounts, add error counting to the files
    ofstream outFile("checkingAcc.txt", std::ios_base::out | std::ios_base::app);
    outFile << newChecking.accNum << endl;
    outFile << newChecking.accBalance << endl;
    outFile.close();
    ofstream outFile2("savingAcc.txt", std::ios_base::out | std::ios_base::app);
    outFile2 << newSavings.accNum << endl;
    outFile2 << newSavings.accBalance << endl;
    outFile2.close();
    
    
}

int getTotalCheckingAccounts() { // get total checking accounts in checkingAcc.txt
    int totalAccounts = 0;
    string text;
    ifstream inFile("checkingAcc.txt");

    if (!inFile)
    {
        cout << "file not found" << endl;
        return -1;
    }

    while (getline(inFile, text))
        totalAccounts++;


    inFile.close();

    return totalAccounts/2;
}

int getTotalSavingAccounts() { // get total saving accounts in savingAcc.txt
    int totalAccounts = 0;
    string text;
    ifstream inFile("savingAcc.txt");

    if (!inFile)
    {
        cout << "file not found" << endl;
        return -1;
    }

    while (getline(inFile, text))
        totalAccounts++;


    inFile.close();
    return totalAccounts/2;

}

void loadFile(CheckingAccount *cAccounts, SavingsAccount *sAccounts) { // populate the two arrays with information from the sAcc & cAcc files

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
        int count = 0;
        
        while (getline(inFile, text))
        {
            
            if (text.find("S") == 0)
            {
                accNum = text;
                
            }
            getline(inFile,text);
             try{
                 balance = stod(text);
             }catch(...) {
                 break;
                 
             }
        sAccounts[count].accNum = accNum;
        sAccounts[count].accBalance = balance;
        count++; // current index of the acocunts
         
    }
    inFile.close();
    // FILL checking ACCOUNTS WITH INFO

    inFile.open("checkingAcc.txt");
    if(!inFile) {
        cout << "Error reading file..." << endl;
        return;
    }

    if (inFile)
    {
        long double balance;
        string accNum;
        int count = 0;
        while (getline(inFile, text))
        {
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
        cAccounts[count].accNum = accNum;
        cAccounts[count].accBalance = balance;
        count++; // current index of the accounts
      }
    }
    inFile.close();
 }
 

}

void login(CheckingAccount *cAccounts, SavingsAccount *sAccounts) {
    string accountNumber;
    do { // ask for input
        cout << "\n";
        cout << "-------------------" << endl;
        cout << "Enter an 8 digit account number: ";
        cin >> accountNumber;
        }while(accountNumber.length() != 8); // make sure the length is 8. 
    
    if(accountNumber.find("C") == 0) // if the input is C, check for checking accounts
    {
        
        for(int i = 0; i < getTotalCheckingAccounts(); i++) {
             //if (day change)
             sAccounts[i].calcInterest(sAccounts[i].accBalance);
            if(accountNumber == cAccounts[i].accNum.substr(0,8)) { // if the account matches a current acc
                for(;;) { // menu for account loop
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Deposit into your checking account" << endl;
                    cout << "[2] Withdraw from your checking account" << endl;
                    cout << "[3] Return to main menu" << endl;
                    cout << "[4] View Account Information (Balance, Annual Service Charge)" << endl;
                    cout << "ACC #: " << cAccounts[i].accNum << endl;
                    cout << "-------------------" << endl;
                    int userInput;
                    cin >> userInput;
                    switch(userInput) {
                       case 1: {

                         cout << "-------------------" << endl;
                         cout << "How much would you like to deposit into the account?: " << endl;
                         cout << "-------------------" << endl;
                         long double depositAmt;
                         cin >> depositAmt;

                         cAccounts[i].deposit(depositAmt);

                         cout << "-------------------" << endl;
                         cout << "Your new balance is: " << cAccounts[i].accBalance << endl;
                         cout << "-------------------" << endl;
                         cout << "Hit enter to continue" << endl;
                         char enter = cin.get(); 
                         cin.ignore();
                         reloadFile(cAccounts, sAccounts);
                         continue;

                        }
                        case 2: {
                          cout << "-------------------" << endl;
                          cout << "How much would you like to withdraw from the account?: " << endl;
                          cout << "-------------------" << endl;
                          long double withdrawAmt;
                          cin >> withdrawAmt;
                          cout << "-------------------" << endl;

                          cAccounts[i].withdraw(withdrawAmt);
                          cout << "-------------------" << endl;
                          cout << "Your new balance is: " << cAccounts[i].accBalance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();

                          continue;
                         }
                        case 3: { // exit case
                            return;
                         }
                        case 4: {
                            cout << "-------------------" << endl;
                            cout << "Your current Balance is: " << cAccounts[i].accBalance << endl;
                            cout << "Annual Service Charge: " << cAccounts[i].annualSC << endl;
                            cout << "-------------------" << endl;
                            cout << "Hit enter to continue" << endl;
                            char enter = cin.get(); 
                            cin.ignore();
                            continue;
                        }
                        default: { // error catching
                                cout << "Try another input!" << endl;
                                cin.clear();
                                cin.ignore();
                                continue;
                         }
                        }
                     }
                 }
             }
        }else if (accountNumber.find("S") == 0) { // if the input is a Savings account
            for(int i = 0; i < getTotalSavingAccounts(); i++) {
            if(accountNumber == sAccounts[i].accNum) { // check against all savings account
                for(;;) {
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Deposit into your savings account" << endl;
                    cout << "[2] Withdraw from your savings account" << endl;
                    cout << "[3] Return to main menu" << endl;
                    cout << "[4] View Account Information (Balance, Annual Service Charge)" << endl;
                    cout << "ACC #: " << sAccounts[i].accNum << endl;
                    cout << "-------------------" << endl;
                    int userInput;
                    cin >> userInput;
                    switch(userInput) {
                       case 1: {

                         cout << "-------------------" << endl;
                         cout << "How much would you like to deposit into the account?: " << endl;
                         cout << "-------------------" << endl;
                         long double depositAmt;
                         cin >> depositAmt;

                         sAccounts[i].deposit(depositAmt);

                         cout << "-------------------" << endl;
                         cout << "Your new balance is: " << sAccounts[i].accBalance << endl;
                         cout << "-------------------" << endl;
                         cout << "Hit enter to continue" << endl;
                         char enter = cin.get(); 
                         cin.ignore();
                         continue;

                        }
                        case 2: {
                          cout << "-------------------" << endl;
                          cout << "How much would you like to withdraw from the account?: " << endl;
                          cout << "-------------------" << endl;
                          long double withdrawAmt;
                          cin >> withdrawAmt;
                          cout << "-------------------" << endl;

                          sAccounts[i].withdraw(withdrawAmt);
                          cout << "-------------------" << endl;
                          cout << "Your new balance is: " << sAccounts[i].accBalance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
   
                          continue;
                         }
                        case 3: { // exit case
                            return;
                         }
                        case 4: { 
                            cout << "-------------------" << endl;
                            cout << "Your current Balance is: " << sAccounts[i].accBalance << endl;
                            cout << "Annual Service Charge: " << sAccounts[i].annualSC << endl;
                            cout << "-------------------" << endl;
                            cout << "Hit enter to continue" << endl;
          
                            char enter = cin.get(); 
                            cin.ignore();
                            continue;
                        }
                        default: { // error catching
                                cout << "Try another input!" << endl;
                                cin.clear();
                                cin.ignore();
                                continue;
                         }
                        }
                     }
                 }
             }
        }else {
        cout << "Invalid Account #" << endl; // error catching
    }
   
}

void reloadFile(CheckingAccount *cAccounts, SavingsAccount *sAccounts) { // a function to overwrite the file with the new updated changes to the accounts
    int totalCheckings = getTotalCheckingAccounts(); // get how many accounts there are now
    int totalSavings = getTotalSavingAccounts(); // get how many accounts there are now
    cout << totalSavings << endl;
    ofstream outFile;
    outFile.open("checkingAcc.txt");
    for(int i = 0; i < totalCheckings; i++) { // loop to output to the file 
        outFile << cAccounts[i].accNum << endl;
        outFile << cAccounts[i].accBalance << endl;
    }
    outFile.close();

    ofstream outFile2;
    outFile2.open("savingAcc.txt");

    for(int i = 0; i < totalSavings; i++) { // loop to  output to the file
        outFile2 << sAccounts[i].accNum << endl;
        outFile2 << sAccounts[i].accBalance << endl;
    }

    outFile2.close();

}
