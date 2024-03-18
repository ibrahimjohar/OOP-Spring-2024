/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 17 March 2024
*   Description: Consider that You're working on Images to handle images in your graphics application. Each Image object contains a pointer to image data stored in memory.
*                You are asked to create Image Class: The Image class represents an image with width, height, and image data as private.
*                The data member represents the image data stored in memory. It's a pointer to a block of memory where the actual pixel values of the image are stored.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Image
{
    private:
        int width;
        int height;
        int* imageData;
    public:
        Image(int w, int h, int* data)
        {
            width = w;
            height = h;

            imageData = new int[width * height];
            memcpy(imageData, data, width*height*sizeof(int)); //copy provided image data in new dynamically allocated memory 
        }

        Image(const Image &obj) //copy constructor
        {
            width = obj.width;
            height = obj.height;

            imageData = new int[width * height];
            memcpy(imageData, obj.imageData, width*height*sizeof(int)); //copy provided image data in new dynamically allocated memory
        }

        ~Image() //destructor
        {
            delete[] imageData;
        }

        void display()
        {
            cout << "Image Specifications:\n";
            cout << "Width: " << width << "\n";
            cout << "Height: " << height << "\n";
            cout << "Image Data:\n";
            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                {
                    cout << imageData[i * width + j] << "   ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        void updateData()
        {
            for (int i = 0; i < width * height; ++i)
            {
                if (imageData[i] <= 0)
                {
                    imageData[i] = rand() % 255 + 1; //randomnly selects a number between 1 and 255
                }
            }
        }
};


int main()
{
    int data[] = {1, 2, 8, 7, 5, -6};

    //create original and copy of the original image
    Image originalImage(2, 3, data);
    Image copiedImage(originalImage);

    //display original image & copied image
    cout << "Original Image:\n";
    originalImage.display();

    cout << "Copied Image:\n";
    copiedImage.display();

    //update image data
    originalImage.updateData();
    copiedImage.updateData();

    //displaying original image after update
    cout << "Original Image after update:\n";
    originalImage.display();

    //displaying copied image after update
    cout << "Copied Image after update:\n";
    copiedImage.display();

    return 0;
}
