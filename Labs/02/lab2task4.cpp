/*
*   Name: Ibrahim Johar Farooqi
*   Roll No: 23K-0074
*   Date: 1 February 2024   
*   Description: Your task is to implement a basic Student Registration System in C++. Define two structures, Register and Student, 
                where Register includes attributes courseId and courseName, and Student inherits from Register while having additional attributes
                such as studentId, firstName, lastName, cellNo, and email. Your objective is to create an array of Student structures to store data for five students.
                Write a C++ program that accomplishes the following tasks:
                    1. Implement the Register and Student structures.
                    2. Inherit the Register structure in the Student structure.
                    3. Create an array of Student structures to store data for 5 students.
                    4. Take input for each student, including their courseId, courseName,
                    studentId, firstName, lastName, cellNo, and email.
                    5. Display the information for all 5 students.
*/



#include <iostream>
#include <string>
using namespace std;

struct Register
{
    int courseId;
    string courseName;
};

struct Student: Register
{
    string studentId;
    string firstname;
    string lastname;
    string email;
    long long int cellno;
};

int main()
{
    struct Student studentdata[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Course ID for Student " << i + 1 << ": ";
        cin >> studentdata[i].courseId;
        cin.ignore();
        cout << "Enter the Course Name for Student " << i + 1 << ": ";
        getline(cin, studentdata[i].courseName);
        cout << "Enter the First Name for Student " << i + 1 << ": ";
        getline(cin, studentdata[i].firstname);
        cout << "Enter the Last Name for Student " << i + 1 << ": ";
        getline(cin, studentdata[i].lastname);
        cout << "Enter the Cell No. for Student " << i + 1 << ": ";
        cin >> studentdata[i].cellno;
        cin.ignore();
        cout << "Enter the Email for Student " << i + 1 << ": ";
        getline(cin, studentdata[i].email);        
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "\nStudent " << i + 1 << ".\n";
        cout << "Course ID: " << studentdata[i].courseId;
        cout << "\nCourse Name: " << studentdata[i].courseName;
        cout << "\nFirst Name: " << studentdata[i].firstname;
        cout << "\nLast Name: " << studentdata[i].lastname;
        cout << "\nCell No: " << studentdata[i].cellno;
        cout << "\nEmail: " << studentdata[i].email;
    }
    
    return 0;
}
