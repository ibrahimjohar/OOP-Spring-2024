/*
*   Programmer : Ibrahim Johar Farooqi
*   Date: 5 February 2024
*   Description: You’re given an integer array and a target sum. Your job is to write a recursive function in C++ that checks if there’s a subset of the array
*                whose elements sum up to the target sum. 
*                • Develop a recursive function named hasSubsetSum that accepts an integer array, the array’s size, and a target sum as input and 
*                    returns a boolean indicating whether a subset with the specified sum exists.
*                • The function should have the following signature:
*                    bool hasSubsetSum(int arr[], int size, int targetSum).
*/

#include <iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum)
{
    //base cases
    if(targetSum == 0)
    {
        return true;
    }
    if(targetSum != 0 && size == 0)
    {
        return false;
    }

    //recursive cases
    if(targetSum > arr[size-1])
    {
        hasSubsetSum(arr, size-1, targetSum);
    }
     return hasSubsetSum(arr, size - 1, targetSum) || hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
    
}

int main()
{
    int arr[] = {20, 4, 2, 5, 35, 21, 56};
    int targetSum = 45;

    if (hasSubsetSum(arr, sizeof(arr) / 4, targetSum)) //check if condition is true
    {
        cout << "The subset successfully sums up to " << targetSum;
    }
    else
    {
        cout << "The Subset Sum does not exist in the array";
    }

    return 0;
}
