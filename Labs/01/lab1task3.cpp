/*
*   Name: Ibrahim Johar Farooqi
*   Date: 25 Jan 2024
*   Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
                 You may assume that each input would have exactly one solution, and you may not use the same element twice.
                 You can return the answer in any order.
                 Input: nums = [2,7,11,15], target = 9
                 Output: [0,1]
                 Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;
    int *nums = new int[n]; // dynamically allocating the array 'nums'
    cout << "Enter Values to be stored in array: \n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Your Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ",";
    }

    int target;
    int index_1, index_2, flag = 0;
    cout << "\nEnter the target integer: ";
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                index_1 = i;
                index_2 = j;
                flag = 1;
                break; 
            }
        }
        if (flag == 1)
        {
            break;  
        }
    }

    if (flag == 0)
    {
        cout << "target not found in array.\n";
    }
    else
    {
        cout << "index 1: " << index_1 << "\n";
        cout << "index 2: " << index_2 << "\n";
    }

    delete[] nums;
    return 0;
}
