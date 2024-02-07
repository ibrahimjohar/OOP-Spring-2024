/*
*   Name: Ibrahim Johar Farooqi
*   Date: 25 Jan 2024
*   Description: Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?
*/

#include <iostream>
#include <stdbool.h>
using namespace std;


bool isPrime(int num);

int main()
{
    int num;
    cout << "Enter your number: ";
    cin >> num;

    if(isPrime(num)==true && num != 1)
    {
        cout << "The number is prime." << endl;
    }
    else 
    {
        cout << "The number is not prime." << endl;
    }
}

bool isPrime(int num)
{
    int factors=1;
    int i;
    for (i=2; i<=num; i++)
    {
        if (num % i == 0)
        {
            factors++;
        }
    }
    if (factors>2)
    {
        return false;
    }
    else
    {
        return true; 
    }
}
