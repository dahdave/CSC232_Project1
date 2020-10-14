#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
//#include <fstream>
#include "BankAccount.h"
using namespace std;

class CheckingAccount : public BankAccount {
   public:
   bool flag;
   // Default constructor
   CheckingAccount() : BankAccount()
   {
      flag = false;
   }
    
   CheckingAccount(string num, double balance, double interestRate) 
   : BankAccount(num, balance, interestRate)
   {
      flag = false;
   }
       

   void checkings()
   {
      flag = true;
   }
    void deposit(double amount) {
        if(amount > 9999.0) {
            cout << "Your account is now considered high risk due to the large deposit." << endl;
            //ofstream txtFile;
            //txtFile.open
        }
        if(amount > 0.00) {
            accBalance += amount;
        }else {
            cout << "Invalid deposit" << endl;
        }
        if(accBalance >= 50.0) {
            flag = true;
        }else { // redudant statement...
            flag = false; 
        }
    }
    void withdraw(double amount) {
       if(accBalance >= amount) {
                accBalance -= amount; 
            }else {
                cout << "Invalid funds " << endl;
                cout << "A non-sufficient fund charge ($25) was applied to your account" << endl;
                accBalance -= 25.0;
                cout << "Your balance is now: " << accBalance << endl;
                if(accBalance < 0.00) {
                    flag = true;
                    cout << "Your balance fell below $0.";
                    cout << "Your checking account is now considered high risk.";
                }
            }
    }
    void setAccount (string num, double balance, double interestRate)
    {
        accNum  = num;
        accBalance = balance;
        annualIR = interestRate;
    } 
};
#endif
