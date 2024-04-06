/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 2
*/

#include <iostream>
#include <string>
using namespace std;

const int MAXWEAPONS = 10;

class Player
{
private:
    int playerID;
    string playerName;
    int health;
public:
    Player(int id, string name) : playerID(id), playerName(name), health(100) {}

    //getter and setter for health
    void setHealth(int h) { health = h; }
    int getHealth() const { return health; }
};

class Weapon
{
private:
    string weaponsList[MAXWEAPONS];
    int numWeapons;
public:
    Weapon(string wList[MAXWEAPONS], int num)
    {
        numWeapons = num;
        for (int i = 0; i < numWeapons; i++)
        {
            if (!wList[i].empty())
            {
                weaponsList[i] = wList[i];
            }
        }

        if (numWeapons < 5) //incase number of weapons are less than 5
        {
            cout << "List has to have at least 5 weapons. Default weapons will be used.\n";
            numWeapons = 5;
            weaponsList[0] = "Gun";
            weaponsList[1] = "Snipper";
            weaponsList[2] = "Bullet";
            weaponsList[3] = "Sword";
            weaponsList[4] = "Ray-Gun";
        }
    }

    void displayWeapons() const
    {
        cout << "Weapons List:\n";
        for (int i = 0; i < numWeapons; i++)
        {
            if (!weaponsList[i].empty())
            {
                cout << i + 1 << ". " << weaponsList[i] << "\n";
            }
        }
    }

    string use()
    {
        displayWeapons();

        int n;
        cout << "Which weapon would you like to use from the available list:";
        cin >> n;

        while (n < 1 || n > numWeapons || weaponsList[n - 1].empty())
        {
            cout << "Enter a valid weapon number!\n";
            cin >> n;
        }
        return weaponsList[n - 1];
    }
};

class Character : public Player
{
private:
    int level;
    string experience;
    int points;

public:
    Character(int id, string name) : level(0), experience("Beginner"), points(0), Player(id, name) {}

    void levelUp(int increment)
    {
        if (increment >= 10)
        {
            level++;
            if (experience == "Beginner")
            {
                experience = "Intermediate";
            }
            else if (experience == "Intermediate")
            {
                experience = "Advanced";
            }
            else if (experience == "Advanced")
            {
                experience = "Expert";
            }
        }
    }

    void playGame(Weapon w, Player &enemy); //declaration of playGame

    void addPoints(int p) { points += p; }

    //getters
    string getExperience() const { return experience; }
    int getPoints() const { return points; }
};

class Enemy : public Player
{
private:
    int damage;
public:
    Enemy(int id, string name, int d) : Player(id, name)
    {
        //validation
        if (d >= 1 && d <= 10) 
        {
            damage = d;
        }
        else
        {
            damage = 5;
        }
    }

    void attack(Weapon w, Character &player)
    {
        cout << "Enemy attacks!\n";
        string weapon = w.use();

        cout << "\nThe enemy used the " << weapon << " weapon to attack.\n";

        player.setHealth(player.getHealth() - damage);
    }
};

void Character::playGame(Weapon w, Player &enemy) //definition of playGame outside of Character class
{
    cout << "Character plays!\n";
    string weapon = w.use();

    cout << "\nPlayer used the " << weapon << " to attack the enemy and inflicted 5 points of damage.\n";
    enemy.setHealth(enemy.getHealth() - 5);

    levelUp(10);
    addPoints(10);
}

int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 2\n\n";

    string list[MAXWEAPONS] = {"ak47", "snipper", "rocketlauncher", "fireblaze", "ak243"};

    Weapon w(list, 5);

    Character ch1(3, "Ibrahim");
    Enemy enemy1(1, "Thanos", 15);

    //playthrough demonstration

    cout << "Character Experience: " << ch1.getExperience() << "\n";
    cout << "Character Points: " << ch1.getPoints() << "\n";
    cout << "Character Health: " << ch1.getHealth() << "\n\n";

    ch1.playGame(w, enemy1);
    cout << "Enemy Health: " << enemy1.getHealth() << "\n";
    cout << "Character Points: " << ch1.getPoints() << "\n";
    cout << "Character Experience: " << ch1.getExperience() << "\n\n";

    enemy1.attack(w, ch1);
    cout << "Character Experience: " << ch1.getExperience() << "\n";
    cout << "Character Points: " << ch1.getPoints() << "\n";
    cout << "Character Health: " << ch1.getHealth() << "\n\n";

    ch1.playGame(w, enemy1);
    cout << "Enemy Health: " << enemy1.getHealth() << "\n";
    cout << "Character Points: " << ch1.getPoints() << "\n";
    cout << "Character Experience: " << ch1.getExperience() << "\n\n";

    return 0;
}
