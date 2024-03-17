/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 17 March 2024
*   Description: You have been hired to develop a program for a hair salon that keeps track of appointments made, total earnings, and the average cost per appointment using
*                static members and functions. Your task is to define a class that represents an appointment at the salon. The class should have private data members that 
*                store information about the appointment, and static data members that keep track of the total number of appointments made and the total earnings from all appointments.
*/

#include <iostream>
using namespace std;

class Appointment
{
    private:
        string customername;
        string dateOfAppointment;
        double fee;
        static int totalAppointments;
        static double totalEarnings;
    public:
        //constructor
        Appointment(string customername, string dateOfAppointment, double fee)
        {
            this->customername = customername;
            this->dateOfAppointment = dateOfAppointment;
            this->fee = fee;
            totalAppointments++;
            totalEarnings += fee;
        }

        //setters and getters
        void setName(string customername)
        {
            this->customername = customername;
        }
        string getName()
        {
            return customername;
        }
        void setDate(string dateOfAppointment)
        {
            this->dateOfAppointment = dateOfAppointment;
        }
        string getDate()
        {
            return dateOfAppointment;
        }
        void setFee(double fee)
        {
            this->fee = fee;
        }
        double getFee()
        {
            return fee;
        }
        static int getTotalAppointments()
        {
            return totalAppointments;
        }
        static double getTotalEarnings()
        {
            return totalEarnings;
        }
        static double AverageCost() //static function to calculate average cost of all appointments
        {
            double avgCost;
            avgCost = static_cast<double>(totalEarnings) / static_cast<double>(totalAppointments);
            return avgCost;
        }
};

//initialization of static data members of the class
int Appointment::totalAppointments = 0;
double Appointment::totalEarnings = 0.0;

int main()
{
    double averageCost;
    class Appointment app1("Ali", "23 Mar 2024", 53.64);
    cout << "Hair Salon - Appointment Tracker\n\n";
    cout << "Customer Name: " << app1.getName() << "\n";
    cout << "Appointment Date: " << app1.getDate() << "\n";
    cout << "Appointment Fee: $" << app1.getFee() << "\n";
    cout << "Total Appointments: " << app1.getTotalAppointments() << "\n";
    cout << "Total Earnings: $" << app1.getTotalEarnings() << "\n";
    averageCost = app1.AverageCost();
    cout << "Average Cost of all appoinments: $" << averageCost << "\n\n";


    class Appointment app2("Jamshed", "25 Mar 2024", 38.4);
    cout << "Customer Name: " << app2.getName() << "\n";
    cout << "Appointment Date: " << app2.getDate() << "\n";
    cout << "Appointment Fee: $" << app2.getFee() << "\n";
    cout << "Total Appointments: " << app2.getTotalAppointments() << "\n";
    cout << "Total Earnings: $" << app2.getTotalEarnings() << "\n";
    averageCost = app2.AverageCost();
    cout << "Average Cost of all appoinments: $" << averageCost << "\n\n";


    class Appointment app3("Colin Munro", "28 Mar 2024", 62.25);
    cout << "Customer Name: " << app3.getName() << "\n";
    cout << "Appointment Date: " << app3.getDate() << "\n";
    cout << "Appointment Fee: $" << app3.getFee() << "\n";
    cout << "Total Appointments: " << app3.getTotalAppointments() << "\n";
    cout << "Total Earnings: $" << app3.getTotalEarnings() << "\n";
    averageCost = app3.AverageCost();
    cout << "Average Cost of all appoinments: $" << averageCost << "\n\n";    

    return 0;
}
