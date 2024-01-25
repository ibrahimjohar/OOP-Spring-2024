/*
*   Name: Ibrahim Johar Farooqi
*   Date: 25 Jan 2024
*   Description: Design a C++ program to manage student marks. Allow the user to input marks for students in three subjects (Mathematics, English, and Science). The program should calculate
                 the total marks, average marks, and display the grade for each student. The user can specify the number of students and then input the marks for each subject for
                 each student. Finally, display the marks, total, average, and grade for each student. Assume a grading system with the following criteria:
                 90 or above: Grade A
                 80-89: Grade B
                 70-79: Grade C
                 60-69: Grade D
                 Below 60: Grade F
*/

#include <iostream>
using namespace std;

int main()
{
    int numstd, total, math, eng, sci;
    float avg;
    cout << "Enter number of students:";
    cin >> numstd;

    for (int i = 0; i < numstd; i++)
    {
        cout << "Student " << i+1 << endl;
        cout << "Mathematics Marks: ";
        cin >> math;
        cout << "English Marks: ";
        cin >> eng;
        cout << "Science Marks: ";
        cin >> sci;
        total = math + eng + sci;
        cout << "Total Marks: " << total << "/300" << endl;
        avg = total / 3;
        cout << "Average Marks: " << avg << endl;

        if (avg <= 100 && avg >= 90)
        {
            cout << "\nGrade: A\n";
        }
        else if (avg <= 89 && avg >= 80)
        {
            cout << "\nGrade: B\n";
        }
        else if (avg <= 79 && avg >= 70)
        {
            cout << "\nGrade: C\n";
        }
        else if (avg <= 69 && avg >= 60)
        {
            cout << "\nGrade: D\n";
        }
        else if (avg <= 60)
        {
            cout << "\nGrade: F\n";
        }
    }
}
