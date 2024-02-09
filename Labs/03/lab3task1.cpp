/*
*   Programmer: Ibrahim Johar Farooqi
*   Date: 9 February 2024
*/

#include <iostream>
#include <string>
using namespace std;

class BoardMarker
{
    private:
    string brand;
    string shade;
    bool refillable;
    bool inkstatus;

    public:
    void set_brand(string brandname)
    {
        brand = brandname;
    }
    void set_shade(string shadename)
    {
        shade = shadename;
    }
    void set_refill(bool refillstatus)
    {
        refillable = refillstatus;
    }
    void set_ink(bool ink)
    {
        inkstatus = ink;
    }

    string get_brand()
    {
        return brand;
    }
    string get_shade()
    {
        return shade;
    }
    bool get_refill()
    {
        return refillable;
    }
    bool get_ink()
    {
        return inkstatus;
    }

    void writemethod()
    {
        if (inkstatus == true)
        {
            cout << "Writing with " << brand << " marker in " << shade << " shade.\n";
        }
        else
        {
            cout << "Ink is finished. Please refill the marker.\n";
        }
    }

    void refillmethod()
    {
        if (refillable == true)
        {
            inkstatus = true;
            cout << "Marker refilled!\n";
        }
        else
        {
            cout << "This marker is not refillable.\n";
        }
    }

};

int main()
{
	BoardMarker marker;
	
    string brand;
    string shade;
	bool refill_status; 
    bool ink_status;
	
    cout << "Enter Brand: ";
	cin.ignore();
	getline(cin, brand);
	cout << "Enter Shade: ";
	getline(cin, shade);
	cout << "Enter refill status (true/false): ";
    cin >> boolalpha >> refill_status;
    cout << "Enter ink status (true/false): ";
    cin >> boolalpha >> ink_status;

    marker.set_brand(brand);
    marker.set_shade(shade);
    marker.set_refill(refill_status);
    marker.set_ink(ink_status);

	cout << "Brand: "<< marker.get_brand() << "\n";
	cout << "Shade: "<< marker.get_shade() << "\n";
	marker.writemethod();
    marker.refillmethod(); 

	return 0;
}
