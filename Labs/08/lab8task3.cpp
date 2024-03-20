/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 19 March 2024
*   Description: Suppose you are developing a game engine that involves a variety of game objects, such as
*                characters, enemies, and items. You want to implement a system to keep track of the position
*                of these objects in 3D space, as well as their health status.
*/

#include <iostream>
using namespace std;

class Position
{
    private:
        int x, y ,z;
    public:
        Position(int X, int Y, int Z) : x(X), y(Y), z(Z) {}

        void display()
        {
            cout << "Position: \n";
            cout << "X: " << x << "\n";
            cout << "Y: " << y << "\n";
            cout << "Z: " << z << "\n";
        }
};

class Health
{
    private:
        int health;
    public:
        Health(int h) : health(h) {}

        void display()
        {
            cout << "Health: " << health << "\n";
        }
};

class Character : public Position, public Health
{
    private:
        string name;
        int power;
    public:
        Character(string n, int p, int X, int Y, int Z, int h) :
            name(n), power(p), Position(X, Y, Z), Health(h) {}

        void MoveForward()
        {
            cout << name << " moves forward one level!\n";
        }

        void PowerUp()
        {
            cout << name << " power increased by 5 pts.\n";
            power += 5;
            cout << "Power Level Now: " << power << "\n";
        }

        void display()
        {
            cout << "Name: " << name << "\n";
            Position::display();
            Health::display();
            cout << "Power: " << power << "\n";
        }
};

int main()
{
    Character brock("Lesnar", 250, 5, 4, 7, 97);

    brock.display();
    brock.MoveForward();
    brock.PowerUp();

    cout << "After power up:\n\n";
    brock.display();

    return 0;
}