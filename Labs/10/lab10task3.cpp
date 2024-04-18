#include <iostream>
using namespace std;

class shape
{
    private:
        float area;
    public:
        shape(): area(10) {}

        shape operator+ (shape obj)
        {
            shape obj2;
            obj2.area = area + obj.area;
            return obj2;
        }

        void Area()
        {
            cout << "Area is " << area << "\n";
        }
};

int main()
{
    shape s1, s2;

    cout << "Area - Shape 1: ";
    s1.Area();
    cout << "Area - Shape 2: ";
    s2.Area();

    shape s3;
    s3 = s1 + s2;
    cout << "Area - Shape 3: ";
    s3.Area();

    return 0;
}
