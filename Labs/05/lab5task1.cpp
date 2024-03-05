/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Create a class called Square with the following attributes:
*                    • sideLength – float variable
*                    • area – float variable
*                    • allareas – static float variable
*                Create the following methods for your class:
*                    • Constructors (default and parameterized (only takes sideLength as input))
*                    • Function to calculate area, the calculated area should always be added to the allareas variable each time an area is calculated. (assume it’s called only once for each object)
*                    • Getters and Setters for all variables
*                In your main function create 3 Squares with different sideLength. Call the area method for each of those Square objects. After each time the area method is called, call that square’s
*                getters for area and allareas to display the updated values.
*/

#include <iostream>
using namespace std;

class Square
{
    private:
        float sideLength;
        float area;
        static float allareas;
    public:
        Square(){} //default constructor

        Square(float sideLength) //parameterized constructor
        {
            this->sideLength = sideLength;
        }

        //setters
        void set_sideLength(float sideLength)
        {
            this->sideLength = sideLength;
        }

        void set_area(float area)
        {
            this->area = area;
        }

        void set_allareas(float allareas)
        {
            this->allareas = allareas;
        }

        //getters
        float get_sideLength()
        {
            return sideLength;
        }

        float get_area()
        {
            return area;
        }

        static float get_allareas()
        {
            return allareas;
        }

        //method to calculate area
        void calculateArea()
        {
            area = sideLength * sideLength;
            allareas += area; 
        }
};

float Square :: allareas = 0;

int main()
{
    Square sq1(5);
    sq1.calculateArea();
    cout << "Square 1 Length: " << sq1.get_sideLength() << "\n";
    cout << "Square 1 Area: " << sq1.get_area() << "\n";
    cout << "All areas: " << sq1.get_allareas() << "\n\n";

    Square sq2(10);
    sq2.calculateArea();
    cout << "Square 1 Length: " << sq2.get_sideLength() << "\n";
    cout << "Square 1 Area: " << sq2.get_area() << "\n";
    cout << "All areas: " << sq2.get_allareas() << "\n\n";

    Square sq3(15);
    sq3.calculateArea();
    cout << "Square 1 Length: " << sq3.get_sideLength() << "\n";
    cout << "Square 1 Area: " << sq3.get_area() << "\n";
    cout << "All areas: " << sq3.get_allareas() << "\n\n";

    return 0;
}
