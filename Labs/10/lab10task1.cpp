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










/*
class Base{
    public:
        int a;
        Base() {}
        Base(int x){
            a = x;
        }

        Base operator+ (Base obj)
        {
            Base obj2;
            obj2 = obj.a + a;
            return obj2;
        }

        void display()
        {
            cout << "The value is " << a << "\n";
        }
};

int main()
{
    Base b1(10), b2(20);
    Base b3;
    b3 = b1 + b2;
    b3.display();
    return 0;
}*/















/*
class Box
{
    double width;

    public:
        friend void printWidth(Box box);
        void setWidth(double width);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    cout << "Width of box: " << box.width << "\n";
}

int main()
{
    Box box1;
    box1.setWidth(19.7);
    printWidth(box1);

    return 0;
}*/






/*class AS
{
    private:
        int a = 15;
        friend void func(int x, AS* obj);
    public:
        void print()
        {
            cout << a << "\n";    
        }
        
};

void func(int x, AS* obj)
{
    obj->a = x;
}

int main()
{
    AS obj;
    obj.print();

    func(25, &obj);
    obj.print();
    return 0;
}
*/
