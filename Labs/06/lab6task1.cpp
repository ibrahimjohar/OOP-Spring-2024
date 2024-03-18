/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 17 March 2024
*   Description: Consider a banking system where you have a BankAccount class representing individual accounts. Each BankAccount object contains a pointer to an array of
*                transactions representing the account history. For that, create class BankAccount which contains the private member variables int accountId, 
*                double balance to store account information., int* transactionHistory is a pointer to an array storing transaction history and int numTransactions used to
*                stores the number of transactions...
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class BankAccount 
{
    private:
        int accountId;
        double balance;
        int* transactionHistory;
        int numTransactions;
    public:
        BankAccount(int accId, double bal, int *tranHistory, int numTrans):
            accountId(accId), balance(bal), numTransactions(numTrans)
        {
            transactionHistory = new int[numTrans];
            memcpy(transactionHistory, tranHistory, numTrans * sizeof(int)); //copy provided transactions in new allocated memory 
        }

        BankAccount(const BankAccount &obj) //copy constructor
        {
            accountId = obj.accountId;
            balance = obj.balance;
            numTransactions = obj.numTransactions;

            transactionHistory = new int[numTransactions];
            memcpy(transactionHistory, obj.transactionHistory, numTransactions * sizeof(int)); //copy provided transactions in object to new allocated memory
        }


        ~BankAccount() //destructor
        {
            delete[] transactionHistory;
        }

        void display()
        {
            cout << "Account ID: " << accountId << "\n";
            cout << "Account Balance: " << balance << "\n";
            cout << "Number of Transactions: " << numTransactions << "\n";
            cout << "Transaction History:\n";
            for (int i = 0; i < numTransactions; i++)
            {
                cout << transactionHistory[i] << "\n";
            }
            cout << "\n";
        }

        void updateTransactionHistory(int* newTransactions, int newNumTrans)
        {
            delete[] transactionHistory; //delete existing transaction history

            numTransactions = newNumTrans;
            transactionHistory = new int[numTransactions];
            memcpy(transactionHistory, newTransactions, numTransactions * sizeof(int));
        }
};

int main()
{
    int transactionHis[] = {130, 145, 200, 1000};
    int nTransactions = sizeof(transactionHis) / sizeof(int);

    class BankAccount acc1(5698, 5000.0, transactionHis, nTransactions);

    //copy of original account created with copy constructor
    class BankAccount acc2(acc1);

    //display both accounts
    cout << "Original Account Details:\n";
    acc1.display();
    cout << "Copy of Original Account Details:\n";
    acc2.display();

    //new transaction history defined
    int newTransactionHis[] = {680, 178, 657, 325, 560};
    int newNumTransactions = sizeof(newTransactionHis) / sizeof(int);
    
    //call updatetransactionhistory function
    acc1.updateTransactionHistory(newTransactionHis, newNumTransactions);

    //display both accounts after update
    cout << "After UpdateTransactionHistory function is called:\n\n";
    cout << "Original Account Details:\n";
    acc1.display();
    cout << "Copy of Original Account Details:\n";
    acc2.display();

    return 0;
}
