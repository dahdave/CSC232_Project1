#include <string>
#include <iostream>
#include <bankAccount.h>
using namespace std;

class savingsAccount : public bankAccount {
    protected:
    bool status;
   // Default constructor
   void savings()
   {
      bool status = true;
   }
    public:
    void deposit(double amount) {
        if(amount > 0.00) {
            accBalance += amount;
        }else {
            cout << "Invalid deposit" << endl;
        }
        if(accBalance >= 50.0) {
            status = true;
        }else { // redudant statement...
            status = false; 
        }
        
    }
    void withdraw(double amount) {
        if(status == false) { // deny the withdraw
            cout << "You may not withdraw, your account balance is: " << accBalance << endl;
            cout << "You must raise your account balance above $50 to become/remain active." << endl;
        }else if (status == true) { // do the withdraw from the balance
            if(accBalance >= amount) {
                accBalance -= amount; 
            }else {
                cout << "Invalid funds " << endl;
                cout << "Your balance is: " << accBalance << endl;
            }
            if(accBalance < 1.00) {
                cout << "The savings account was closed. Balance fell below $1" << endl;
                closeAcc();
            }
            if(accBalance < 50.0) {
                cout << "Warning! Your savings account is now inactive because the balance is now below $50." << endl;
                cout << "You must deposit more money before you can make another withdraw." << endl;
                status = false;
            }
        }
    }
};
