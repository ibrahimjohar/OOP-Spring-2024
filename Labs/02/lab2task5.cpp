/*
*   Programmer : Ibrahim Johar Farooqi
*   Date: 5 February 2024
*   Description: Your assignment is to construct a basic product management system for an online store. 
*                1. Develop a function that enables the addition of a new product to the system.
*                The function should accept parameters such as product name, price, quantity, and any other relevant details.
*                2. Implement a function that takes a product ID as input and displays detailed information about the product, including its name, price,
*                quantity in stock, and any other relevant details.
*                3. Design a function that allows the update of product information. It should accept a product ID and the new details (e.g., updated price, quantity, etc.) and modify
*                the existing product’s information accordingly.
*/

#include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    int quantity;
    float price;
    int id;
};

//function to input product information
void input_product(struct Product *productinfo) 
{
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, productinfo->name);
    cout << "Enter Product ID: ";
    cin >> productinfo->id;
    cout << "Enter Product Price: ";
    cin >> productinfo->price;
    cout << "Enter Product Quantity: ";
    cin >> productinfo->quantity;
    cout << "Product successfully added.";
    cout << "\n";    
}

//function to output the product information according to the ID provided
void display_productinfo(struct Product *productinfo, int size_arr, int search_id)
{
    int flag = 0;
    for (int i = 0; i < size_arr; i++)
    {
        if (productinfo[i].id == search_id)
        {
            flag = 1;
            cout << "Product Name: " << productinfo[i].name;
            cout << "\nProduct ID: " << productinfo[i].id;
            cout << "\nProduct Price: " << productinfo[i].price;
            cout << "\nProduct Quantity: " << productinfo[i].quantity;
            cout << "\n";
        }
        else
        {
            flag = 0;
            continue;
        }
    }

    if (flag == 0)
    {
        cout << "Product ID not found in system.\n";
    }
}

//function to update existing record of a product with the provided ID
void update_productinfo(struct Product *&productinfo, int size_arr, int update_id)
{
    int flag = 0;
    for (int i = 0; i < size_arr; i++)
    {
        if (productinfo[i].id == update_id)
        {
            cout << "Product ID: " << productinfo[i].id << " Found!\n"; 
            flag = 1;
            cout << "Updated Product Name: ";
            cin.ignore();
            getline(cin,productinfo[i].name);
            cout << "Updated Product ID: ";
            cin >> productinfo[i].id;
            cout << "Updated Product Price: ";
            cin >> productinfo[i].price;
            cout << "Product Quantity: ";
            cin >> productinfo[i].quantity;
            cout << "\n";
        }
        else
        {
            flag = 0;
            continue;
        }
    }

    if (flag == 0)
    {
        cout << "Product ID not found in system.\n";
    }
}

//function to add product
void add_product(struct Product *&productinfo, int &size_arr)
{
    size_arr++;
    Product *increased_productinfo = new Product[size_arr]; //use of dma to initialise inceased size array
    for (int i = 0; i < size_arr - 1; i++)
    {
        increased_productinfo[i] = productinfo[i]; 
    }

    delete[] productinfo; //free memory of original dma initialised array
    input_product(&increased_productinfo[size_arr - 1]);
    productinfo = increased_productinfo;
}

int main()
{
    int size_arr = 0; 
    Product *productinfo = new Product[size_arr]; 

    int menu;
    
    do
    {
        cout << "Product Management System for an Online Store!\n1. Add a new Product Information\n2. Update Product Information\n3. Display Product Information\n";
        cout << "Enter main menu option (press any other key except 1, 2, 3 to exit): ";
        cin >> menu; 

        switch (menu)
        {
        case 1:
            add_product(productinfo, size_arr);
            break;
        case 2:
            int update_id;
            cout << "Enter Product ID to update that Product: ";
            cin >> update_id;
            update_productinfo(productinfo, size_arr, update_id);
            break;
        case 3: 
            int search_id;
            cout << "Enter Product ID to display product information: ";
            cin >> search_id;
            display_productinfo(productinfo, size_arr, search_id);
            break;
        default:
            cout << "\nManagement System is shutting down now!\n";
            break;
        }
    }while(menu == 1 || menu == 2 || menu == 3);

    delete[] productinfo; //free memory of dma initialised array
    return 0;
}
