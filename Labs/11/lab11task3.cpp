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
