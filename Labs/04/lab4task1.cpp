/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 15 February 2024
*   Description: Construct a class representing a Book, encompassing attributes like name, author, ISBN number, and total page count, along with a variable tracking the number of pages read.
*                Tasks include defining constructors for the Book class - one default constructor and another parameterized constructor initializing all attributes. Values can be hardcoded within the main function.
*                Additionally, implement a method to update the pages read, triggering a display of "You have finished the book" when all pages are read. This method should be called from the main function to monitor reading progress.
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
        Book(){}
        Book(string Name, string Author, int ISBN, int Total_PG_Count, int PGs_Read)
        {
            name = Name;
            author = Author;
            isbn = ISBN;
            total_pg_count = Total_PG_Count;
            pages_read = PGs_Read;
        }

        void update_pages(int pgs_read)
        {
            pages_read += pgs_read;
            if (pages_read == total_pg_count)
            {
                cout << "You have finished the book.\n";
            }
            else if (pages_read < total_pg_count)
            {
                cout << "You have not finished the book.\n";
            }
        }
};

int main()
{
    Book book1("Life of Pi", "Steven Speilberg", 98732, 500, 0);

    int update_pages;

    do
    {
        cout << "How many pages have you read? [0 to exit]: ";
        cin >> update_pages;

        book1.update_pages(update_pages);
    }while (update_pages != 0);

    return 0;
}
