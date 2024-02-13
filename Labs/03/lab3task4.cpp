/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 13 February 2024
*   Description: Forge a class labelled "Smartphone" possessing the following attributes:
*                    • Brand
*                    • Model
*                    • Display Resolution
*                    • RAM
*                    • ROM
*                    • Storage
*                Develop getter and setter methods for these attributes. Additionally, define specific actions smartphones can perform, such as:
*                    • Making phone calls
*                    • Sending messages
*                    • Connecting to Wi-Fi
*                    • Browsing the internet
*                Create distinct smartphone objects, set their attributes using setter functions, and exhibit their attributes after retrieving them using getter functions.
*/

#include <iostream>
#include <string>
using namespace std;

class Smartphone
{
    private:
        string Brand;
        string Model;
        string DispResolution;
        int RAM;
        int ROM;
        int Storage;
    public:
        //setters
        void set_brand(string brand)
        {
            Brand = brand;
        }
        void set_model(string model)
        {
            Model = model;
        }
        void set_resolution(string resolution)
        {
            DispResolution = resolution;
        }
        void set_ram(int ram)
        {
            RAM = ram;
        }
        void set_rom(int rom)
        {
            ROM = rom;
        }
        void set_storage(int storage)
        {
            Storage = storage;
        } 

        //getters
        string get_brand()
        {
            return Brand;
        }
        string get_model()
        {
            return Model;
        }
        string get_resolution()
        {
            return DispResolution;
        }
        int get_ram()
        {
            return RAM;
        }
        int get_rom()
        {
            return ROM;
        }
        int get_storage()
        {
            return Storage;
        }   

        //action methods
        void MakePhoneCall(string phone_num)
        {
            cout << Model << " is dialling a call to " << phone_num << "...\n";
        }
        void SendMsg(string receiver, string msg)
        {
            cout << Model << " is sending the following text message: '" << msg << "' to " << receiver << "\n";
        }
        void ConnectingToWifi(string networkname)
        {
            cout << Brand << " " << Model << " is connecting to " << networkname << " network\n"; 
        }
        void BrowsingtheInternet()
        {
            cout << Model << " is now browsing the internet...\n"; 
        }

};

int main()
{
    //object declarations
    Smartphone smartphone1;
    Smartphone smartphone2;

    //setting attributes of smartphone1 using setters
    smartphone1.set_brand("Apple");
    smartphone1.set_model("iPhone 11");
    smartphone1.set_resolution("1170x2532");
    smartphone1.set_ram(4);
    smartphone1.set_rom(8);
    smartphone1.set_storage(128);

    //setting attributes of smartphone2 using setters
    smartphone2.set_brand("Samsung");
    smartphone2.set_model("S24 Ultra");
    smartphone2.set_resolution("2400x1200");
    smartphone2.set_ram(12);
    smartphone2.set_rom(16);
    smartphone2.set_storage(256);

    //displaying attributes of smartphone1 using getters
    cout << "Smartphone 1 Specifications: \n";
    cout << "Brand: " << smartphone1.get_brand() << "\n";
    cout << "Model: " << smartphone1.get_model() << "\n";
    cout << "Display Resolution: " << smartphone1.get_resolution() << "\n";
    cout << "RAM: " << smartphone1.get_ram() << "GB\n";
    cout << "ROM: " << smartphone1.get_rom() << "GB\n";
    cout << "Storage: " << smartphone1.get_storage() << "GB\n";
    cout << "\n";

    //displaying actions of smartphone1
    smartphone1.ConnectingToWifi("PTCL");
    smartphone1.MakePhoneCall("0300-2173318");
    smartphone1.SendMsg("Ahmed", "When are you free today?");
    smartphone1.BrowsingtheInternet();
    cout << "\n";

    //displaying attributes of smartphone2 using getters
    cout << "Smartphone 2 Specifications: \n";
    cout << "Brand: " << smartphone2.get_brand() << "\n";
    cout << "Model: " << smartphone2.get_model() << "\n";
    cout << "Display Resolution: " << smartphone2.get_resolution() << "\n";
    cout << "RAM: " << smartphone2.get_ram() << "GB\n";
    cout << "ROM: " << smartphone2.get_rom() << "GB\n";
    cout << "Storage: " << smartphone2.get_storage() << "GB\n";
    cout << "\n";

    //displaying actions of smartphone2
    smartphone2.ConnectingToWifi("TP-Link");
    smartphone2.MakePhoneCall("0300-2345642");
    smartphone2.SendMsg("Frank", "Have you done your assignment?");
    smartphone2.BrowsingtheInternet();
    cout << "\n";

    return 0;
}
