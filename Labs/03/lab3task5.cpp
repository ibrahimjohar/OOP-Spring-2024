/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 13 February 2024
*   Description: Construct a class for a stationary shop.
*                This class maintains lists for all items it sells (hint: an array of strings) and their corresponding prices (hint: an array of prices).
*                Design a menu-driven program to:
*                • Enable the shop owner to add items and their prices.
*                • Retrieve the list of items.
*                • Modify the prices of items.
*                • Display all items along with their prices.
*                Generate a receipt that the shopkeeper can share with customers. This receipt can only be generated after the shopkeeper inputs the items and their quantities bought by the customer.
*/

#include <iostream>
#include <string>
using namespace std;

class StationaryShop
{
    private:
        string item_list[100];
        double item_prices[100] = {0.0};
        int item_count;

    public:
        //constructor
        StationaryShop()
        {
            item_count = 0;
        }
        
        //method to add items to array
        void add_items(string item_name, double price)
        {
            if (item_count < 100)
            {
                item_list[item_count] = item_name;
                item_prices[item_count] = price;
                item_count++;
                cout << item_name << " added successfully.\n";
            }
            else
            {
                cout << "Maximum number of items are added. More items cannot be added\n";
            }
        }

        //method to display items along with prices
        void display_items_prices()
        {
            cout << "List of all items with prices: \n";
            for (int i = 0; i < 100; i++)
            {
                if (item_list[i] != "" && item_prices[i] != 0.0) //condition check, in order to skip empty indexes
                {
                    cout << "Item " << i+1 << ": " << item_list[i] << " Price: $ " << item_prices[i] << "\n";
                }
                
            }
        }

        //method to display only items
        void display_items_list()
        {
            cout << "List of all items: \n";
            for (int i = 0; i < 100; i++)
            {
                if (item_list[i] != "") //condition for skipping empty array indexes
                {
                    cout << "Item " << i+1 << ": " << item_list[i] << "\n";
                }
            }
        }

        //method to modify prices of items
        void modify_price(string item_name, double new_price)
        {
            int flag = 0;
            for (int i = 0; i < 100; i++)
            {
                if (item_list[i] == item_name)
                {
                    item_prices[i] = new_price;
                    cout << "Price of " << item_list[i] << " updated!\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Item not found in list.\n";
            }
        }

        //method for generating receipt 
        void receipt(int items_purchased[], int quantities[])
        {
            double totalamount = 0.0;
            cout << "Receipt: \n";
            for (int i = 0; i < 100; i++)
            {
                if (items_purchased[i] != 0)
                {
                    cout << "Item: " << item_list[items_purchased[i] - 1] << " Quantity: " << quantities[i] << "\n";
                    totalamount += item_prices[items_purchased[i] - 1] * quantities[i]; //calculation of final sum
                }
            }
            cout << "Total Amount = $" << totalamount << "\n";
        }

};

int main()
{
    //object declaration
    StationaryShop myshop;

    int menu;

    do
    {
        cout << "\nStationary Shop Menu:\n";
        cout << "1.Add Items\n";
        cout << "2.Display List of Items\n";
        cout << "3.Modify Price of an Item\n";
        cout << "4.Display Items with Prices\n";
        cout << "5.Generate Reciept\n";
        cout << "Any other number to exit shop.\n";
        cout << "Enter menu number: ";
        cin >> menu;

        string itemname;
        double price;
        
        int quantities[100] = {0}; //to store the quanity of individual items purchased by customer
        int purchaseditems[100] = {0}; //to store the index values of the items purchased by customer

        switch (menu)
        {
        case 1:
            cout << "Enter name of the item: ";
            cin.ignore();
            getline(cin, itemname);
            cout << "Enter price of the item: ";
            cin >> price;
            
            myshop.add_items(itemname, price); 
            break;
        case 2:
            myshop.display_items_list();
            break;
        case 3:
            cout << "Enter name of the item you would like to update its price: ";
            cin.ignore();
            getline(cin, itemname);
            cout << "Enter new price of the item: ";
            cin >> price;

            myshop.modify_price(itemname, price);
            break;
        case 4:
            myshop.display_items_prices();
            break;
        case 5:
            int item_index, quantity;
            
            //loop to continue asking for all the items, the customer wants to purchase
            while(true)
            {
                cout << "Enter item index number (press 0 to stop): ";
                cin >> item_index;
                if (item_index == 0)
                {
                    break;
                }
                cout << "Enter quantity of item: ";
                cin >> quantity;
                purchaseditems[item_index - 1] = item_index;
                quantities[item_index - 1] = quantity;
            }

            myshop.receipt(purchaseditems, quantities); //generate receipt
            break;
        default:
            cout << "Shop is closing now.\n";
            break;
        }
    } while (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5);

    return 0;    
}
