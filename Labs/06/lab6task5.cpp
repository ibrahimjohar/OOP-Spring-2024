/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 17 March 2024
*   Description: Consider a School Management System. You are required to create two classes, Student and Course. Each student can enroll in multiple courses.
*                The Course class should have the following properties: course code (string), course name (string), and course credit hours (integer).
*                The Student class should have the following properties:
*                student ID (string), student name (string), and a list of enrolled courses (an array of Course objects).
*/

#include <iostream>
using namespace std;

const int MaxCourses = 8;

class Course
{
    private:
        string courseCode;
        string courseName;
        int courseCreditHrs;
    public:
        Course(){}
        Course(string code, string name, int creditHrs): 
            courseCode(code), courseName(name), courseCreditHrs(creditHrs){}

        void setCourseName(string name)
        {
            courseName = name;
        } 
        string getCourseName() const
        {
            return courseName;
        }
        void setCourseCode(string code) 
        {
            courseCode = code;
        }
        string getCourseCode()
        {
            return courseCode;
        }
        void setCourseCreditHrs(int creditHrs)
        {
            courseCreditHrs = creditHrs;
        }
        int getCourseCreditHrs()
        {
            return courseCreditHrs;
        }
};

class Student
{
    private:
        string id;
        string name;
        Course courses[MaxCourses];
        int nCoursesEnrolled;
    public:
        Student(string id, string name)
        {
            this->id = id;
            this->name = name;
            nCoursesEnrolled = 0;
        }

        void enroll(const Course& course)
        {
            if (nCoursesEnrolled < MaxCourses)
            {
                courses[nCoursesEnrolled++] = course;
                cout << course.getCourseName() << " enrolled.\n";
            }
            else
            {
                cout << "Maximum number of courses enrolled.\n";
            }
        }

        void drop(const string& courseCode)
        {
            int index = -1;
            for (int i = 0; i < nCoursesEnrolled; i++)
            {
                if (courses[i].getCourseCode() == courseCode)
                {
                    index = i;
                    break;
                }
            }

            if (index != -1)
            {
                for (int i = index; i < nCoursesEnrolled - 1; i++)
                {
                    courses[i] = courses[i + 1];
                }
                nCoursesEnrolled--;
                cout << "Course " << courseCode << " dropped successfully.\n";
            }
            else
            {
                cout << "Course " << courseCode << " not found.\n";
            }
        }

        int getTotalCreditHours()
        {
            int totalCreditHrs = 0;
            for (int i = 0; i < nCoursesEnrolled; i++)
            {
                totalCreditHrs += courses[i].getCourseCreditHrs();
            }
            return totalCreditHrs;
        }    

        void printEnrolledCourses()
        {
            for (int i = 0; i < nCoursesEnrolled; i++)
            {
                cout << "Course " << i+1 << "\n";
                cout << "Code: " << courses[i].getCourseCode() << "\n";
                cout << "Name: " << courses[i].getCourseName() << "\n";
                cout << "Credit Hours: " << courses[i].getCourseCreditHrs() << "\n\n";
            }
        }  
};


int main()
{
    class Course course1("24-kl", "AP", 3);
    class Course course2("54-r5", "Calculus", 3);
    class Course course3("EL-1005", "DLD", 2);

    class Student student1("23k-0074", "Ibrahim Johar");
    
    student1.enroll(course1);
    student1.enroll(course2);
    student1.enroll(course3);
    cout << "\n";

    int totalCredHrs = student1.getTotalCreditHours();
    cout << "Total Credit Hours: " << totalCredHrs << "\n\n";

    student1.printEnrolledCourses();

    student1.drop("EL-1005");
    cout << "\n";

    totalCredHrs = student1.getTotalCreditHours();
    cout << "Total Credit Hours: " << totalCredHrs << "\n\n";

    student1.printEnrolledCourses();

    return 0;
}
