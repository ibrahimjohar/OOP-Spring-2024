/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Scenario 2
*/

#include <iostream>
#include <cmath>
using namespace std;

class Table 
{
    private:
        const int defaultseats = 4;
        int total_seat_capacity;
        int occupied_seats;
        int free_seats;
        bool clean;
    public:
        Table(): total_seat_capacity(defaultseats), occupied_seats(0), clean(true){}

        Table(int capacity): occupied_seats(0), clean(true)
        {
            if(capacity != 4 && capacity != 8)
            {
                total_seat_capacity = round(capacity / 4.0) * 4;
            }
            else if(capacity == 4)
            {
                total_seat_capacity = capacity;
            }
            else if(capacity == 8)
            {
                total_seat_capacity = capacity;
            }
        }

        Table& operator=(const Table &other)
        {
            if (this != &other)
            {
                // Copy members from 'other' to 'this'
                total_seat_capacity = other.total_seat_capacity;
                occupied_seats = other.occupied_seats;
                free_seats = other.free_seats;
                clean = other.clean;
            }
            return *this;
        }

        bool isTableClean()
        {
            return clean;
        }

        bool isTableOccupied()
        {
            return occupied_seats > 0;
        }

        void occupyTable(int grp_size)
        {
            if (isTableClean() && !isTableOccupied())
            {
                if (grp_size <= total_seat_capacity)
                {
                    occupied_seats = grp_size;
                }
                else
                {
                    cout << "Number of people in group exceed table's seat capacity.\n";
                }
            }
            else
            {
                cout << "Table cannot be occupied right now.\n";
            }
        }

        void freeTable()
        {
            if (isTableOccupied())
            {
                occupied_seats = 0;
            }
            else
            {
                cout << "Table is already empty and ready to be occupied.\n";
            }
        }

        void haveLunch()
        {
            if (isTableOccupied())
            {
                clean = false;
                cout << "Having lunch on this table, hence table is not clean.\n";
            }
            else
            {
                cout << "No one is seated at this table hence cannot have lunch.\n";
            }
        }

        void leaveTable()
        {
            if (isTableOccupied())
            {
                occupied_seats = 0;
                cout << "The group is now leaving the table. Table is now empty.\n";
            }
            else
            {
                cout << "Table is already empty.\n";
            }
        }

        void cleanTable()
        {
            if (!isTableOccupied())
            {
                clean = true;
                cout << "Table has now been cleaned.\n";
            }
            else
            {
                cout << "People are still seated, table cannot be cleaned at the moment.\n";
            }
        }
};

void OccupyTable(Table tables[], int n_tables, int grp_size)
{
    bool tablefound = false;
    for (int i = 0; i < n_tables; i++)
    {
        if (!tables[i].isTableOccupied())
        {
            tables[i].occupyTable(grp_size);
            tablefound = true;
            cout << "Table " << i+1 << " occupied for " << grp_size << " people.\n";
            break;
        }
    }

    if (!tablefound)
    {
        cout << "No table found for a group of " << grp_size << ".\n";
    }
}

void EmptyTable(Table tables[], int n_tables, int tablenumber)
{
    if (tablenumber >= 0 && tablenumber < n_tables)
    {
        tables[tablenumber].freeTable();
        cout << "Table " << tablenumber + 1 << " has been emptied.\n";
    }
    else
    {
        cout << "Table number does not exist.\n";
    }
}

int main()
{
    cout << "Ibrahim Johar Farooqi\n23K-0074\n";
    Table tables[5];

    tables[0] = Table(8); 
    tables[1] = Table(8); 
    tables[2] = Table(4); 
    tables[3] = Table(4); 
    tables[4] = Table(4); 

    OccupyTable(tables, 5, 4); //table1
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    cout << "\n";

    OccupyTable(tables, 5, 6); //table2
    EmptyTable(tables, 5, 1);

    return 0;
}
