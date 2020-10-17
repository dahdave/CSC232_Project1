#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>
#include "BankAccount.h"
#include <limits>
using namespace std;


//  David Harper — M03353490
//  Christian Lesile — M02560358
//  Ethan Dawley - M03110954
//


// SavingsAccount represents a functioning savings account
// SavingsAccount class is a child class of parent
// BankAccount class

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
   // Function to deposit money
   void deposit(double amount) 
   {
      if(amount > 0.00) // If the amount deposited is more than 0 
      {
         accBalance += amount;// Successfully deposit
      }
      else// If the deposit is not a positive amount it will not deposit
      {
         cout << "Invalid deposit" << endl;// Lets user know amount is invalid for deposit
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         for(;;) 
         {
            cout << "Please enter a valid deposit: "<< endl;// Prompts user to enter a valid deposit
            double amt;
            cin >> amt;
            deposit(amt);
            break;
         }
      }
      if(accBalance >= 50.0)// If the balance is greater than $50 the status will remain active 
      {
         status = true;
      }
      else // redudant statement...
      { 
         status = false; 
      }
        
   }
   void withdraw(double amount) // Function to withdraw money
   {
       if(status == false) 
        { // Deny the withdraw
            cout << "You may not withdraw, your account balance is: $" << accBalance << endl;
            cout << "You must raise your account balance above $50 to become/remain active." << endl;
        }
        else if (status == true) 
        { // Do the withdraw from the balance
            if(accBalance >= amount) 
            {
                accBalance -= amount; 
            }
            else 
            {
                cout << "Invalid funds " << endl;
            }
            if(accBalance < 1.00)// If the balance falls below a dollar close the acount
            {
                cout << "The savings account was closed. Balance fell below $1" << endl;
                closeAcc();
            }
            if(accBalance < 50.0)// If the balance falls below $50 account becomes inactive 
            {
                cout << "Warning! Your savings account is now inactive because the balance is now below $50. " << endl;
                cout << "There was a $5 service charge. ";
                accBalance -= 5;
                cout << "You must deposit more money before you can make another withdraw." << endl;
                status = false;
            }
        }
    }
    void calcInterest(double accBalance)// Calculates current interest
    {
       accBalance = calcInt(accBalance);
    }      
};
#endif
