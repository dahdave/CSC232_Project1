#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>
#include "BankAccount.h"
#include <limits>
using namespace std;

class SavingsAccount : public BankAccount {
    public:
    bool status;
   // Default constructor
   SavingsAccount() : BankAccount()
   {
      status = true;
   }
   // 2nd Constructor
   SavingsAccount (string num, double balance, double interestRate): 
   BankAccount (num, balance, interestRate)
   {
      status = true;
   }

    void deposit(double amount) {
        if(amount > 0.00) {
            accBalance += amount;
        }else {
            cout << "Invalid deposit" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) {
                cout << "Please enter a valid deposit: "<< endl;
                double amt;
                cin >> amt;
                deposit(amt);
                break;
            }
        }
        if(accBalance >= 50.0) {
            status = true;
        }else { // redudant statement...
            status = false; 
        }
        
    }
    void withdraw(double amount) 
    {
        if(status == false) 
        { // deny the withdraw
            cout << "You may not withdraw, your account balance is: $" << accBalance << endl;
            cout << "You must raise your account balance above $50 to become/remain active." << endl;
        }
        else if (status == true) 
        { // do the withdraw from the balance
            if(accBalance >= amount) 
            {
                accBalance -= amount; 
            }
            else 
            {
                cout << "Invalid funds " << endl;
            }
            if(accBalance < 1.00) 
            {
                cout << "The savings account was closed. Balance fell below $1" << endl;
                closeAcc();
            }
            if(accBalance < 50.0) 
            {
                cout << "Warning! Your savings account is now inactive because the balance is now below $50. " << endl;
                cout << "There was a $5 service charge. ";
                accBalance -= 5;
                cout << "You must deposit more money before you can make another withdraw." << endl;
                status = false;
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
