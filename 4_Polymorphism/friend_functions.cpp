#include <iostream>
#include <ostream>
using namespace std;

class Rectangle
{
  private:
    float side_1, side_2;

  public:
    Rectangle(float s1, float s2);
    float area() const;
    void set_Sides(float a, float b);
    friend void toZero(Rectangle &r);
    ~Rectangle();
};

Rectangle::Rectangle(float s1, float s2)
{
    side_1 = s1;
    side_2 = s2;
}
Rectangle::~Rectangle()
{
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
int main()
{
    Rectangle R(3.2, 12);
    cout << R.area() << endl;
    toZero(R);
    cout << R.area() << endl;
    cout << "HELLO" << endl;
}
