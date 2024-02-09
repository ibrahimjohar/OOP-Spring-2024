#include <iostream>
#include <string>
using namespace std;

class BoardMarker
{
    private:
    string brand;
    string shade;
    bool refillable;
    bool inkstatus;

    public:
    void set_brand(string brandname)
    {
        brand = brandname;
    }
    void set_shade(string shadename)
    {
        shade = shadename;
    }
    void set_refill(bool refillstatus)
    {
        refillable = refillstatus;
    }
    void set_ink(bool ink)
    {
        inkstatus = ink;
    }

    string get_brand()
    {
        return brand;
    }
    string get_shade()
    {
        return shade;
    }
    bool get_refill()
    {
        return refillable;
    }
    bool set_ink()
    {
        return inkstatus;
    }

    void write()
    {
        if (inkstatus)
        {
            cout << "Writing with " << brand << " marker in " << shade << " shade.\n";
        }
        else
        {
            cout << "Ink is finished. Refill the marker.\n";
        }
    }

}

int main()
{

}
