/*
Default constructor parameters:
-They are set in case the arguments are not called.
-So default constructors can be called with parameters or not
IMPORTANT:
-Careful when using 2 constructors and they are both default. It will not compile!(see next example)
*/
#include <iostream>
using namespace std;
class Triangle
{
  private:
    double base;
    double height;

  public:
    // Constructor
    Triangle(double b = 0.0, double h = 0.0)
        : base(b), height(h) // By using the deafult arguments we can make the costructor a default constructor.(see
                             // beginning for warnings.)
    {
    }
    // Mutators(WE are doing inline for this simple example)
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
    Triangle *tptr = new Triangle{2.0, 0.0}; // looks like a function but we are using a constructor b =1.2, h = 3.3
    cout << "Area: " << tptr->getArea() << endl;
    delete tptr; // Frees the meory space
    return 0;
}
