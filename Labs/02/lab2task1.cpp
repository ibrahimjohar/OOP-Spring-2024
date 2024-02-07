/*
*   Programmer: Ibrahim Johar Farooqi
*   Date: 5 February 2024
*   Description: Your assignment is to develop a C++ function that interchanges the values of two variables.
                 Construct a recursive function called recursiveSwap that accepts two variables as arguments and swaps their values recursively.
*/
#include <iostream>
using namespace std;

void recursiveSwap(int *a, int *b, int counter)
{
    //base case for recursion
    if (counter == 0)
    {
        return;
    }
    //swapping
    int temp = *a;
    *a = *b;
    *b = temp;
    //recursive call decrementing the counter value on each call
    recursiveSwap(a, b, counter - 1);
}

int main()
{
    int val_1, val_2, count;
    cout << "Enter Value 1: ";
    cin >> val_1;
    cout << "Enter Value 2: ";
    cin >> val_2;
    cout << "Enter Number of times you would like to recursively swap these two values: ";
    cin >> count;

    cout << "\nValue 1 was: " << val_1 << " & Value 2 was: " << val_2 << endl;
    
    //function call
    recursiveSwap(&val_1, &val_2, count);
    
    cout << "\nValue 1 is now: " << val_1 << " & Value 2 is now: " << val_2 << endl;
    
    return 0;
}
