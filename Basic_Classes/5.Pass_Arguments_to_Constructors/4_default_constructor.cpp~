/*
This example showcases what not to do while working with constructors.
The idea is that when you use multiple constructors you cannot have 2 default ones(with pre-initoialized parameters).
Try to compile this program and see why. Default constructor parameters: -They are set in case the arguments are not
called. -So default constructors can be called with parameters or not IMPORTANT: -Careful when using 2 constructors and
they are both default. It will not compile!(see next example)
*/
#include <iostream>
using namespace std;
class Triangle
{
  private:
    double base;
    double height;

  public:
    // Note that here we have 2 default constructors Constructor
    Triangle()
    {
        base = 0;
        height = 0; // Second default constructor
    }
    Triangle(double b = 0.0, double h = 0.0) : base(b), height(h)
    {
    }
    void setBase(double b);
    void setHeigbht(double h);
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
