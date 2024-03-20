/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 19 March 2024
*   Description: Suppose you are developing a game that has different types of characters. You have a base
*                class called "Character" which has attributes like health and damage. Now, you want to
*                create two derived classes - "Enemy" and "Player" - which inherit from the "Character"
*                class. Further, you want to create another class called "Wizard" which inherits from the
*                "Player" class and has additional attributes like magic power and spells.
*/

#include <iostream>
using namespace std;

class Character
{
    private:
        int health;
        int damage;
    public:
        Character(int h, int d): health(h), damage(d) {}

        void display()
        {
            cout << "Health: " << health << "\n";
            cout << "Damage: " << damage << "\n\n";
        }
};

class Enemy : public Character
{
    public:
        Enemy(int h, int d) : Character(h, d) {}

        void display()
        {
            cout << "Enemy Details:\n";
            Character::display();
        }
};

class Player : public Character
{
    public: 
        Player(int h, int d) : Character(h, d) {}

        void display()
        {
            cout << "Player Details:\n";
            Character::display();
        }
};

class Wizard : public Player
{
    private:
        int magicPower;
        string spells;
    public:
        Wizard(int mp, string s, int h, int d) : magicPower(mp), spells(s), Player(h, d) {}

        void display()
        {
            cout << "Wizard Details:\n\n";
            Player::display();
            cout << "Magic Power: " << magicPower << "\n";
            cout << "Spells: " << spells << "\n\n";
        }  
};


int main()
{
    Wizard wizardOZ(80, "Disappearing Cloak", 87, 13);

    wizardOZ.display();

    return 0;
}