/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Scenario 1
*/

#include <iostream>
#include <string>
using namespace std;

class Pet
{
    private:
        string species;
        string petname;
        string healthStatus;
        int hungerLevel;
        int happinessLevel;
        string specialSkills[100];
    public:
        Pet(){}

        Pet(string health, int hunger, int happiness, string animal, string name, string skills[100])
        : healthStatus(health), hungerLevel(hunger), happinessLevel(happiness), species(animal), petname(name)
        {
            for (int i = 0; i < 100; ++i) {
                specialSkills[i] = skills[i];
            }
        }

        string get_species()
        {
            return species;
        }

        string get_petname()
        {
            return petname;
        }

        int get_hunger()
        {
            return hungerLevel;
        }

        int get_happiness()
        {
            return happinessLevel;
        }

        string get_healthstatus()
        {
            return healthStatus;
        }

        void get_specialskills()
        {
            cout << "Special Skills:\n";
            for (int i = 0; i < 100; i++)
            {
                cout << i+1 << " - " << specialSkills[i] << "\n";
            }
        }

        void displayPetDetails()
        {
            cout << "\nHealth Status: " << healthStatus << "\n";
            cout << "Hunger Level: " << hungerLevel << "\n";
            cout << "Happiness Level: " << happinessLevel << "\n";
            cout << "Special Skills:\n";
            for (int i = 0; i < 100; i++)
            {
                cout << specialSkills[i] << "\n";
            }
        }

        void updateHappiness(int happiness)
        {
            happinessLevel = min(happiness, 10);
        }

        void updateHealth(string health)
        {
            healthStatus = health;
        }

        void updateHunger(bool feed, int hunger)
        {
            hungerLevel = hunger;
            // Update hunger based on user action (feed or other relevant actions)
            if (feed)
            {
                hungerLevel = max(hungerLevel - 1, 0); // Hunger decreases when fed
                happinessLevel = min(happinessLevel + 1, 10); // Feeding increases happiness
            }
            else 
            {
                hungerLevel = min(hungerLevel + 1, 10); // Hunger increases
                happinessLevel = max(happinessLevel - 1, 0); // Happiness decreases when hungry
            }
        }
};

class Adopter
{
    private:
        string adopterName;
        string adopterMobileNum;
        Pet adoptedPetRecords[10];
        int numAdoptedPets;
    public:
        Adopter(string name, string mobilenum) : adopterName(name), adopterMobileNum(mobilenum), numAdoptedPets(0){}

        void adoptPet(const Pet& pet)
        {
            if (numAdoptedPets < 10)
            {
                adoptedPetRecords[numAdoptedPets] = pet;
                numAdoptedPets++;
                cout << "Pet was successfully adopted!\n\n";
            }
            else
            {
                cout << "Sorry, you can't adopt any more pets as maximum limit has been reached.\n\n";
            }
        }

        int get_NumAdoptedPets()
        {
            return numAdoptedPets;
        }

        void returnPet(string pet_name)
        {
            int index = -1;
            for (int i = 0; i < 10; i++)
            {
                if (adoptedPetRecords[i].get_petname() == pet_name)
                {
                    index = i;
                    break;    
                }
            }

            if (index != -1)
            {
                for (int i = index; i < numAdoptedPets - 1; i++)
                {
                    adoptedPetRecords[i] = adoptedPetRecords[i+1];
                }
                numAdoptedPets--;
                cout << "Pet '" << pet_name << "' returned successfully!\n\n";
            }
            else
            {
                cout << "Pet '" << pet_name << "' not found. Unable to return pet.\n\n";
            }
        }
        
        void displayAdoptedPets()
        {
            for (int i = 0; i < numAdoptedPets; i++)
            {
                cout << "Pet #" << i+1 << ":\n";
                cout << "Name: " << adoptedPetRecords[i].get_petname() << "\n";
                cout << "Species: " << adoptedPetRecords[i].get_species() << "\n";
                adoptedPetRecords[i].displayPetDetails();

                if (i < numAdoptedPets - 1)
                cout << "\n";
            }
        }

        void interactWithPet(string pet_name)
        {
            int index = -1;
            for (int i = 0; i < get_NumAdoptedPets(); i++)
            {
                if (adoptedPetRecords[i].get_petname() == pet_name)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Pet not found in adopted list.\n";
                exit;
            }

            Pet& pet = adoptedPetRecords[index];

            cout << "Interacting with " << pet_name  << "\n";
            cout << "1. Feed the pet\n";
            cout << "2. Play with the pet\n";
            cout << "Enter interaction #: ";
            int choice;
            cin >> choice;

            int hunger, happiness;
            string confirmation;
            switch(choice)
            {
                case 1:
                    cout << "Enter Pet's current hunger level: ";
                    cin >> hunger;

                    cout << "Do you want to feed the pet? (Yes or No): ";
                    cin.ignore();
                    getline(cin, confirmation);
                    if (confirmation == "Yes" || confirmation == "yes" || confirmation == "YES")
                    {
                        pet.updateHunger(true, hunger);
                        cout << "You have now fed your pet, therefore happiness has increased and hunger has been reduced\n";
                        cout << "After feeding your pet:\n";
                        cout << "Hunger Level: " << pet.get_hunger() << "\n";
                        cout << "Happiness Level: " << pet.get_happiness() << "\n";
                        cout << "\n";
                    }   
                    else if(confirmation == "No" || confirmation == "no" || confirmation == "NO")
                    {
                        pet.updateHunger(false, hunger);
                        cout << "You have not fed your pet, therefore happiness has decreased and hunger has been increased\n";
                        cout << "After not feeding your pet:\n";
                        cout << "Hunger Level: " << pet.get_hunger() << "\n";
                        cout << "Happiness Level: " << pet.get_happiness() << "\n";
                        cout << "\n";
                    }
                    break;
                case 2:
                    cout << "Enter Pet's current happiness level: ";
                    cin >> happiness;

                    cout << "Do you want to play with the pet? (Yes or No)";
                    cin.ignore();
                    getline(cin, confirmation);
                    if (confirmation == "Yes" || confirmation == "yes" || confirmation == "YES")
                    {
                        pet.updateHappiness(happiness + 1);
                        cout << "You have now played with your pet, therefore happiness has increased\n";
                        cout << "After playing with your pet:\n";
                        cout << "Happiness Level: " << pet.get_happiness() << "\n";
                        cout << "\n";
                    }   
                    else if(confirmation == "No" || confirmation == "no" || confirmation == "NO")
                    {
                        pet.updateHappiness(happiness - 1);
                        cout << "You have not played with your pet, therefore happiness has decreased\n";
                        cout << "After playing with your pet:\n";
                        cout << "Happiness Level: " << pet.get_happiness() << "\n";
                        cout << "\n";
                    }
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
            }
        }
};

int main()
{
    cout << "Ibrahim Johar Farooqi\n23K-0074\n";
    string name, number;
    cout << "Enter Your Name: ";
    getline(cin, name);
    cout << "Enter Your Mobile Number: ";
    getline(cin, number);
    cout << "\n";

    Pet allPets[100];
    int total_pets=0;
    Adopter adopter1(name, number);

    int choice;

    do
    {
        cout << name << ", Welcome!\n";
        cout << "Virtual Pet Adoption System\n";
        cout << "Menu:\n";
        cout << "1.Add a Pet\n";
        cout << "2.Show all Pets\n";
        cout << "3.Adopt a Pet\n";
        cout << "4.Interact with a Pet\n";
        cout << "5.Return a Pet\n";
        cout << "6.Show all adopted Pets\n";
        cout << "Input Menu Number (-1 to exit): ";
        cin >> choice;
        cout << "\n";

        string species, health, petname;
        int hunger, happiness, n_skills, pet_index, index;
        string skills[100];
        
        switch (choice)
        {
        case 1:
            {
                cout << "Enter Pet Name: ";
                cin.ignore();
                getline(cin, petname);
                cout << "Enter Species: ";
                getline(cin, species);
                cout << "Enter Health Status: ";
                getline(cin, health);
                cout << "Enter Hunger Level: ";
                cin >> hunger;
                cout << "Enter Happiness Level: ";
                cin >> happiness;
                cout << "Enter number of special skills: ";
                cin >> n_skills;
                cin.ignore();
                for (int i = 0; i < n_skills; i++)
                {
                    cout << i+1 << ": ";
                    getline(cin, skills[i]);
                }
                cout << "\n";

                Pet newPet(health, hunger, happiness, species, petname, skills);
                allPets[total_pets] = newPet;
                total_pets++;
            }
            break;
        case 2:
            {
                for (int i = 0; i < total_pets; i++)
                {
                    cout << "Pet Name: " << allPets[i].get_petname() << "\n";
                    cout << "Species: " << allPets[i].get_species() << "\n";
                    cout << "Health Status: " << allPets[i].get_healthstatus() << "\n";
                    cout << "Hunger Status: " << allPets[i].get_hunger() << "\n";
                    cout << "Happiness Status: " << allPets[i].get_happiness() << "\n";
                    cout << "\n";
                }
            }
            break;
        case 3:
            {
                cout << "Enter Name of Pet you would like to adopt: ";
                cin.ignore();
                getline(cin, petname);
                index = -1;
                for (int i = 0; i < 100; i++)
                {
                    if (allPets[i].get_petname() == petname)
                    {
                        index = i;
                        break;
                    }
                }
                if (index == -1)
                {
                    cout << "Pet not found in list.\n";
                    exit(0);
                }

                adopter1.adoptPet(allPets[index]);
            }
            break;
        case 4:
            {
                cout << "Enter name of the pet you want to interact with: ";
                cin >> petname;

                adopter1.interactWithPet(petname);
            }
            break;
        case 5:
            {
                cout << "Which pet would you like to return? Enter Name: ";
                cin >> petname;

                adopter1.returnPet(petname);
            }
            break;
        case 6:
            {
                adopter1.displayAdoptedPets();
            }
            break;
        default:
            cout << "Exiting the Virtual Pet Adoption System.\n";
            break;
        }

    } while(choice >= 1 && choice <= 6);

    return 0;
}

