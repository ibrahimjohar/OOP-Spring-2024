/*
*   Programmer: Ibrahim Johar Farooqi
*   Date: 9 February 2024
*/

#include <iostream>
#include <string>
using namespace std;

class WaterBottle
{
    private:
        string company;
        string color;
        double capacityLiters;
        double capacityMilliliters;

    public:
        string get_company()
        {
            return company;
        }

        string get_color()
        {
            return color;
        }

        double get_capacityLiters()
        {
            return capacityLiters;
        }

        double get_capacityMilliliters()
        {
            return capacityMilliliters;
        }

        void set_company(string companyName)
        {
            company = companyName;
        }

        void set_color(string bottleColor)
        {
            color = bottleColor;
        }

        void set_capacityMilliliters(double capacityInMilliliters)
        {
            capacityMilliliters = capacityInMilliliters;
            capacityLiters = capacityMilliliters / 1000.0;
        }

        void set_capacityLiters(double capacityInLiters)
        {
            capacityLiters = capacityInLiters;
            capacityMilliliters = capacityLiters * 1000.0;
        }

        void updateWaterCapacity(double consumedMilliliters)
        {
            if (consumedMilliliters <= capacityMilliliters)
            {
                capacityMilliliters -= consumedMilliliters;
                capacityLiters = capacityMilliliters / 1000.0;
            }
            else
            {
                cout << "Consumed amount exceeds available water capacity, cannot update water capacity.\n";
            }
        }
};


int main()
{
    string company;
    string color;
    double capacityLiters;
    double capacityMilliliters;
    double water_consumed;
    
    WaterBottle bottle;

    cout << "Enter manufacturer company: ";
    getline(cin, company);
    
    cout << "Enter color: ";
    getline(cin, color);

    cout << "Enter capacity in litres: ";
    cin >> capacityLiters;

    cout << "Enter capacity in milliliters: ";
    cin >> capacityMilliliters;

    bottle.set_company(company);
    bottle.set_color(color);
    bottle.set_capacityLiters(capacityLiters);
    bottle.set_capacityMilliliters(capacityMilliliters);

    cout << "\nWater Bottle Information:\n";
    cout << "Company: " << bottle.get_company() << "\n";
    cout << "Color: " << bottle.get_color() << "\n";
    cout << "Capacity (Liters): " << bottle.get_capacityLiters() << " L\n";
    cout << "Capacity (Milliliters): " << bottle.get_capacityMilliliters() << " ml\n\n";

    cout << "Enter amount of water consumed: ";
    cin >> water_consumed;

    bottle.updateWaterCapacity(water_consumed);

    cout << "\nRemaining Capacity (Liters): " << bottle.get_capacityLiters() << " L\n";
    cout << "Remaining Capacity (Milliliters): " << bottle.get_capacityMilliliters() << " ml\n";

    return 0;
}
