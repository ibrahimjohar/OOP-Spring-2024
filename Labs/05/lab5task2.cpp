/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Create a class called LoanHelper, which helps the user calculate their loan payments. 
*                The class should have a variable that stores interest rate for the loan as a user defined constant value. 
*                Aside from the that, it also stores the amount for the loan taken and amount of months that the user will repay the loan in.
*                The loan repayment should be calculated on a monthly basis, and the interest rate should be applied over the monthly return amount.
*                The output should be something like:
*                “You have to pay 999 every month for 12 months to repay your loan”
*                Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate should be a value between 0-0.5%
*/

#include <iostream>
using namespace std;

class LoanHelper
{
    private:
        const float interestRate; //user defined constant value
        float amount;
        int amountOfMonths;
        float monthlyPayment;
    public:
        LoanHelper(float amount, int amountOfMonths, float rate): interestRate(rate/100)
        {
            this->amount = amount;
            this->amountOfMonths = amountOfMonths;
            this->monthlyPayment = 0.0;
        }

        void calculateMonthlyLoan() //method to calculate loan
        {
            monthlyPayment = (amount / amountOfMonths);
            monthlyPayment += monthlyPayment * interestRate;
        }

        float get_monthlyPayment()
        {
            return monthlyPayment;
        }
};

int main()
{
    LoanHelper loan1(1000, 12, 5);
    loan1.calculateMonthlyLoan();

    cout << "You have to pay $" << loan1.get_monthlyPayment() << " every month for 12 months to repay your loan.\n";

    return 0;
}