#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//parent class
// bank account 
class BankAccount
{
    public:
    string accNum;
    long double accBalance;
    double annualIR;
    double annualSC;

    public:
    // Default
    BankAccount()
    {
        accNum = "";
        accBalance = 0.0;

        ifstream nFile;
        nFile.open("interestRate.txt");
        string text2;
        getline(nFile,text2);
        if(annualIR >= .1 && annualIR <= 10) {
         annualIR = stod(text2);
        }else {
            annualIR = 0;
        }

        ifstream inFile;
        inFile.open("serviceCharge.txt");
        string text;
        getline(inFile,text);
        annualSC = stod(text);


    }
    // Constructor
    BankAccount(string num, long double balance, double intrestRate)
    {
        accNum  = num;
        accBalance = balance;
        annualIR = intrestRate;
    }
    // Deposits an amount specified into the account balance
    virtual void deposit(long double ammount)
    {
        accBalance += ammount;
    }
    // Withdraws an amount specified from the account balance
    virtual void withdraw(long double ammount)
    {
        accBalance -= ammount;
    }
    // calculates daily interest rate and adds the daily interest to account balance
    double calcInt(double balance)
    {
        double dailyIR = annualIR / 365;
        dailyIR = dailyIR * accBalance;
        accBalance += dailyIR;
        return accBalance;
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
