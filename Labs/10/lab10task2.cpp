/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 18 April 2024
*   Description: Write a program to overload decrement operator -- in such a way that when it is used as a prefix,
*                it multiplies a number by 4 and when it is used as a postfix then it divides the number by 4.
*/

#include <iostream>
using namespace std;

class C
{
    private:
        int val;
    public:
        C(int v) : val(v) {}

        C operator --(int)
        {
            return val = val /4;
        }

        C operator --()
        {
            return val = val * 4;
        }

        void displayVal()
        {
            cout << "Value: " << val << "\n";
        }
};

int main()
{

    C obj1(5);
    cout << "Value before prefix used:\n";
    obj1.displayVal();

    cout << "\nValue after prefix used:\n";
    --obj1;
    obj1.displayVal();

    cout << "\nValue after postfix used:\n";
    obj1--;
    obj1.displayVal();

    return 0;
}