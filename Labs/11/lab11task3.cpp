/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 29 April 2024
*   Description: You are working on a project that involves managing different types of vehicles, such as cars, trucks, and motorcycles.
*                You need to create a base class called Vehicle that has common attributes and methods, such as make, model, and speed.
*                However, the specific features and behaviors vary depending on the type of vehicle (e.g., fuel efficiency, cargo capacity).
*                Create an abstract class Vehicle with pure virtual functions for specific features and behaviors, and then create concrete subclasses for each type of vehicle.
*/

#include <iostream>
using namespace std;

class Vehicle
{
    protected:
        string make, model;
        int speed;
    public:
        Vehicle(string mK, string mD, int s = 0)
            : make(mK), model(mD), speed(s) {}

        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual double calculateFuelEfficiency() = 0;

        string getMake() const { return make; }
        string getModel() const { return model; }
        int getSpeed() const { return speed; }
};

class Car : public Vehicle
{
    private:
        double fuelCapacity;
    public:
        Car(string mK, string mD, double fuelCap)
            : Vehicle(mK, mD), fuelCapacity(fuelCap) {}

        void accelerate() override { speed += 10; }

        void brake() override
        {
            speed -= 10; 
            if (speed < 0) { speed = 0; }
        }

        double calculateFuelEfficiency() override { return fuelCapacity / 100.f; }
};

class Truck : public Vehicle 
{
    private:
        int cargoCapacity;
    public:
        Truck(string mK, string mD, int cargoCap)
            : Vehicle(mK, mD), cargoCapacity(cargoCap) {}

        void accelerate() override { speed += 5; }

        void brake() override
        {
            speed -= 5; 
            if (speed < 0) { speed = 0; }
        }

        double calculateFuelEfficiency() override { return 0.75f; } //assumption
};
