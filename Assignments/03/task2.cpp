/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 2
*/

#include <iostream>
using namespace std;

template <class T1, class T2>
class Pet
{
    protected:
        string name;
        int age;
    public:
        Pet(string n, int a) : name(n), age(a) {}

        virtual void makeSound() = 0;

        virtual void display() const
        {
            cout << "Pet Name: " << name << "\n";
            cout << "Pet Age: " << age << " Years\n";
        }
};

class Cat : public Pet<string, int>
{
    public:
        Cat(string n, int a) : Pet<string, int>(n, a) {}

        void makeSound() { cout << "Meow!\n\n"; }

        void display() const
        {
            cout << "Cat.\n";
            Pet::display();
        }
};

class Dog : public Pet<string, int>
{
    public:
        Dog(string n, int a) : Pet<string, int>(n, a) {}

        void makeSound() { cout << "Woof!\n\n"; }

        void display() const
        {
            cout << "Dog.\n";
            Pet::display();
        }
};

class Bird : public Pet<string, int>
{
    public:
        Bird(string n, int a) : Pet<string, int>(n, a) {}

        void makeSound() { cout << "Chirp!\n\n"; }

        void display() const
        {
            cout << "Bird.\n";
            Pet::display();
        }
};


int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 2\n\n";

    Cat cat1("Noah", 3);
    Dog dog1("Pluto", 4);
    Bird bird1("Birdie", 1);

    Pet <string, int> *petPtr;

    petPtr = &cat1;
    petPtr->display();
    petPtr->makeSound();

    petPtr = &dog1;
    petPtr->display();
    petPtr->makeSound();

    petPtr = &bird1;
    petPtr->display();
    petPtr->makeSound();

    return 0;
}
