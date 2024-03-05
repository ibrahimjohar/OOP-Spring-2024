/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Keeping in mind our previous car example, write a class that represents a car, and use aggregation and composition to combine different components 
*                like engine, wheels, headlights and steering to create the car object.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Engine
{
    private:
        string modelName;
        int year;
        int horsepower;
    public:
        Engine(string modelName, int year, int horsepower)
        {
            this->modelName = modelName;
            this->horsepower = horsepower;
            this->year = year;
        }

        void setModelName(string modelName)
        {
            this->modelName = modelName;
        }

        void setYear(int year)
        {
            this->year = year;
        }

        void setHorsePower(int horsepower)
        {
            this->horsepower = horsepower;
        }

        void display()
        {
            cout << "\nEngine:\nModel Name: " << modelName << "\nYear of Manufacturing: " << year << "\nHorsepower: " << horsepower << "\n\n";
        }
};

class Wheels
{
    private:
        string brand;
        int size;

    public:
        Wheels(){}

        Wheels(string brand, int size)
        {
            this->brand = brand;
            this->size = size;
        }

        void setBrand(string brand)
        {
            this->brand = brand;
        }

        void setSize(int size)
        {
            this->size = size;
        }

        void display()
        {
            cout << "\nWheels:\nBrand: " << brand << "\nSize: " << size << "\n\n";
        }
};

class Headlights
{
    private:
        string type;
        string color;

    public:
        Headlights() {}

        Headlights(string type, string color)
        {
            this->type = type;
            this->color = color;
        }

        void setType(string type)
        {
            this->type = type;
        }

        void setLEDColor(string color)
        {
            this->color = color;
        }

        void display()
        {
            cout << "\nHeadlights:\nType: " << type << "\nColor: " << color << "\n\n";
        }
};

class Steering
{
    private:
        string type;
        string hornType;

    public:
        Steering(string type, string hornType)
        {
            this->type = type;
            this->hornType = hornType;
        }

        void setType(string type)
        {
            this->type = type;
        }

        void setHorntype(string hornType)
        {
            this->hornType = hornType;
        }

        void display()
        {
            cout << "\nSteering:\nType: " << type << "\nHorn Type: " << hornType << "\n\n";
        }
};

class Car
{
    private:
        Engine *e; //Aggregation used here, as 'Car' has Engine but Engine is independent
        Steering *steeringwheel; //Aggregation used here, as 'Car' has Steering but Steering is independent
        Wheels carWheels; //Composition used here as the Class 'Car' owns Wheels, as Car is in complete control over its creation and destruction
        Headlights carHeadlights; //Composition used here as the Class 'Car' owns Headlights, as Car is in complete control over its creation and destruction

        string carModel;
        int carId;
        float carPrice;
    public:        
        Car(string carModel, int carId, float carPrice, Engine *e, Steering *steeringwheel)
        {
            this->carModel = carModel;
            this->carId = carId;
            this->carPrice = carPrice;
            this->e = e;
            this->steeringwheel = steeringwheel;
            this->carWheels = Wheels("Yamaha", 38);
            this->carHeadlights = Headlights("LED", "Blue");
        }

        void displayCar()
        {
            cout << fixed << setprecision(2);
            cout << "Car Model Name: " << carModel;
            cout << "\nCar ID: " << carId;
            cout << "\nCar Price: " << carPrice << "\n";
            e->display();
            steeringwheel->display();
            carWheels.display();
            carHeadlights.display(); 
        }
};

int main()
{
    Engine engine1("Honda", 2017, 1500);
    Steering steeringwheel("Power Steering", "Loud");

    Car car1("Honda City", 56479, 390780.50, &engine1, &steeringwheel);
    car1.displayCar();

    return 0;
}