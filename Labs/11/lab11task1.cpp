/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 29 April 2024
*   Description: Your task is to create a C++ program that facilitates unit conversions commonly used in the lab. The program should be able to convert between
*                different units such as liters to gallons and Fahrenheit to Celsius.
*/

#include <iostream>
using namespace std;

class convert
{
    protected:
        double val1, val2;
    public:
        convert(double v) : val1(v), val2(0) {}
        virtual void compute() = 0; 
        double getConvertedValue() const { return val2; }
};

class l_to_g : public convert
{
    public:
        l_to_g(double val) : convert(val) {}

        void compute() override 
        {
            val2 = val1 * 0.264172; //1 ltr is approx 0.264172 gallons
        }
};

class f_to_c : public convert
{
    public:
        f_to_c(double val) : convert(val) {}

        void compute() override
        {
            val2 = (val1 - 32) * 5 / 9; //conversion for Fahrenheit to Celsius
        }
};

int main()
{
    convert *converterPtr;

    converterPtr = new l_to_g(4); 
    converterPtr->compute();
    cout << "4 Liters : " << converterPtr->getConvertedValue() << " Gallons.\n";

    converterPtr = new f_to_c(70); 
    converterPtr->compute(); 
    cout << "70 Fahrenheit : " << converterPtr->getConvertedValue() << " degrees Celsius.\n";

    delete converterPtr;

    return 0;
}
