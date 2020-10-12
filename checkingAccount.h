#include <string>
#include <iostream>
#include <bankAccount.h>
using namespace std;

class checkingAccount : public bankAccount {
    protected:
    bool flag;
    public:
    void deposit(double amount) {
        if(amount > 9999.0) {
            cout << "Your account is now considered high risk due to the large deposit." << endl;
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
};