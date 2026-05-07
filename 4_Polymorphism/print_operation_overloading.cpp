#include <iostream>
#include <ostream>
using namespace std;

class Rectangle
{
  private:
    float side_1, side_2;

  public:
    Rectangle(float s1, float s2);
    Rectangle operator+(Rectangle &op2);
    bool operator>(Rectangle &op2);
    float area() const;
    float getSide1() const
    {
        return side_1;
    }
    float getSide2() const
    {
        return side_2;
    }
    void set_Sides(float a, float b);
    friend void toZero(Rectangle &r);
    friend ostream &operator<<(ostream &os, const Rectangle &r);
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
Rectangle Rectangle::operator+(Rectangle &op2)
{
    float newSide1 = this->side_1 + op2.side_1;
    float newSide2 = this->side_2 + op2.side_2;
    Rectangle ReturnRec(newSide1, newSide2);
    return ReturnRec;
}
bool Rectangle::operator>(Rectangle &op2)
{
    return (this->area() > op2.area());
}
// Technique to do cout<<obj and print!!!
/*
 * We need to ask ourselves what should we do?
 * Normally it is Class-Operator-Argument
 * But now it is OS- OPerator_class
 * SO the operator should be global and the function should be declared as a friend function by the class
 */
ostream &operator<<(ostream &os, const Rectangle &r)
{
    os << "Rectangle [Width" << r.getSide1() << " Height" << r.getSide2() << " Area: " << r.area() << endl;
    return os;
}
int main()
{
    Rectangle R1(2, 1);
    cout << "Area 1 is: " << R1.area() << endl;
    Rectangle R2(3, 2);
    cout << "Area 2 is: " << R2.area() << endl;
    Rectangle R3 = R2 + R1;
    cout << "Area 3 is: " << R3.area() << endl;
    cout << "Is R1 > R2??" << (R1 > R2) << endl;
    cout << R1 << endl;
}
