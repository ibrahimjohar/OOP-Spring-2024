/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Implement a restaurant ordering system that holds information about the restaurant’smenus, menu items, orders, and payments.
*                Identify the relationship between the five entities mentioned. Keep in mind the following information as well:
*                a) Menu Items hold two things: food name and food price.
*                b) Menu is a class that holds an array of menu items. You can have different functions to add and remove items, or display the entire menu.
*                c) Restaurant ordering system has one menu.
*                d) Any staff member can place an order to the system on behalf of a customer. Theorder class consists of one or more menu items and a payment.
*                e) Payment is a class that holds the amount of money that a customer needs to pay.This is generated when the order is placed.
*/

#include <iostream>
using namespace std;

const int MaxMenuItems = 10;

class MenuItems
{
    private:
        string foodName;
        float foodPrice;
    public:
        bool isEmpty;
        MenuItems() {}
        MenuItems(string foodName, float foodPrice)
        {
            this->foodName = foodName;
            this->foodPrice = foodPrice;
            isEmpty = true;
        }

        string getFoodName()
        {
            return foodName;
        }

        float getFoodPrice()
        {
            return foodPrice;
        }

        void setFoodName(string foodName)
        {
            this->foodName = foodName;
        }

        void setFoodPrice(float foodPrice)
        {
            this->foodPrice = foodPrice;
        }
};

class Menu
{
    private:
        static int current_items;
    public:
        MenuItems menuList[MaxMenuItems];
        Menu()
        {
            for (int i = 0; i < MaxMenuItems; i++)
            {
                menuList[i] = MenuItems("", 0.0);
            }
        }

        void addItem(MenuItems item)
        {
            int emptyindex;
            int flag = 0;
            for (int i = 0; i < MaxMenuItems; i++)
            {
                if (menuList[i].isEmpty)
                {
                    emptyindex = i;
                    flag = 1;
                    menuList[emptyindex] = item;
                    menuList[emptyindex].isEmpty = false;
                    current_items++;
                    return;
                }
            }
            
            if (flag == 0)
            {
                cout << "Menu List is already full.\n";
                return;
            }
        }

        void removeItem(string itemName)
        {
            int flag = 0;
            for (int i = 0; i < MaxMenuItems; i++)
            {
                if (menuList[i].getFoodName() == itemName)
                {
                    menuList[i].setFoodName("");
                    menuList[i].setFoodPrice(0.0);
                    menuList[i].isEmpty = true;
                    flag = 1;
                    cout << itemName << " has been removed from the menu items.\n";
                    return;
                }
            }

            if (flag == 0)
            {
                cout << "Item not found in the list.\n";
            }
        }

        void displayMenu()
        {
            cout << "\nMenu:\n";
            for (int i = 0; i < MaxMenuItems; i++)
            {
                cout << i+1 << ". Item: " << menuList[i].getFoodName() << " - Price: $" << menuList[i].getFoodPrice() << "\n";
            }
        }

};

int Menu :: current_items = 0;

class Payment
{
    private:
        float amount;
    public:
        Payment(float amount)
        {
            this->amount = amount;
        }
        
        void displayPayment()
        {
            cout << "\nTotal Payment is: $" << amount << "\n";
        }
};

class Order
{
    private:
        MenuItems orderedItems[20];
        Payment *payment;
        int n_orderItems;

    public:
        Order() : payment(nullptr), n_orderItems(0)
        {
            for (int i = 0; i < 20; i++)
            {
                orderedItems[i] = MenuItems("", 0.0);
            }
        }

        void addMenuItem(const MenuItems &item)
        {
            int emptyindex;
            int flag = 0;

            for (int i = 0; i < 20; i++)
            {
                if (orderedItems[i].isEmpty)
                {
                    emptyindex = i;
                    flag = 1;
                    orderedItems[emptyindex] = item;
                    orderedItems[emptyindex].isEmpty = false;
                    n_orderItems++;
                    return;
                }
            }

            if (flag == 0)
            {
                cout << "Order List is full.\n";
                return;
            }
        }

        void totalTheOrder()
        {
            float total = 0.0;
            for (int i = 0; i < n_orderItems; i++)
            {
                total += orderedItems[i].getFoodPrice();
            }
            payment = new Payment(total);
        }

        void displayOrder()
        {
            cout << "\nOrder:\n";
            for (int i = 0; i < 20; i++)
            {
                if (!orderedItems[i].isEmpty)
                {
                    cout << i + 1 << ". " << orderedItems[i].getFoodName() << " - $" << orderedItems[i].getFoodPrice() << "\n";
                }
            }
            if (payment != nullptr)
            {
                payment->displayPayment();
            }
        }


        ~Order()
        {
            delete payment;
        }
};

class RestaurantOrderingSystem
{
    private:
        Menu menu;
    public:
        void addItemsToMenu()
        {
            menu.addItem(MenuItems("Chicken Tikka", 6.57));
            menu.addItem(MenuItems("Fries", 4.51));
            menu.addItem(MenuItems("BBQ Platter", 10.54));
            menu.addItem(MenuItems("Ice-Cream", 3.24));
            menu.addItem(MenuItems("Cake", 9.84));
            menu.addItem(MenuItems("Chowmin", 15.94));
            menu.addItem(MenuItems("Beef Steak", 16.87));
            menu.addItem(MenuItems("Beef Burger", 10.84));
            menu.addItem(MenuItems("Cheese Pasta", 7.04));
            menu.addItem(MenuItems("Chicken Broast", 6.81));
        }

        void displayMenu()
        {
            menu.displayMenu();
        }

        void takeUserOrder(Order &userOrder)
        {
            int choice;
            do
            {
                cout << "\nEnter the item number to order (0 to exit): ";
                cin >> choice;

                if (choice > 0 && choice <= MaxMenuItems)
                {
                    userOrder.addMenuItem(menu.menuList[choice - 1]);
                }
                else if (choice != 0)
                {
                    cout << "Invalid choice. Please enter a valid item number.\n";
                }
            } while (choice != 0);
        }

};



int main()
{
    RestaurantOrderingSystem kfc_system;

    kfc_system.addItemsToMenu();
    kfc_system.displayMenu();

    Order yourOrder;
    kfc_system.takeUserOrder(yourOrder);

    yourOrder.totalTheOrder();
    yourOrder.displayOrder();

    return 0;
}