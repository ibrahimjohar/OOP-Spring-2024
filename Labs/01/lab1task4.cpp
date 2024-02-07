/*
*   Name: Ibrahim Johar Farooqi
*   Date: 25 Jan 2024
*   Description: Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a
*                container can store. Notice that you may not slant the container. 
*                Input: height = [1,8,6,2,5,4,8,3,7]
*                Output: 49
*                Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
*                In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <iostream>
using namespace std;

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int left_bound = 0;
    int right_bound = (sizeof(height)/sizeof(height[0])) - 1;
    int vertical_dis;
    int horizontal_dis;
    int max_output = 0;

    while (left_bound < right_bound)
    {
        if (right_bound == left_bound + 1)
        {
            right_bound = (sizeof(height)/sizeof(height[0])) - 1;
            left_bound++;
        }

        horizontal_dis = right_bound - left_bound;

        if (height[left_bound]>height[right_bound])
        {
            vertical_dis = height[right_bound];
        }

        if (height[left_bound]<height[right_bound])
        {
            vertical_dis = height[left_bound];
        }

        if (height[left_bound] == height[right_bound])
        {
            vertical_dis = height[left_bound];
        }

        if (max_output < (vertical_dis * horizontal_dis))
        {
            max_output = vertical_dis * horizontal_dis;
        }

        right_bound--;
    }

    cout << "The maximum amount of water that the container can hold is " << max_output;
    return 0;

}