
/*
 Overloading constructors: Having multiple constructors for the same function so that according to the parameters we
have a different output. In that case we can call the class in a differnt way and get differnt results!!!!
*/
#include <iostream>
using namespace std;

class Circle
{
  private:
    double radius;

  public:
    // Default constructors
    Circle() : radius(0)
    {
        cout << "Entering the default constuctor" << endl;
    }
    // We can overload the constructor by using more than one constructors.
    // Overloaded Constructor:
    Circle(double r) : radius(r)
    {
        cout << "Entering the overloaded constuctor" << endl;
    }
    // mutator
    void setRadious(double r)
    {
        radius = r;
    }
    // Accessors
    double getRadius() const
    {
        return radius;
    }
};
int main()
{
    Circle c; // Using the default constructor
    cout << c.getRadius() << endl;
    Circle d(1.2); // Uses the overloaded constructor
    cout << d.getRadius() << endl;
    return 0;
}
