/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Scenario 5
*/

#include <iostream>
#include <string>
using namespace std;

const int MaxMenuItems = 3;
const int MaxCouponCodes = 5;

class BOGOCoupon
{
    private:
        string coupon_code;
        int valid_from;
        int valid_till;
        string restaurant_code;
        bool redeemed;

    public:
        BOGOCoupon() {}
        BOGOCoupon(string coupon, int validFrom, int validTill, string restaurantCode)
            : coupon_code(coupon), valid_from(validFrom), valid_till(validTill), restaurant_code(restaurantCode), redeemed(false) {}

        bool is_valid(string res_code, int current_date)
        {
            return (!redeemed && res_code == restaurant_code && current_date >= valid_from && current_date <= valid_till);
        }

        string get_coupon_code()
        {
            return coupon_code;
        }

        bool is_redeemed()
        {
            return redeemed;
        }

        void redeem()
        {
            redeemed = true;
        }
};

class Restaurant
{
    private:
        string restaurantName;
        string location;
        string menuList[MaxMenuItems];
        double priceList[MaxMenuItems];

    public:
        double totalBill;

        Restaurant(string name, string loc, string menu[MaxMenuItems], double prices[MaxMenuItems])
        {
            restaurantName = name;
            location = loc;
            for (int i = 0; i < MaxMenuItems; i++) {
                menuList[i] = menu[i];
                priceList[i] = prices[i];
            }
        }

        void display_menu()
        {
            cout << restaurantName << " Menu:\n";
            for (int i = 0; i < MaxMenuItems; i++)
            {
                cout << i + 1 << "." << menuList[i] << " : Rs." << priceList[i] << "\n";
            }
            cout << "\n";
        }

        void generate_bill()
        {
            display_menu();
            cout << "Total Bill: Rs." << totalBill << "\n";
        }

        void add_item_to_bill(int item)
        {
            if (item >= 1 && item <= MaxMenuItems)
            {
                totalBill += priceList[item - 1];
                cout << "Item added to the bill.\n";
            } else {
                cout << "Invalid item selection.\n";
            }
        }

        void apply_discount(BOGOCoupon coupons_list[MaxCouponCodes], string coupon)
        {
            int count = 0;

            for (int i = 0; i < MaxMenuItems; i++)
            {
                for (int j = 0; j < MaxCouponCodes; j++)
                {
                    if (coupons_list[j].get_coupon_code() == coupon && coupons_list[j].is_valid(restaurantName, 0) && !coupons_list[j].is_redeemed())
                    {
                        count++;
                        break;
                    }
                }
            }

            if (count >= 2)
            {
                for (int i = 0; i < MaxCouponCodes; i++)
                {
                    if (coupons_list[i].get_coupon_code() == coupon && coupons_list[i].is_valid(restaurantName, 0) && !coupons_list[i].is_redeemed())
                    {
                        double discountAmount = priceList[i];
                        totalBill -= discountAmount;
                        cout << "Discount Applied: Rs." << discountAmount << "\n";

                        coupons_list[i].redeem();
                        return;
                    }
                }
            }
        }
};

class User
{
    private:
        string name;
        int age;
        int mobile_number;
        BOGOCoupon coupons_list[MaxCouponCodes];
        string redeemed_coupons_list[MaxCouponCodes];

    public:
        User(string userName, int userAge, int mobNumber) : name(userName), age(userAge), mobile_number(mobNumber) {}

        string get_name()
        {
            return name;
        }

        void Accumulate_coupon(BOGOCoupon &coupon)
        {
            int flag = 0;
            for (int i = 0; i < MaxCouponCodes; i++)
            {
                if (coupons_list[i].is_valid("", 0))
                {
                    coupons_list[i] = coupon;
                    cout << "Coupon was accumulated!\n";
                    flag = 1;
                    return;
                }
            }
        }

        bool Has_valid_coupon(string res_code, int current_date)
        {
            for (int i = 0; i < MaxCouponCodes; i++)
            {
                if (coupons_list[i].is_valid(res_code, current_date) && !coupons_list[i].is_redeemed())
                {
                    return true;
                }
            }
            return false;
        }

        bool redeem_coupon(string coupon_code)
        {
            for (int i = 0; i < MaxCouponCodes; i++)
            {
                if (coupons_list[i].get_coupon_code() == coupon_code && !coupons_list[i].is_redeemed())
                {
                    coupons_list[i].redeem();
                    redeemed_coupons_list[i] = coupon_code;
                    return true;
                }
            }
            return false;
        }
};

int main()
{
    cout << "Ibrahim Johar Farooqi\n23K-0074\n";
    string foodhaven_menu[] = {"Sushi", "Pad Thai", "Mango Tango"};
    double foodhaven_prices[] = {10.0, 8.0, 5.0};

    string pixelbites_menu[] = {"Binary Burger", "Quantum Quinoa,", "Data Donuts"};
    double pixelbites_prices[] = {7.0, 9.0, 6.0};

    BOGOCoupon foodHavenCoupon("FH-BOGO-12345", 0, 30, "Food Haven");
    BOGOCoupon pixelBitesCoupon("PB-BOGO-67890", 1, 25, "Pixel Bites");

    BOGOCoupon couponsList[MaxCouponCodes];
    couponsList[0] = foodHavenCoupon;
    couponsList[1] = pixelBitesCoupon;

    Restaurant pixelbites("Pixel Bites", "Cyber Street", pixelbites_menu, pixelbites_prices);
    Restaurant foodhaven("Food Haven", "City Center", foodhaven_menu, foodhaven_prices);

    User user1("Ashir", 19, 92324598);
    user1.Accumulate_coupon(foodHavenCoupon);

    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "Welcome:\n"
             << "1. Menu\n"
             << "2. Add Item\n"
             << "3. Receipt || Bill\n"
             << "4. Exit\n"
             << "Enter Choice: ";
        cin >> choice;

        int res;
        switch (choice)
        {
            case 1:
                cout << "Select restaurant\n"
                    << "1. Food Haven\n"
                    << "2. Pixel Bites\n"
                    << "Enter Restaurant Choice: ";
                cin >> res;
                cout << "\n";
                if (res == 1)
                    foodhaven.display_menu();
                else if (res == 2)
                    pixelbites.display_menu();
                break;
            case 2:
                cout << "Select restaurant to add item\n"
                    << "1. Food Haven\n"
                    << "2. Pixel Bites\n"
                    << "Enter Restaurant Choice: ";
                cin >> res;
                int item;
                cout << "Enter item number: ";
                cin >> item;

                if (res == 1)
                    foodhaven.add_item_to_bill(item);
                else if (res == 2)
                    pixelbites.add_item_to_bill(item);
                break;
            case 3:
                cout << "Select restaurant\n"
                    << "1. Food Haven\n"
                    << "2. Pixel Bites\n"
                    << "Enter Restaurant Choice: ";
                cin >> res;
                if (res == 1)
                {
                    foodhaven.generate_bill();

                    cout << "Do you want to apply a discount on your bill? (Y / N): ";
                    char applyDiscount;
                    cin >> applyDiscount;

                    if (applyDiscount == 'Y' || applyDiscount == 'y') {
                        string couponCode;
                        cout << "Enter the coupon code: ";
                        cin >> couponCode;
                        foodhaven.apply_discount(couponsList, couponCode);
                    }
                }
                else if (res == 2)
                {
                    pixelbites.generate_bill();

                    cout << "Do you want to apply a discount on your bill? (Y / N): ";
                    char applyDiscount;
                    cin >> applyDiscount;

                    if (applyDiscount == 'Y' || applyDiscount == 'y')
                    {
                        string couponCode;
                        cout << "Enter the coupon code: ";
                        cin >> couponCode;
                        pixelbites.apply_discount(couponsList, couponCode);
                    }
                }
                break;
            case 4:
                flag = false;
                break;
            default:
                cout << "Wrong option" << endl;
        }
    }

    return 0;
}
