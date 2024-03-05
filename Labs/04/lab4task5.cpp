/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 15 February 2024
*   Description: Transform the Office class by replacing the furniture array with a pointer. Modify the constructor to accept the size of the 
*                furniture array instead of the array itself, dynamically allocating memory for the furniture array within the constructor.
*                Implement a destructor to deallocate memory allocated for the furniture pointer. 
*                In the main function, dynamically allocate an Office object, pass required values to the constructor, and then delete the dynamically
*                allocated object to ensure proper invocation of the destructor.
*/

#include <iostream>
using namespace std;

class Office 
{
    private:
        string Location;
        int SeatingCapacity;
        string *Furniture;
    public:
        Office(string location = " ", int seatingcap = 0, int size = 0): Location(location), SeatingCapacity(seatingcap), Furniture(new string[size])
        {} //constructor using a member initialization list

        ~Office() //destructor
        {
            delete[] Furniture;
            cout << "Furniture has now been delted." << "\n";
        }
};

int main()
{
    Office *office1 = new Office("Saddar", 50, 4);

    delete office1; //free dynamically allocated memory

    return 0;
}