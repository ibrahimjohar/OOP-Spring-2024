/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 4 March 2024
*   Description: Create a class called ValidateString. The purpose of this class will be check if the given characters in a string are alphabet only.
*                Numbers and symbols will mean that the string is invalid. By using a parameterized constructor, create multiple objects for your class that accept
*                different strings. Create a constant function that checks whether the string variable is valid or not.
*                What happens if you do not make your function constant? Add a comment right above your function explaining why we make a function constant.
*/

#include <iostream>
#include <cctype>
using namespace std;

class ValidateString
{
    private:
        string stringVar;
    public:
        ValidateString(string stringVar)
        {
            this->stringVar = stringVar;
        }

        //a function is made 'const' so that it can never modify data memebers in an object,
        //if a function is not made constant then there is a chance the function might modify the data members in an object
        bool isStringValid() const //function to check string validity 
        {
            for (char c : stringVar) //iterate through the string to check if all characters are alphabets
            {
                if (!isalpha(c))
                {
                    return false;
                }
            }
            return true;
        }

        string get_string() const
        {
            return stringVar;
        }
};

int main()
{
    ValidateString str1("Ibrahim");
    if (str1.isStringValid())
    {
        cout << "[" << str1.get_string() << "] is valid as it has only alphabets.\n";
    }
    else
    {
        cout << "[" << str1.get_string() << "] is not valid as it does not only contain alphabets.\n";
    }


    ValidateString str2("Symbols-23K-0074");
    if (str2.isStringValid())
    {
        cout << "[" << str2.get_string() << "] is valid as it has only alphabets.\n";
    }
    else
    {
        cout << "[" << str2.get_string() << "] is not valid as it does not only contain alphabets.\n";
    }

    return 0;
}