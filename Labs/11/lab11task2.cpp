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
