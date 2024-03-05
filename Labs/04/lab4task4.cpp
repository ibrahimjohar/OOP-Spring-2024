/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 15 February 2024
*   Description: Instantiate a class named Office to represent attributes of an office space, including Location
*                (default value: " "), SeatingCapacity (default value: 0), and Furniture (a string array with a size of 3, default: {"", "", ""}). 
*                Implement a parameterized constructor assigning default values to all attributes using a member initialization list. 
*                Create multiple instances of the Office class using different numbers of constructor arguments.
*/

#include <iostream>
using namespace std;

class Office 
{
    private:
        string Location;
        int SeatingCapacity;
        string Furniture[3];
    public:
        Office(string location = " ", int seatingcap = 0, string furniture1 = "", string furniture2 = "", string furniture3 = ""):
            Location(location), SeatingCapacity(seatingcap)
        {
            Furniture[0] = furniture1;
            Furniture[1] = furniture2;
            Furniture[2] = furniture3;
        }

        void display()
        {
            cout << "Location: " << Location << "\n";
            cout << "Seating Capacity: " << SeatingCapacity << "\n";
            cout << "Furniture: (" << Furniture[0] << "," << Furniture[1] << "," << Furniture[2] <<")\n";
        }

};

int main()
{
    Office office1("Malir");
    Office office2("PakTower", 30);
    Office office3("Saddar", 45, "Chairs", "Tables", "Sofas");

    cout << "Office 1 (1 argument): \n";
    office1.display();
    cout << "\n";

    cout << "Office 2 (2 arguments): \n";
    office2.display();
    cout << "\n";

    cout << "Office 3 (3 arguments): \n";
    office3.display();
    cout << "\n";
}