/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Scenario 4
*/

#include <iostream>
#include <string>
using namespace std;

class RollerCoaster
{
    private:
        string name;
        int height;
        int length;
        int speed;
        int capacity;
        int currentNumRiders;
        bool rideInProgress;
    public:
        RollerCoaster(): name("roller coaster"), height(500), length(2000), capacity(20), speed(0), rideInProgress(false), currentNumRiders(0){}

        RollerCoaster(string Name, int max_height, int total_track_length, int Capacity) : speed(0), rideInProgress(false), currentNumRiders(0)
        {
            name = Name;
            height = max_height;
            length = total_track_length;
            if (Capacity > 3)
            {
                if (Capacity % 2 != 0 && Capacity % 3 != 0)
                {
                    capacity = ((Capacity + 1) / 2) * 2;
                }
                else
                {
                    capacity = Capacity;
                }
            }
            else
            {
                cout << "Invalid capacity entered. Capacity is now of 4 people.\n";
                capacity = 4;
            }
        }

        // Getter and Setter for 'name'
        string getName() const 
        {
            return name;
        }

        void setName(const string& Name)
        {
            name = Name;
        }

        // Getter and Setter for 'height'
        int getHeight() const
        {
            return height;
        }

        void setHeight(int MaxHeight)
        {
            height = MaxHeight;
        }

        // Getter and Setter for 'length'
        int getLength() const
        {
            return length;
        }

        void setLength(int TotalTrackLength)
        {
            length = TotalTrackLength;
        }

        // Getter and Setter for 'speed'
        int getSpeed() const
        {
            return speed;
        }

        void setSpeed(int Speed) 
        {
            speed = Speed;
        }

        // Getter and Setter for 'capacity'
        int getCapacity() const 
        {
            return capacity;
        }

        void setCapacity(int Capacity)
        {
            if (Capacity > 3)
            {
                if (Capacity % 2 != 0 && Capacity % 3 != 0)
                {
                    capacity = ((Capacity + 1) / 2) * 2;
                }
                else
                {
                    capacity = Capacity;
                }
            }
            else
            {
                cout << "Invalid capacity entered. Capacity is now set to 4 people.\n";
                capacity = 4;
            }
        }

        // Getter and Setter for 'currentNumRiders'
        int getCurrentNumRiders() const
        {
            return currentNumRiders;
        }

        void setCurrentNumRiders(int CurrentRiders)
        {
            currentNumRiders = CurrentRiders;
        }

        // Getter and Setter for 'rideInProgress'
        bool isRideInProgress() const
        {
            return rideInProgress;
        }

        void setRideInProgress(bool RideStatus)
        {
            rideInProgress = RideStatus;
        }

        int LoadRiders(int nRiders)
        {
            int availableSeats = capacity - currentNumRiders;
            if (!rideInProgress)
            {
                if (nRiders <= availableSeats)
                {
                    currentNumRiders += nRiders;
                    cout << nRiders << " people successfully seated on the roller coaster.\n";
                    return 0;
                }
                else 
                {
                    cout << "Due to limited space only " << availableSeats << " seats are available.\n";
                    return nRiders - availableSeats; //returning excess riders
                }
            }
        }

        int startRide()
        {
            if (!rideInProgress)
            {
                if (currentNumRiders == capacity)
                {
                    cout << "All seats have been occupied.\n";
                }
                else if (currentNumRiders < capacity)
                {
                    cout << "Ride cannot be started as there are " << capacity - currentNumRiders << " empty seats.\n";
                    return capacity - currentNumRiders;
                }
            }
            else
            {
                return -1;
            }

            rideInProgress = true;
            cout << "Ride started!\n";
            
            return 0;
        }

        int stopRide()
        {
            if (rideInProgress)
            {
                rideInProgress = false;
                cout << "Ride has been stopped.\n";
                return 0;
            }
            else
            {
                cout << "Ride is already not in progress.\n";
                return -1;
            }
        }

        void unloadRiders()
        {
            if (!rideInProgress)
            {
                currentNumRiders = 0;
            }
            else
            {
                cout << "Cannot unload riders when ride is in progress.\n";
            }
        }

        void accelerate(int rollno)
        {
            int speed_factor = rollno % 10;
            speed += speed_factor;
        }

        void decelerate(int rollno)
        {
            while (rollno >= 10)
            {
                rollno /= 10;
            }
            int speed_factor = rollno;
            speed -= speed_factor;
        }

};

int main()
{
    cout << "Ibrahim Johar Farooqi\n23K-0074\n";
    RollerCoaster ride1;
    RollerCoaster ride2("new rollercoaster", 600, 2500, 20);

    cout << "RollerCoaster Name: " << ride2.getName() << "\n";
    cout << "Max Height: " << ride2.getHeight() << "\n";
    cout << "Track Length: " << ride2.getLength() << "\n";
    cout << "Capacity: " << ride2.getCapacity() << "\n";
    
    cout << "\n";

    string new_name;
    cout << "Enter new name for rollercoaster: ";
    getline(cin, new_name);
    ride2.setName(new_name);
    cout << "New RollerCoaster Name: " << ride2.getName() << "\n";

    cout << "\n";

    ride2.LoadRiders(20);
    ride2.startRide();
    
    cout << "\n";

    int rollno, freq;
    cout << "Enter Roll Number: ";
    cin >> rollno;
    cout << "Enter number of times the ride should accelerate: ";
    cin >> freq;

    cout << "\nSpeed before acceleration: " << ride2.getSpeed() << "\n";

    for (int i = 0; i < freq; i++)
    {
        ride2.accelerate(rollno);
    }

    cout << "Speed after acceleration: " << ride2.getSpeed() << "\n\n";

    cout << "Enter number of times the ride should decelerate: ";
    cin >> freq;

    for (int i = 0; i < freq; i++)
    {
        ride2.decelerate(rollno);
    }

    cout << "Speed after deceleration: " << ride2.getSpeed() << "\n\n";

    ride2.stopRide();
    ride2.unloadRiders();

    return 0;
}
