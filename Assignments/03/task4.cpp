/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 4
*/

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class Drone
{
    protected:
        float latitude;
        float longitude;
        float altitude;
        float speed;
    public:
        Drone(float lat, float lon, float alt, float s) : latitude(lat), longitude(lon), altitude(alt), speed(s) {}

        void adjustAltitude(float meters) { altitude += meters; }

        void setSpeed(float speed)
        { 
            try
            {
                if (speed < 0)
                {
                    throw "Error! Speed cannot be less than zero\n";
                }
                else
                {
                    this->speed = speed;
                }
            }
            catch(const char *error)
            {
                cout << error << "\n";
            }
        }

        virtual void displayPosition() const
        {
            cout << "Latitude: " << latitude << "\n"; 
            cout << "Longitude: " << longitude << "\n";
            cout << "Altitude: " << altitude << "\n";
            cout << "Speed: " << speed << "\n";
        }
};

class Flyable
{
    public:
        virtual void takeoff() = 0;
        virtual void land() = 0;
        virtual void navigateTo(float lat, float lon, float alti) = 0;
};

class Scanable
{
    public:
        virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scanable
{
    private:
        float cameraResolution;
        float maxFlightTime;
    public:
        ReconDrone(float lat, float lon, float alt, float s, float res, float maxTime) :
            Drone(lat, lon, alt, s), cameraResolution(res), maxFlightTime(maxTime) {}
        
        void takeoff() override 
        {
            this->altitude = 20.f; 
            cout << "\nRecon Drone is taking off.\n"; 
        }

        void land() override
        {
            this->altitude = 0.f; 
            cout << "\nRecon Drone has landed now.";
        }

        void navigateTo(float lat, float lon, float alti) override
        {
            try
            {
                if (alti < 0)
                {
                    throw "Error! Invalid Altitude value\n"; //altitude cannnot be less than zero
                }
                else
                {
                    float distance = sqrt(pow(lat - latitude, 2) + pow(lon - longitude, 2) + pow(alti - altitude, 2));
                    float time = distance / speed; 

                    cout << "\nCurrently navigating to: [" << lat << ", " << lon << ", " << alti << "]\n";
                    cout << "Est Time required to reach destination is " << time << " seconds.\n";
                }
            }
            catch(const char *error)
            {
                cout << error << "\n";
            }
            
        }

        void scanArea(float radius) override
        {
            cout << "\nScanning area within a radius of " << radius << " meters.\n";
        }
};


int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 4\n\n";

    ReconDrone drone(10.0f, 20.f, 0.0f, 20.0f, 1080, 30.0f);
    drone.takeoff();
    drone.setSpeed(50.f);

    drone.scanArea(650);
    drone.navigateTo(22.0f, 38.0f, 150.0f);
    drone.scanArea(1700);
    drone.navigateTo(54.0f, 230.0f, 190.0f);

    drone.land();

    return 0;
}
