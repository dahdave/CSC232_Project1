#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
//#include <fstream>
#include "BankAccount.h"
#include <limits>
using namespace std;

class CheckingAccount : public BankAccount {
   public:
   bool flag;
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
            cout << "Your account is now considered high risk due to the large deposit." << endl;
            //ofstream txtFile;
            //txtFile.open
        }
        if(amount > 0.00) {
            accBalance += amount;
        }else {
            cout << "Invalid deposit" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) {
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
            for(;;) {
                cout << "Please enter a valid withdraw: " << endl;
                double amt;
                cin >> amt;
                withdraw(amt);
                break;
            }
       }
       if(accBalance >= amount) {
                accBalance -= amount; 
            }else {
                cout << "Invalid funds " << endl;
                cout << "A non-sufficient fund charge ($25) was applied to your account" << endl;
                accBalance -= 25.0;
                if(accBalance < 0.00) {
                    flag = true;
                    cout << "Your balance fell below $0.";
                    cout << " Your checking account is now considered high risk." << endl;
                }
            }
    }
};
#endif
