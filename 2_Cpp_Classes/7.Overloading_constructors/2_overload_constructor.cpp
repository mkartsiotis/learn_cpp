/*
  Overloading constructors: Having multiple constructors for the same function so that according to the parameters we
have a different output. In that case we can call initialize class in a differnt way(with more or less parameters and
get the results we want that may as well vary) In this file we will showcase one common multiple constructor technique
that uses a chain constructor method.
*/
#include <iostream>
using namespace std;

class Circle
{
  private:
    double radius;
    double thickness;

  public:
    // Default constructor:
    Circle() : Circle(0) // Same as Circle() : radius(0). But we can throw one constructor away!!(its code)
    {
        cout << "Entering the default constuctor" << endl;
    }
    // We can overload the constructor by using more than one constructors.
    // Overloaded Constructor:
    Circle(double r) : Circle(r, 0)
    {
        cout << "Entering the first overloaded constuctor" << endl;
    }
    // Second overloaded constructor
    Circle(double r, double th) : radius(r), thickness(th)
    {
        cout << "Entering the second overloaded constuctor" << endl;
    }
    // mutator
    void setRadius(double r)
    {
        radius = r;
    }
    // Accessors
    double getRadius() const
    {
        return radius;
    }
    double getThickness() const
    {
        return thickness;
    }
};
int main()
{
    cout << "First Circle" << endl;
    Circle c;
    cout << c.getRadius() << ", " << c.getThickness() << endl;

    cout << "Second Circle" << endl;
    Circle d(2.1);
    cout << d.getRadius() << ",  " << d.getThickness() << endl;

    cout << "Third Circle" << endl;
    Circle e(3.3, 1.2);
    cout << e.getRadius() << ", " << e.getThickness() << endl;
    return 0;
}
/*Notes:
  1. Run the program.What do you notice?
-We can clearly see going from one constructor to the other. This reflects the program sice we call the second
constructor to accomplish the task of the first constructor. And then we call the third constructor to accomplish its
task. This not only is allowed but it is a very common practice in such cases.
 */
