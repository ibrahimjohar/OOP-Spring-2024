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
    string getCompany()
    {
        return company;
    }

    string getColor()
    {
        return color;
    }

    double getCapacityLiters()
    {
        return capacityLiters;
    }

    double getCapacityMilliliters()
    {
        return capacityMilliliters;
    }

    void setCompany(string companyName)
    {
        company = companyName;
    }

    void setColor(string bottleColor)
    {
        color = bottleColor;
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
            cout << "Consumed amount exceeds available water capacity.\n";
        }
    }
};

int main()
{
    WaterBottle bottle;
    bottle.setCompany("ABC Company");
    bottle.setColor("Blue");

    bottle.setCapacityMilliliters(1500);
    bottle.setCapacityLiters(1.5);

    cout << "Water Bottle Information:\n";
    cout << "Company: " << bottle.getCompany() << "\n";
    cout << "Color: " << bottle.getColor() << "\n";
    cout << "Capacity (Liters): " << bottle.getCapacityLiters() << " L\n";
    cout << "Capacity (Milliliters): " << bottle.getCapacityMilliliters() << " ml\n\n";

    bottle.updateWaterCapacity(300);

    cout << "After consuming 300 ml of water:\n";
    cout << "Remaining Capacity (Liters): " << bottle.getCapacityLiters() << " L\n";
    cout << "Remaining Capacity (Milliliters): " << bottle.getCapacityMilliliters() << " ml\n";

    return 0;
}
