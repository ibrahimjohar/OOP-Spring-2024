/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 13 February 2024
*   Description: This Calendar class should possess 12 arrays, each representing a month of the year, along with a variable storing information about the current year.
*                Users can allocate tasks for each day, with one entry allowed per day.
*                Incorporate the following methods within this class:
*                    • Addition of a task: This function accepts task details, date, and month as parameters
*                    and adds the task to the specified day.
*                    • Removal of a task: Accepts the date and month as parameters to eliminate the task.
*                    • Display tasks: This method traverses through all months and prints the allocated
*                    tasks.
*                Instantiate a calendar object, input 5-6 tasks manually, demonstrate task removal, and display the updated task list.
*/
#include <iostream>
using namespace std;

class Calendar
{
    private:
        static const int months = 12;
        int currentyear;
        string tasks[months][31]; //array for storing tasks according to each day in a month
    public:
        //constructor for Calendar
        Calendar(int CurrentYear)
        {
            currentyear = CurrentYear;
        }

        //method definition to add tasks
        void addtask(int Date, int Month, string task)
        {
            if (Month >= 1 && Month <= months && Date >= 1 && Date <= 31) //check if the date user enters is valid
            {
                tasks[Month - 1][Date - 1] = task; //assign task in the array
                cout << "Task added on " << Date << "/" << Month << "/" << currentyear << "\n"; 
            }
            else
            {
                cout << "Invalid month or date inputted.\n";
            }
        }

        //method to remove a task from the array "tasks"
        void taskremoval(int Date, int Month)
        {
            if (Month >= 1 && Month <= months && Date >= 1 && Date <= 31) //check for date validity
            {
                tasks[Month - 1][Date - 1] = ""; //remove string stored at this array index
                cout << "Task on " << Date << "/" << Month << "/" << currentyear << " Removed\n"; 
            }
            else
            {
                cout << "Invalid month or date inputted.\n";
            }
        }

        //method to display all the tasks in that year
        void displaytasks()
        {
            cout << currentyear << " Tasks:\n";

            //i:month
            for (int i = 0; i < months; i++)
            {
                //j: day
                for (int j = 0; j < 31; j++)
                {
                    if (tasks[i][j] != "")//check for skipping indexes with no string stored
                    {
                        cout << i + 1 << "/" << j + 1 << "/" << currentyear << ": " << tasks[i][j] << "\n";
                    }
                }
            }
        }
};

int main()
{
    int year;
    cout << "Enter current year: ";
    cin >> year;

    Calendar newcalendar(year); //object declaration and constructor callout

    //manual inputs
    newcalendar.addtask(23,2,"Complete Lab Tasks");
    newcalendar.addtask(15,1,"Buy New Clothes");
    newcalendar.addtask(3,4,"Learn New Programming Language");
    newcalendar.addtask(19,3,"Study for Exam");
    newcalendar.addtask(30,8,"Play Outdoor Sports");

    //display all the added tasks
    newcalendar.displaytasks();

    //demonstration of removal of a task
    newcalendar.taskremoval(30,8);

    //display the updated task list
    newcalendar.displaytasks();

    return 0;
}
