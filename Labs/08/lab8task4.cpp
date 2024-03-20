/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 19 March 2024
*   Description: Suppose you are developing a program for a school that needs to keep track of its students
*                and teachers. Both students and teachers have a name and an age, but they have different
*                properties beyond that. Students have a student ID number and a grade level, while
*                teachers have a subject they teach and a room number.
*/

#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
    public:
        Person(string n, int a) : name(n), age(a) {}

        void display()
        {
            cout << "Name: " << name << "\n";
            cout << "Age: " << age << "\n";
        }

        string getname()
        {
            return name;
        }

        int getage()
        {
            return age;
        }
};

class Student : public Person
{
    private:
        string studentID;
        int gradeLevel;
    public:
        Student(string stdId, int gL, string n, int a) : 
            studentID(stdId), gradeLevel(gL), Person(n, a) {}
        
        void display()
        {
            cout << "Student Name: " << getname() << "\n";
            cout << "Student Age: " << getage() << "\n";
            cout << "Student ID: " << studentID << "\n";
            cout << "Grade Level: " << gradeLevel << "\n";
        }

        string getStdName()
        {
            return getname();
        }

        int getStdAge()
        {
            return getage();
        }

        string getStdId()
        {
            return studentID;
        }

        int getgradeLevel()
        {
            return gradeLevel;
        }
};

class Teacher : public Person
{
    private:
        string subject;
        string roomNumber;
    public:
        Teacher(string sub, string roomNum, string n, int a) : 
            subject(sub), roomNumber(roomNum), Person(n, a) {}
        
        void display()
        {
            cout << "Subject: " << subject << "\n";
            cout << "Room Number: " << roomNumber << "\n";
        }

        string getTeacherName()
        {
            return getname();
        }

        string getRoomNum()
        {
            return roomNumber;
        }

        string getsub()
        {
            return subject;
        }

};

class GraduateStudent : public Student, public Teacher
{
    private:
        string graduatingDate;
    public:
        GraduateStudent(string gradDate, string stdId, int gL, string sub, string roomNum, string s_n, int s_a, string t_n, int t_a) :
            graduatingDate(gradDate), Student(stdId, gL, s_n, s_a), Teacher(sub, roomNum, t_n, t_a) {}
        
        void display()
        {
            cout << getStdName() << ", Age: " << getStdAge() << " Years Old; has graduated on '" << graduatingDate << "'.\n";
            cout << "Student ID: " << getStdId() << "\n";
            cout << "Student Grade Level: " << getgradeLevel() << "\n";
            cout << getStdName() << " is now a Teacher Assistant for '" << getTeacherName() << "' in room '" << getRoomNum() << "' for the subject of '" << getsub() << "'\n";
        }
};

int main()
{
    GraduateStudent gradStudent1("21 March 2024", "23K-0074", 14, "Object Oriented Programming", "EE-34", "Ibrahim Johar", 19, "Sir Mark", 27);

    gradStudent1.display();

    return 0;
}