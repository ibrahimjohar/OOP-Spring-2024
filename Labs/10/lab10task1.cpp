/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 18 April 2024
*   Description: Elon Musk wants to change the logo of twitter from the blue bird to doge coin but wants to keep everything on twitter the same.
*                Create three classes Logo, Platform and Server with the attributes of your choice (Keep the Logo attribute private and
*                string) and change the logo attribute via the friend keyword. Use the display function to display the parameters twice 
*                (once with the original logo and the other with the modified one)
*/

#include <iostream>
#include <string>
using namespace std;

class Platform;
class Server;

class Logo
{
private:
    string logoName;

public:
    Logo(string l = "Default Logo") : logoName(l) {}

    Logo(const Logo &other) : logoName(other.logoName) {}

    void display() const
    {
        cout << "Logo Name: " << logoName << "\n";
    }

    friend void changeLogo(Platform &platform, const Logo &newLogo);
};

class Server
{
private:
    string ipAddress;

public:
    Server(string ip = "127.0.0.1") : ipAddress(ip) {}

    void display() const
    {
        cout << "IP Address: " << ipAddress << "\n";
    }
};

class Platform
{
private:
    string platformName;
    Logo mainLogo;
    Server server1;

public:
    Platform(string name, string name_Logo, string addIP)
        : platformName(name), mainLogo(name_Logo), server1(addIP) {}

    void display() const
    {
        cout << "Platform name: " << platformName << "\n";
        mainLogo.display();
        server1.display();
    }

    void setMainLogo(const Logo &logo)
    {
        mainLogo = logo;
    }
};

void changeLogo(Platform &platform, const Logo &newLogo)
{
    platform.setMainLogo(newLogo);
}



int main()
{
    Platform twitter("Twitter", "Blue Bird", "192.168.25.5");

    twitter.display();

    Logo dogecoin("Dogecoin");
    changeLogo(twitter, dogecoin);

    cout << "\nAfter Logo Change:\n";
    twitter.display();

    return 0;
}
