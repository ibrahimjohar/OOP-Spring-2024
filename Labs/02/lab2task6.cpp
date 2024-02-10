/*
*   Programmer : Ibrahim Johar Farooqi
*   Date: 5 February 2024
*   Description: You are asked to write a C++ program that calculates the Least Common Multiple (LCM) and Greatest Common Divisor (GCD) of two numbers.
*                Implement two separate recursive functions, calculateLCM and calculateGCD, each handling the corresponding task.
*/

#include <iostream>
using namespace std;

int calculateLCM(int a, int b)
{
    static int multiple_temp = 0;
    multiple_temp += b;

    if ((multiple_temp % a == 0) && (multiple_temp % b == 0))
    {
        return multiple_temp;
    }
    else
    {
        return calculateLCM(a, b);
    }
}

int calculateGCD(int num1, int num2) //euclid's algorithm applied where if num1 > num2 then the GCD of (num1, num2) = GCD(num2, num1 % num2), then the base case = GCD(num1, 0) = num1
{
    //base case
    if (num2 == 0)
    {
        return num1;
    }
    //recursive case
    else
    {
        return calculateGCD(num2, num1 % num2);
    }
}


int main()
{
    int n1, n2;
    cout << "Enter Num 1: ";
    cin >> n1;
    cout << "Enter Num 2: ";
    cin >> n2;

    int lcm, gcd;
    if (n1 > n2) //to ensure that num1 > num2 at all times
    {
        lcm = calculateLCM(n2, n1);
    }
    else
    {
        lcm = calculateLCM(n1, n2);
    }

    gcd = calculateGCD(n1, n2);

    cout << "GCD of " << n1 << " & " << n2 << " is " << gcd << "\n";
    cout << "LCM of " << n1 << " & " << n2 << " is " << lcm << "\n";

    return 0;
}