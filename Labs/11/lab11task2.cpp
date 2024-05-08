/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 29 April 2024
*   Description: You need to create a base class called Account that has common attributes and methods for all types of accounts, such as account number, balance, and 
*                deposit/withdrawal methods. However, the interest calculation and account-specific rules vary depending on the type of account (e.g., savings, current, credit).
*                Create an abstract class Account with pure virtual functions for interest calculation and account-specific rules, and then create concrete subclasses for each type of account.
*/

#include <iostream>
using namespace std;

class Account
{
    protected:
        int accountNumber;
        double balance;
    public:
        Account(int account, double bal)
            : accountNumber(account), balance(bal) {}

        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
        virtual double calculateInterest() = 0;

        int getAccountNumber() const { return accountNumber; }
        double getBalance() const { return balance; }
};

class SavingsAccount : public Account
{
    private:
        double interestRate;
    public:
        SavingsAccount(int account, double bal, double rate)
            : Account(account, bal), interestRate(rate) {}

        void deposit(double amount) override
        {
            if (amount > 0) { balance += amount; }
        }

        void withdraw(double amount) override 
        {
            if (amount > 0 && amount <= balance) { balance -= amount; }
        }

        double calculateInterest() override { return balance * interestRate; }
};

class CurrentAccount : public Account
{
    private:
        double overdraftLimit;
    public:
        CurrentAccount(int account, double bal, double overdraft)
            : Account(account, bal), overdraftLimit(overdraft) {}

        void deposit(double amount) override 
        {
            if (amount > 0) { balance += amount; }
        }

        void withdraw(double amount) override 
        {
            if (amount > 0 && amount <= balance + overdraftLimit) {  balance -= amount; }
        }

        double calculateInterest() override { return 0; } //current accs cant earn interest
};
