/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 28 March 2024
*   Description: You are tasked with creating a payroll management system for a small company. The system
*                needs to handle two types of employees: full-time employees and part-time employees. Each
*                type of employee has different attributes and methods associated with them. Full-time
*                employees receive a fixed salary per month, while part-time employees are paid based on the
*                number of hours they work.
*/

#include <iostream>
using namespace std;

class Employee
{
    protected:
        string employeeID, employeeName;
    public:
        Employee(string id, string name) : employeeID(id), employeeName(name) {}

        virtual double calculatePay() const
        {
            return 0.0;
        }
        virtual void displayDetails()
        {
            cout << "Employee ID: " << employeeID << "\n";
            cout << "Employee Name: " << employeeName << "\n";
        }

};

class FullTimeEmployee : public Employee
{
    private:
        double monthlySalary;
    public:
        FullTimeEmployee(string id, string name, double salary) : 
            monthlySalary(salary), Employee(id, name) {}
        
        double calculatePay() const
        {
            return monthlySalary;
        }

        void displayDetails() const 
        {
            cout << "Employee ID: " << employeeID << "\n";
            cout << "Employee Name: " << employeeName << "\n";
            cout << "Monthly Salary: $" << monthlySalary << "\n";
        }
};

class PartTimeEmployee : public Employee
{
    private:
        double hourlyWage;
        int nHours;
    public:
        PartTimeEmployee(string id, string name, double hourly, int hrs) : 
            hourlyWage(hourly), nHours(hrs), Employee(id, name) {}
        
        double calculatePay() const
        {
            return hourlyWage * nHours;
        }

        void displayDetails() const 
        {
            cout << "Employee ID: " << employeeID << "\n";
            cout << "Employee Name: " << employeeName << "\n";
            cout << "Hourly Wage: $" << hourlyWage << "\n";
            cout << "Hours Worked: " << nHours << "\n";
        }
        
};

int main()
{
    FullTimeEmployee full_Emp1("23K-0074", "Ibrahim Johar", 5000.0);
    PartTimeEmployee part_Emp1("23K-0007", "Mark", 25.0, 45);

    Employee *employeePtr;
    employeePtr = &full_Emp1;

    cout << "Full Time Employee Details:\n";
    full_Emp1.displayDetails();
    cout << "Full Time Employee Pay: " << full_Emp1.calculatePay() << "\n\n";

    cout << "Part Time Employee Details:\n";
    part_Emp1.displayDetails();
    cout << "Part Time Employee Pay: " << part_Emp1.calculatePay() << "\n\n";

    cout << "Using base class pointer for Full-Time Employee:" << "\n";
    cout << "Pay: $" << employeePtr->calculatePay() << "\n\n";

    employeePtr = &part_Emp1;

    cout << "Using base class pointer for Part-Time Employee:" << "\n";
    cout << "Pay: $" << employeePtr->calculatePay() << "\n";

    return 0;
}