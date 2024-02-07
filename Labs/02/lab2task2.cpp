/*
*   Programmer : Ibrahim Johar Farooqi
*   Date: 5 February 2024
*   Description: Envision that you’re assigned to create a program to handle a library’s book inventory.
*                Each book has characteristics such as title, author, year of publication, and genre. 
*                Construct a struct that accurately depicts a book as an entity in the real world.
*                Then, using a programming C++, write a basic program that uses this struct to demonstrate the creation, modification, and display of book data.
*                    1. Expand the program to manage an array of multiple books.
*                    2. Develop a function to find a book by its title or author.
*                    3. Enable the user to interactively input new books and update existing book data.
*/

#include <iostream>
#include <string>
using namespace std;

//struct definition
struct Books
{
    string title;
    string author;
    string genre;
    int yearofpubl;
};

//bookfinder function definition
void bookfinder(string bookname, int nbooks, struct Books *booksinfo)
{
    int flag = 0;
    for (int i = 0; i < nbooks; i++)
    {
        if (booksinfo[i].title == bookname || booksinfo[i].author == bookname)
        {
            flag = 1;
            cout << "Book Title: " << booksinfo[i].title;
            cout << "\nBook Author: " << booksinfo[i].author;
            cout << "\nBook Genre: " << booksinfo[i].genre;
            cout << "\nPublishing Year of Book: " << booksinfo[i].yearofpubl << endl;
        }
        else
        {
            flag = 0;
            continue;
        }
    }

    if (flag == 0)
    {
        cout << "Book title/author not found in library.\n";
    }
}

int main()
{
    int nbooks;
    cout << "Enter number of books you would like to enter: ";
    cin >> nbooks;
    cin.ignore();

    Books *booksinfo = new Books[nbooks]; //use of dma to allocate memory for booksinfo array 

    for (int i = 0; i < nbooks; i++)
    {
        cout << "Book " << i + 1 << " Title: ";
        getline(cin, booksinfo[i].title);
        cout << "Book " << i + 1 << " Author: ";
        getline(cin, booksinfo[i].author);
        cout << "Book " << i + 1 << " Genre: ";
        getline(cin, booksinfo[i].genre);
        cout << "Book " << i + 1 << " Year of Publishing: ";
        cin >> booksinfo[i].yearofpubl;
        cin.ignore(); 
    }

    int main_menu;
    string bookname;
    int flag = 0;
    do
    {
        cout << "\nMain Menu:\n";
        cout << "1. Add more books.\n2. Update Book Information.\n3. Search a Book.\n";
        cout << "Enter main menu option (press any other key except 1, 2, 3 to exit): ";
        cin >> main_menu;
        cin.ignore(); 

        switch (main_menu)
        {
        case 1:
        {
            int newcount;
            cout << "Enter number of new books you would like to add: ";
            cin >> newcount;
            cin.ignore(); 

            int totalbooks = nbooks + newcount; //update count 
            Books *new_booksinfo = new Books[totalbooks]; //new declaration of array using dma to increase size of array

            //copy contents of original array to the new larger (in size) array 
            for (int i = 0; i < nbooks; i++)
            {
                new_booksinfo[i] = booksinfo[i];
            }

            for (int i = nbooks; i < totalbooks; i++)
            {
                cout << "Book " << i + 1 << " Title: ";
                getline(cin, new_booksinfo[i].title);
                cout << "Book " << i + 1 << " Author: ";
                getline(cin, new_booksinfo[i].author);
                cout << "Book " << i + 1 << " Genre: ";
                getline(cin, new_booksinfo[i].genre);
                cout << "Book " << i + 1 << " Year of Publishing: ";
                cin >> new_booksinfo[i].yearofpubl;
                cin.ignore();
            }

            delete[] booksinfo; //free the memory allocated for original booksinfo
            booksinfo = new_booksinfo; //updating booksinfo to point to new_booksinfo
            nbooks = totalbooks; //update the total number of books
            flag = 1;
            break;
        }

        case 2:
            cout << "Enter book title to update: ";
            getline(cin, bookname);

            //search for book and updating info
            for (int i = 0; i < nbooks; i++)
            {
                if (booksinfo[i].title == bookname)
                {
                    cout << "Book ' " << booksinfo[i].title << " ' Found!\n";
                    cout << "Updated Book Title: ";
                    getline(cin, booksinfo[i].title);
                    cout << "Updated Book Author: ";
                    getline(cin, booksinfo[i].author);
                    cout << "Updated Book Genre: ";
                    getline(cin, booksinfo[i].genre);
                    cout << "Updated Year of Publishing: ";
                    cin >> booksinfo[i].yearofpubl;
                    cin.ignore();
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter book title or book author to search your desired book: ";
            getline(cin, bookname);
            bookfinder(bookname, nbooks, booksinfo); //call function to find the book and display its attributes
            break;

        default:
            cout << "\nLibrary is shutting down now!\n";
            break;
        }

    } while (main_menu == 1 || main_menu == 2 || main_menu == 3);

    delete[] booksinfo;
    return 0;
}
