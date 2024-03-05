/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 15 February 2024
*   Description: Revise the previous Book class by eliminating the parameterized constructor and enhancing the default constructor. 
*                The revised default constructor should initialize the page count to 1000 and the pages read to 0 using a member initialization list.
*                Generate setter methods for the remaining attributes and utilize them within the main function to update attribute values.
*                Introduce a method called "showBookInfo" to exhibit all book details. Invoke this method from the main function for displaying book information.
*/

#include <iostream>
using namespace std;

class Book
{
    private:
        string name;
        string author;
        int isbn;
        int total_pg_count;
        int pages_read;
    public: 
        Book(): total_pg_count(1000), pages_read(0){} //constructor using member initialization list 

        void set_name(string Name)
        {
            name = Name;
        }

        void set_author(string Author)
        {
            author = Author; 
        }

        void set_isbn(int ISBN)
        {
            isbn = ISBN;
        }

        void showBookInfo()
        {
            cout << "Book Name: " << name << "\n";
            cout << "Book Author: " << author << "\n";
            cout << "Book ISBN: " << isbn << "\n";
            cout << "Book Page Count: " << total_pg_count << "\n";
            cout << "Pages Read: " << pages_read << "\n"; 
        } 

};

int main()
{
    Book book1;

    book1.set_name("500 Days of Summer");
    book1.set_author("Floyd");
    book1.set_isbn(45309); 
    book1.showBookInfo();

    return 0;
}
