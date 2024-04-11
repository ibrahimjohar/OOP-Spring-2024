/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 28 March 2024
*   Description: Suppose you are tasked with developing a geometry application that helps users calculate
*                properties of various shapes. You are required to implement classes for different shapes such
*                as Circle, Rectangle, Square, Triangle, and EquilateralTriangle. Each shape class
*                should inherit from a base class called Shape. Additionally, the EquilateralTriangle class
*                should inherit from the Triangle class. Your implementation should utilize method overriding
*                and pointers to ensure polymorphic behavior.
*/

#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

class Shape
{
protected:
    mutable double area;
    mutable double perimeter;

public:
    Shape() {}

    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual void displayProperties() const = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r), Shape() {}

    double Area() const
    {
        area = M_PI * radius * radius;
        return area;
    }

    double Perimeter() const
    {
        perimeter = 2 * M_PI * radius;
        return perimeter;
    }

    void displayProperties() const
    {
        cout << "Properties of the Circle: \n";
        cout << "Area: " << Area() << "\n";
        cout << "Perimeter: " << Perimeter() << "\n";
        cout << "Diameter: " << radius * 2 << "\n";
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w), Shape() {}

    double Area() const
    {
        area = length * width;
        return area;
    }

    double Perimeter() const
    {
        perimeter = 2 * (length + width);
        return perimeter;
    }

    void displayProperties() const
    {
        cout << "Properties of the Rectangle: \n";
        cout << "Area: " << Area() << "\n";
        cout << "Perimeter: " << Perimeter() << "\n";
        cout << "Diagonal: " << sqrt(length * length + width * width) << "\n";
    }
};

class Square : public Shape
{
private:
    int sidelength;

public:
    Square(int l) : sidelength(l), Shape() {}

    double Area() const
    {
        area = sidelength * sidelength;
        return area;
    }

    double Perimeter() const
    {
        perimeter = 4 * sidelength;
        return perimeter;
    }

    void displayProperties() const
    {
        cout << "Properties of the Square: \n";
        cout << "Area: " << Area() << "\n";
        cout << "Perimeter: " << Perimeter() << "\n";
        cout << "Diagonal: " << sqrt(2 * sidelength * sidelength) << "\n";
    }
};

class Triangle : public Shape
{
protected:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3), Shape() {}

    double Area() const
    {
        double s = (side1 + side2 + side3) / 2;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        return area;
    }

    double Perimeter() const
    {
        perimeter = side1 + side2 + side3;
        return perimeter;
    }

    void displayProperties() const
    {
        cout << "Properties of the Triangle:\n";
        cout << "Area: " << Area() << "\n";
        cout << "Perimeter: " << Perimeter() << "\n";
    }
};

class EquilateralTriangle : public Triangle
{
private:
    double side;

public:
    EquilateralTriangle(double s) : Triangle(s, s, s), side(s) {}

    double Area() const
    {
        //area = (sqrt(3)/4) * (side^2)
        const double constantVal = 0.43301270189; // sqrt(3)/4
        area = constantVal * (side * side);
        return area;
    }

    double Perimeter() const
    {
        return 3 * side;
    }

    void displayProperties() const
    {
        cout << "Properties of the Equilateral Triangle:\n";
        cout << "Area: " << Area() << "\n";
        cout << "Perimeter: " << Perimeter() << "\n";
    }
};

int main()
{
    Shape *shape1;
    int choice;
    int flag = 1;
    while (flag == 1)
    {
        cout << "Please select a shape:\n"
             << "1. Circle\n"
             << "2. Rectangle\n"
             << "3. Square\n"
             << "4. Triangle\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
            case 1:
            {
                double rad;
                cout << "Enter the radius of the circle: ";
                cin >> rad;
                shape1 = new Circle(rad);
                break;
            }
            case 2:
            {
                double len, wid;
                cout << "Enter the length of the rectangle: ";
                cin >> len;
                cout << "Enter the width of the rectangle: ";
                cin >> wid;

                shape1 = new Rectangle(len, wid);
                break;
            }
            case 3:
            {
                double side;
                cout << "Enter side length of square: ";
                cin >> side;
                shape1 = new Square(side);
                break;
            }
            case 4:
            {
                double s1, s2, s3;
                cout << "Enter length of each side(3): ";
                cin >> s1 >> s2 >> s3;

                if (s1 == s2 && s1 == s3)
                {
                    shape1 = new EquilateralTriangle(s1);
                }
                else
                {
                    shape1 = new Triangle(s1, s2, s3);
                }
                break;
            }
        }

        shape1->displayProperties();

        string choice2;
        cout << "Do you want to calculate properties for another shape? (yes/no): ";
        cin >> choice2;

        if (choice2 == "no")
        {
            flag = 0;
        }
    }

    delete shape1;

    return 0;
}
