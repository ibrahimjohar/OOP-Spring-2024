/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 3
*/

#include <iostream>
using namespace std;

class DarazPersonData
{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string zip;
        string phone;
    public:
        DarazPersonData(string last, string first, string add, string c, string s, string z, string p) :
            lastName(last), firstName(first), address(add), city(c), state(s), zip(z), phone(p)
                {}
        //getters
        string getLastName() const { return lastName; }
        string getFirstName() const { return firstName; }
        string getAddress() const { return address; }
        string getCity() const { return city; }
        string getState() const { return state; }
        string getZip() const { return zip; }
        string getPhone() const { return phone; }

        //setters
        void setLastName(string last) { lastName = last;}
        void setFirstName(string first) { firstName = first; }
        void setAddress(string addr) { address = addr; }
        void setCity(string c) { city = c; }
        void setState(string s) { state = s; }
        void setZip(string z) { zip = z; }
        void setPhone(string ph) { phone = ph; }
};

class DarazCustomerData : public DarazPersonData
{
    private:
        int customerNumber;
        int loyaltyPoints;
        static int totalCustomers;
    public:
        DarazCustomerData(string last, string first, string add, string c, string s, string z, string p) :
            DarazPersonData(first, last, add, c, s, z, p), customerNumber(totalCustomers++), loyaltyPoints(0) {}

        //getters
        int getCustomerNumber() const { return customerNumber; }
        int getLoyaltyPoints() const { return loyaltyPoints; }

        //setters
        void setCustomerNumber(int number) { customerNumber = number; }
        void setLoyaltyPoints(int points) { loyaltyPoints = points; }
};

int DarazCustomerData::totalCustomers = 0; //initialisation of static member

class DarazLoyaltyProgram
{
    private:
        DarazCustomerData *customer;
    public:
        DarazLoyaltyProgram(DarazCustomerData *customer1) : 
            customer(customer1) {}
        
        void addLoyaltyPoints(int pts)
        {
            customer->setLoyaltyPoints(customer->getLoyaltyPoints() + pts);
        }

        void redeemLoyaltyPoints(int pts, double itemprice)
        {
            int loyaltyPoints = customer->getLoyaltyPoints();

            if (loyaltyPoints - pts >= 0 && pts >= 0)
            {
                double discount = itemprice * 0.75; 
                cout << "Discounted Price: $" << discount << "\n";
                customer->setLoyaltyPoints(loyaltyPoints - pts);
            }
            else
            {
                cout << "Negative or invalid points input. Points Redemption not possible.\n";
            }
        }

        void dipslayLoyaltyPoints()
        {
            cout << "Total Loyalty Points: " << customer->getLoyaltyPoints() << "\n";
        }

};

void printCustomerInfo(DarazCustomerData customer)
{
    cout << "Customer ID: " << customer.getCustomerNumber() << "\n";
    cout << "Name: " << customer.getFirstName() + " " + customer.getLastName() << "\n";
    cout << "Address: " << customer.getAddress() << "\n";
    cout << "City: " << customer.getCity() << "\n";
    cout << "Phone: " << customer.getPhone() << "\n";
    cout << "Zip: " << customer.getZip() << "\n";
    cout << "State: " << customer.getState() << "\n";
}

int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 3\n\n";
    double itemprice;
    int loyaltyPoints;

    DarazCustomerData customer1("Ibrahim", "Johar", "Malir", "Karachi", "Sindh", "75090", "0300214579");

    printCustomerInfo(customer1);

    DarazLoyaltyProgram loyaltyprogram1(&customer1);

    loyaltyprogram1.addLoyaltyPoints(100);

    loyaltyprogram1.dipslayLoyaltyPoints();

    cout << "Enter item price: $";
    cin >> itemprice;

    cout << "Enter number of points to redeem: ";
    cin >> loyaltyPoints;

    loyaltyprogram1.redeemLoyaltyPoints(loyaltyPoints, itemprice);

    return 0;
}
