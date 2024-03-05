/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 15 February 2024
*   Description: Develop a class called WeekDays containing private data members - a string array named Days for the days of the week and an integer variable named CurrentDay
*                for the current day. Create the following constructors and member functions for the class: a Default Constructor initializing
*                the Days array from Sunday to Saturday, a Parameterized Constructor accepting an integer value for CurrentDay, 
*                performing a modulus operation to adjust if the value exceeds 6, and initializing the Days array accordingly.
*                Additional member functions include getCurrentDay, getNextDay, getPreviousDay, and getNthDayFromToday.
*/

#include <iostream>
#include <string>
using namespace std;

class WeekDays
{
    private:
        string Days[7];
        int CurrentDay;
    public:
        WeekDays()
        {
            Days[0] = "Sunday";
            Days[1] = "Monday";
            Days[2] = "Tuesday";
            Days[3] = "Wednesday";
            Days[4] = "Thursday";
            Days[5] = "Friday";
            Days[6] = "Saturday";
            CurrentDay = 0;
        }

        WeekDays(int c_day)
        {
            Days[0] = "Sunday";
            Days[1] = "Monday";
            Days[2] = "Tuesday";
            Days[3] = "Wednesday";
            Days[4] = "Thursday";
            Days[5] = "Friday";
            Days[6] = "Saturday";
            CurrentDay = c_day % 7;
        }

        string getCurrentDay() const
        {
            return Days[CurrentDay];
        }

        string getNextDay()
        {
            return Days[(CurrentDay + 1) % 7];
        }

        string getPreviousDay()
        {
            return Days[(CurrentDay + 6) % 7];
        }

        string getNthDayFromToday(int n)
        {
            return Days[(CurrentDay + n) % 7];
        }

};

int main()
{
    int c_day;
    cout << "Enter Current Day #: ";
    cin >> c_day; 
    WeekDays thisWeek(c_day);

    cout << "Current Day is: " << thisWeek.getCurrentDay() << "\n";
    cout << "Next Day is: " << thisWeek.getNextDay() << "\n";
    cout << "Previous Day was: " << thisWeek.getPreviousDay() << "\n";
    cout << "3 Days from today will be: " << thisWeek.getNthDayFromToday(3) << "\n";
}