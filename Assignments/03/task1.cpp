/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 1
*/

#include <iostream>
using namespace std;

class Medicine
{
    private:
        string name;
        string formula;
        string manufactureDate;
        string expirationDate;
        double retailPrice;
    public:
        Medicine(string n, string f, string mD, string eD, double price):
            name(n), formula(f), manufactureDate(mD), expirationDate(eD), 
            retailPrice(price) {}

        //setters
        void setName(string newName); 
        void setFormula(string newFormula); 
        void setManufactureDate(string mD); 
        void setExpirationDate(string eD); 
        void setRetailPrice(double newPrice); 
        //getters
        string getName() const;
        string getFormula() const;
        string getManufactureDate() const;
        string getExpirationDate() const; 
        double getRetailPrice() const; 

        virtual void printDetails() {}

        bool operator == (const Medicine &medicine) 
        {
            return medicine.expirationDate == expirationDate;
        }
};

class Tablet: public Medicine 
{
    private:
        double sucroseLevel;
    public:
        Tablet(int sLevel, string n, string f, string mD, string eD, double price):
            Medicine(n, f, mD, eD, price) 
        {
            if (sLevel >= 0 && sLevel <= 1) { sucroseLevel = sLevel; }
            else { cout << "Sucrose Level should be in the range of 0 and 1.\n"; }
        }

        void setSucroseLevel(double sL);
        double getSucroseLevel() const;

        void printDetails() override {}
};

class Capsule: public Medicine
{
    private:
        double absorptionPercentage;
    public:
        Capsule(double aP, string n, string f, string mD, string eD, double price):
            Medicine(n, f, mD, eD, price)
        {
            if (aP >= 0 && aP <= 100) { absorptionPercentage = aP; }
            else { cout << "Percentage absorption should in the range of 0 and 1.\n"; }
        }

        void setAbsorptionPercentage(double aP);
        double getAbsorptionPercentage() const;

        void printDetails() override {}
};

class Syrup : public Medicine
{
    private:
        double volume;
    public:
        Syrup(double vol, string n, string f, string mD, string eD, double price):
            Medicine(n, f, mD, eD, price), volume(vol) {}

        void setVolume(double v);
        double getVolume() const;
        
        void printDetails() override {}
};

//global medicine list to search against in the Pharmacist and Counter class
int medicine_count = 4;
Medicine *medicineList[] = 
{
    new Tablet(0.5f, "Panadol", "Formula 098", "25-10-23", "25-10-27", 25.8f),
    new Capsule(67.f, "Vitamin D Suppliment", "Formula 0963", "12-08-15", "12-08-25", 6.2f),
    new Syrup(15.f, "Calpol", "Formula 0241", "04-02-2021", "10-02-2023", 12.7f),
    new Capsule(54.f, "Multi-Vitamin Suppliment", "Formula 023", "09-09-18", "09-09-21", 7.8f)
};

class Pharmacist
{
    public:
        void Search_Medicine(Medicine *m, string formula_Med); //search medicine by formula
};

class Counter
{
    private:
        double revenue;
    public:
        Counter(double r) : revenue(r) {}
        
        void Search_Medicine(Medicine *m, string name_Med); //search medicine by name

        void Update_Revenue(double newRevenue);
};
