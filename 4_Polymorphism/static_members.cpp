#include <iostream>
#include <ostream>
using namespace std;

class Rectangle
{
  private:
    float side_1, side_2;
    static int obj_total_number;

  public:
    static void increase_total_num();
    Rectangle()
    {
        cout << "REC INITIALIZED" << endl;
        increase_total_num();
    }
    Rectangle(float s1, float s2);
    float area() const;
    static void printTotalNumber();
    void set_Sides(float a, float b);
    friend void toZero(Rectangle &r);
    ~Rectangle();
};

int Rectangle::obj_total_number = 0;
Rectangle::Rectangle(float s1, float s2)
{
    cout << "REC INITIALIZED WITH PARAMETERS" << endl;
    side_1 = s1;
    side_2 = s2;
    increase_total_num();
}
Rectangle::~Rectangle()
{
    obj_total_number--;
}
float Rectangle::area() const
{
    return side_1 * side_2;
}
void Rectangle::set_Sides(float a, float b)
{
    side_1 = a;
    side_2 = b;
}
void toZero(Rectangle &r)
{
    r.side_1 = 0;
    r.side_2 = 0;
}
void Rectangle::increase_total_num()
{
    obj_total_number++;
}
void Rectangle::printTotalNumber()
{
    cout << obj_total_number << endl;
}
int main()
{
    Rectangle R(3.2, 12);
    cout << R.area() << endl;
    Rectangle **R1 = new Rectangle *[10];
    cout << "Just 1 object initialized" << endl;
    for (int i = 0; i < 10; i++)
        R1[i] = new Rectangle(i + 1, i);
    cout << "ARRAY OF 10 objects initialized" << endl;
    Rectangle::printTotalNumber();
    for (int i = 0; i < 10; i++)
        delete R1[i];
    cout << "Deleted the objects" << endl;
    Rectangle::printTotalNumber();
    delete[] R1;
    cout << "Deleted the pointer as well" << endl;
    Rectangle::printTotalNumber();
}
