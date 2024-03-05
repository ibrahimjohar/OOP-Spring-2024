/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Create a BankAccount class. Which contains following details and functionalties:
*                Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
*                Create Constructor: The class has a constructor that takes parameters to initialize the account details (accountNumber, accountHolderName, and balance).
*                Create following Member Functions:
*                • deposit(double amount): Adds the specified amount to the account balance.
*                • withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
*                • display(): Displays the account details including the account number, account holder name, and balance.
*/

#include <iostream>
using namespace std;

class BankAccount
{   
    private:
        int accountNumber;
        string accountHolderName;
        double balance;
    public:
        BankAccount(){}; //default constructor
        BankAccount(int accountNumber, string accountHolderName, double balance) //parameterized constructor
        {
            this->accountNumber = accountNumber;
            this->accountHolderName = accountHolderName;
            this->balance = balance;            
        }

        double deposit(double amount)
        {
            balance += amount;
            return balance;
        }

        double withdraw(double amount)
        {
            balance -= amount;
            return balance;
        }

        void display()
        {
            cout << "Account Holder Name: " << accountHolderName << "\n";
            cout << "Account Number: " << accountNumber << "\n";
            cout << "Account Balance: " << balance << "\n\n";
        }

        void displayBalance()
        {
            cout << "Balance: " << balance << "\n\n";
        }
};

int main()
{
    BankAccount banksAccs[3];

    banksAccs[0] = BankAccount(3456, "James", 1500.0);
    banksAccs[1] = BankAccount(1345, "Armstrong", 700.0);
    banksAccs[2] = BankAccount(9834, "John", 900.0);

    for (int i = 0; i < 3; i++) //loop for transactions 
    {
        cout << "Bank Account " << i+1 << ":\n";
        banksAccs[i].display();
        banksAccs[i].deposit(500.0);
        cout << "After Deposit Transaction:\n";
        banksAccs[i].displayBalance();

        banksAccs[i].withdraw(200.0);
        cout << "After Withdrawl Transaction:\n";
        banksAccs[i].displayBalance();
    }


    return 0;
}