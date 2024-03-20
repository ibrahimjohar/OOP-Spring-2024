/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 19 March 2024
*   Description: Suppose you are creating a program to represent different types of vehicles. You want to create
*                a base class called Vehicle that has member variables for the make, model, and year, as well
*                as a constructor to initialize these variables. You then want to create a derived class called Car
*                that inherits from Vehicle and adds member variables for the number of doors and the fuel
*                efficiency. Finally, you want to create a derived class called ElectricCar that inherits from
*                Car and adds a member variable for the battery life.
*                Write the code to define the Vehicle, Car, and ElectricCar classes, including constructors
*                to initialize the member variables. In each derived class constructor, make sure to call the
*                appropriate base class constructor using an initialization list. Also, demonstrate how to create
*                and use an object of the ElectricCar class.
*/

#include <iostream>
using namespace std;

class Vehicle
{
    public:
        string make;
        string model;
        int year;

        Vehicle(string veh_make, string veh_model, int y) :
            make(veh_make), model(veh_model), year(y) {}

};

class Car : public Vehicle
{
    public:
        int nDoors;
        int fuelEfficiency;

        Car(int nD, int fE, string ma, string mo, int y) : 
            nDoors(nD), fuelEfficiency(fE), Vehicle(ma, mo, y) {} 
};

class ElectricCar : public Car
{
    public: 
        int batterylife;

        ElectricCar(int battery, int nD, int fE, string ma, string mo, int y) :
            batterylife(battery), Car(nD, fE, ma, mo, y) {}

        void display()
        {
            cout << "Car Make: " << make << "\n";
            cout << "Car Model: " << model << "\n";
            cout << "Year of Manufacturing: " << year << "\n";
            cout << "Number of Doors: " << nDoors << "\n";
            cout << "Fuel Efficiency: " << fuelEfficiency << "%\n";
            cout << "Battery Life: " << batterylife << " Hours\n";
        } 
};

int main()
{
    ElectricCar tesla(56, 5, 89, "Tesla", "Model 3", 2017);

    tesla.display();

    return 0;
}   