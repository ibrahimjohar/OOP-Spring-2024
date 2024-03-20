/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 19 March 2024
*   Description: You are designing a library system using C++. You have a class called "Book" with attributes
*                like title, author, and publisher. Now, you want to create a derived class called "FictionBook" which 
*                inherits from the "Book" class and has additional attributes like genre and protagonist.
*/

#include <iostream>
using namespace std;

class Book
{
    private:
        string title;
        string author;
        string publisher;
    public:
        Book(string title, string author, string publisher)
        {
            this->title = title;
            this->author = author;
            this->publisher = publisher;
        }

        void display()
        {
            cout << "Title: " << title << "\n";
            cout << "Author: " << author << "\n";
            cout << "Publisher: " << publisher << "\n\n";
        }
};

class FictionBook : public Book
{
    private:
        string genre;
        string protagonist;
    public:
        FictionBook(string genre, string protagonist, string title, string author, string publisher) : 
            Book(title, author, publisher)
        {
            this->genre = genre;
            this->protagonist = protagonist;
        }

        void display()
        {
            Book::display();
            cout << "Genre: " << genre << "\n";
            cout << "Protagonist: " << protagonist << "\n";
        }
};

int main()
{
    FictionBook fictionbk1("Sci-Fi", "Harry Potter", "Harry Potter - Wizard of Azkaban", "JK Rowling", "Liberty Books");

    fictionbk1.display();

    return 0;
}
