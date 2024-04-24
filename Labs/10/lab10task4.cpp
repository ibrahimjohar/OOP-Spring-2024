/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 18 April 2024
*   Description: Write the following program to show the working of friend class. Define two classes i.e., “printClass” and “perimeter”.
*                perimeter class finds perimeter using length and breadth values where length and breadth values are private.
*                Make “printClass” a friend of “perimeter” class. Once this is done, create an object in main class 
*                to calculate perimeter and pass this object to printClass to display perimeter.
*/

#include <iostream>
using namespace std;

class perimeter
{
    private:
        double length;
        double width;
    public:
        perimeter(double l, double w) : 
            length(l), width(w) {}

        double calcPerimeter()
        {
            return ((length*2)+(width*2));
        } 

        friend class printClass;
};

class printClass
{
    public:
        void display(perimeter obj)
        {
            cout << "Perimeter: " << obj.calcPerimeter() << "\n";
        }
};

int main()
{
    perimeter obj1(10,5);

    printClass printObj;
    printObj.display(obj1);

    return 0;
}