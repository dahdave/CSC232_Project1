#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
#include "BankAccount.h"
#include <limits>
using namespace std;


//  David Harper — M03353490
//  Christian Lesile — M02560358
//  Ethan Dawley - M03110954
//

class CheckingAccount : public BankAccount {
   public:
   bool flag; // high risk
   // Default constructor
   CheckingAccount() : BankAccount()
   {
      flag = false;
   }
    
   CheckingAccount(string num, long double balance, double intrestRate) 
   : BankAccount(num, balance, intrestRate)
   {
      flag = false;
   }
       

   void checkings()
   {
      bool flag = true;
   }
    void deposit(long double amount) {
        if(amount > 9999.0) {
            cout << "Your account is now considered high risk due to the large deposit." << endl; // large deposit = high risk
            accNum = accNum + "*"; // apend to the accNum to indicate high risk
        } 
        if(amount > 0.00) {
            accBalance += amount; // deposit the amount
        }else {
            cout << "Invalid deposit" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) { // error checking
                cout << "Please enter a valid deposit: " << endl;
                double amt;
                cin >> amt;
                deposit(amt);
                break;
            }
        }
        if(accBalance >= 50.0) {
            flag = true;
        }else { // redudant statement...
            flag = false; 
        }
    }
    void withdraw(long double amount) {
       if(amount < 0.00) {
          cout << "Invalid withdraw" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) { // error checking
                cout << "Please enter a valid withdraw: " << endl;
                double amt;
                cin >> amt;
                withdraw(amt);
                break;
            }
       }
       if(accBalance >= amount) {
                accBalance -= amount; // subtract the amount if it's in the balance
            }else {
                cout << "Invalid funds " << endl;
                cout << "A non-sufficient fund charge ($25) was applied to your account" << endl;
                accBalance -= 25.0; // service charge
                if(accBalance < 0.00) { // if account balance is below 0, it's at high risk
                    flag = true;
                    cout << "Your balance fell below $0.";
                    cout << " Your checking account is now considered high risk." << endl;
                    accNum = accNum + "*"; // append to the end of account number
                }
            }
    } 
};
#endif
