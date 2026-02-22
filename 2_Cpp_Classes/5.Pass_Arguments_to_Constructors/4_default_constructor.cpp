/*
This example focuses on creating a constructor conventionally without using inline declarations.
The constructor that we are going to create is a default constructor.
This constructor is set ouside but is declarted inside the class the class declaration as you can see below.
*/
#include <iostream>
using namespace std;
class Triangle
{
  private:
    double base;
    double height;

  public:
    // Be very careful!The default values go in the declaration.
    // In the initialization brackets we do not need the = 0.
    // Any other way(in other words not putting the default values on the declaration)leads to compilation issues.
    Triangle(double b = 0, double h = 0);
    void setBase(double b);
    void setHeight(double h);
    // Accessors
    double getBase() const
    {
        return base;
    }
    double getHeight() const
    {
        return height;
    }
    double getArea() const
    {
        return 0.5 * base * height;
    }
};

int main(void)
{
    Triangle *tptr = new Triangle(); // The problem is when we try to call the constructor without arguments.
    cout << "Area: " << tptr->getArea() << endl;
    delete tptr; // Frees the meory space
    return 0;
}

// Here we have the non-inline initialized constructor:
// Note that we can use the good practice of initializing the private variables ouside the costructor's body.
Triangle::Triangle(double b, double h) : base(b), height(h)
{
}
