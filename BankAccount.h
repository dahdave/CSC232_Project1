#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <iostream>
using namespace std;
//parent class
// bank account 
class BankAccount
{
    public:
    string accNum;
    double accBalance;
    double annualIR;
    double annualSC;

    // Default
    BankAccount()
    {
        accNum = "";
        accBalance = 0.0;
        annualIR = 0.0;
    }
    // Constructor
    BankAccount(string num, double balance, double intrestRate)
    {
        accNum  = num;
        accBalance = balance;
        annualIR = intrestRate;
    }
    // Deposits an amount specified into the account balance
    virtual void deposit(double ammount)
    {
        accBalance += ammount;
    }
    // Withdraws an amount specified from the account balance
    virtual void withdraw(double ammount)
    {
        accBalance -= ammount;
    }
    // calculates daily interest rate and adds the daily interest to account balance
    void calcInt()
    {
        double dailyIR = annualIR / 365;
        dailyIR = dailyIR * accBalance;
        accBalance += dailyIR;
    }

    // unfinished
    void yearlyCharge()
    {
        accBalance -= annualSC;
    }
    //unfinished
    virtual void closeAcc()
    {
            delete this;
    }

};
#endif
