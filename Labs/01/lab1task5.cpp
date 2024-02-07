/*
*   Name: Ibrahim Johar Farooqi
*   Date: 25 Jan 2024
*   Description: Design Event Management System in C++ to facilitate the organization of events. 
                The program should empower the user to seamlessly manage event details, including the event name, date, venue, and organizer.
                Incorporate key features such as the ability to add events, display comprehensive details of all events, and 
                perform event searches based on specific dates. To enhance flexibility and scalability, leverage dynamic memory allocation for
                storing event details.
                1. Prompt the user to input the total number of events they wish to manage.
                2. Dynamically allocate memory to store event details for the specified
                number of events.
                3. For each event, prompt the user to input:
                    • Event Name
                    • Date
                    • Venue
                    • Organizer
                4. Display all events that match the provided date, including their complete
                details.
                5. Allow the user to search for events based on a specific date.
*/

#include <iostream>
#include <string>
using namespace std;

struct EventManagement
{
    string name;
    string date;
    string venue;
    string organizer;
};

int main()
{
    int n_events;
    cout << "Welcome to the Event Management System!\n";
    cout << "Enter total number of events: ";
    cin >> n_events;
    cin.ignore(); 

    EventManagement *events = new EventManagement[n_events];
    int *events_printed = new int[n_events]{0};

    for (int i = 0; i < n_events; i++)
    {
        cout << "Name of Event " << i + 1 << ": ";
        getline(cin, events[i].name);
        cout << "Date of Event " << i + 1 << " (Format: '10-01-2024'): ";
        getline(cin, events[i].date);
        cout << "Venue of Event " << i + 1 << ": ";
        getline(cin, events[i].venue);
        cout << "Organizer of Event " << i + 1 << ": ";
        getline(cin, events[i].organizer);
    }

    int menucount;
    do
    {
        cout << "\nMenu:\n1: Add new events\n2: Search for event(s) on a specific date\n3. Search for events(s) on a specific date with its complete details\n";
        cout << "Enter menu number (press any other key except 1, 2, 3 to exit): ";
        cin >> menucount;
        cin.ignore(); 

        switch (menucount)
        {
        case 1:
        {
            int new_count;
            cout << "Enter number of new events you would like to add: ";
            cin >> new_count;
            cin.ignore(); 

            int total_new_events = n_events + new_count;

            EventManagement *new_events_arr = new EventManagement[total_new_events];

            for (int i = 0; i < n_events; i++)
            {
                new_events_arr[i] = events[i];
            }

            for (int i = n_events; i < total_new_events; i++)
            {
                cout << "Name of Event " << i + 1 << ": ";
                getline(cin, new_events_arr[i].name);

                cout << "Date of Event " << i + 1 << " (Format: '10-01-2024'): ";
                getline(cin, new_events_arr[i].date);

                cout << "Venue of Event " << i + 1 << ": ";
                getline(cin, new_events_arr[i].venue);

                cout << "Organizer of Event " << i + 1 << ": ";
                getline(cin, new_events_arr[i].organizer);
            }

            delete[] events;
            delete[] events_printed;

            events = new_events_arr;
            events_printed = new int[total_new_events]{0};
            n_events = total_new_events;

            cout << "New events were added.\n\n";
            break;
        }
        case 2:
        {
            fill(events_printed, events_printed + n_events, 0);

            string date_n2;
            cout << "Enter date to search for a specific event (Format: '10-01-2024'): ";
            cin >> date_n2;

            for (int i = 0; i < n_events; i++)
            {
                if (events[i].date.find(date_n2) != string::npos && events_printed[i] == 0)
                {
                    cout << "\nEvent Name: " << events[i].name << "\n";
                    events_printed[i] = 1;
                }
            }
            break;
        }
        case 3:
        {
            fill(events_printed, events_printed + n_events, 0);

            string date_n3;
            cout << "\nEnter date to search for a specific event (Format: '10-01-2024'): ";
            cin >> date_n3;

            for (int i = 0; i < n_events; i++)
            {
                if (events[i].date.find(date_n3) != string::npos && events_printed[i] == 0)
                {
                    cout << "\nEvent Name: " << events[i].name << "\n";
                    cout << "Event Date: " << events[i].date << "\n";
                    cout << "Event Venue: " << events[i].venue << "\n";
                    cout << "Event Organizer: " << events[i].organizer << "\n";
                    events_printed[i] = 1;
                }
            }
            break;
        }
        default:
            cout << "\nProgram shutting down.\n";
            break;
        }

    } while (menucount == 1 || menucount == 2 || menucount == 3);

    delete[] events;
    delete[] events_printed;

    return 0;
}
