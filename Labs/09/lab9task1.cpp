/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 28 March 2024
*   Description: You are tasked with developing a software module for a geometry library that calculates the
*                areas and perimeters of various shapes. Your module needs to efficiently handle circles,
*                rectangles, and triangles. You've decided to implement this module in C++, utilizing function
*                overloading and a global constant for the value of pi.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class Shape
{
    public:
        //area of a circle
        double area(double radius)
        {
            return PI * radius * radius;
        }

        //area of a rectangle
        double area(double length, double width)
        {
            return length * width;
        }

        //area of a triangle
        double area(double s1, double s2, double s3)
        {
            double s = (s1 + s2 + s3) / 2;
            return sqrt(s * (s - s1) * (s - s2) * (s - s3));
        }

        //perimeter of a circle
        double perimeter(double radius)
        {
            return 2 * PI * radius;
        }

        //perimeter of a rectangle
        double perimeter(double length, double width)
        {
            return 2 * (length + width);
        }

        //perimeter of a triangle
        double perimeter(double side1, double side2, double side3)
        {
            return side1 + side2 + side3;
        }
};

int main()
{
    Shape shape1;

    //Circle
    double radius = 4.5;
    cout << "Circle Radius = " << radius << "\n";
    cout << "Area = " << shape1.area(radius) << "\n";
    cout << "Perimeter = " << shape1.perimeter(radius) << "\n";

    //Rectangle
    double len = 10; double width = 5;
    cout << "\nRectangle Length = " << len << ", Width = " << width << "\n";
    cout << "Area = " << shape1.area(len, width) << "\n";
    cout << "Perimeter = " << shape1.perimeter(len, width) << "\n";

    //Triangle
    double s1 = 6.0; double s2 = 4.0; double s3 = 5.0;
    cout << "\nTriangle Side 1 = " << s1 << ", Side 2 = " << s2 << ", Side 3 = " << s3 << "\n";
    cout << "Area = " << shape1.area(s1, s2, s3) << "\n";
    cout << "Perimeter = " << shape1.perimeter(s1, s2, s3) << "\n";

    return 0;
}
