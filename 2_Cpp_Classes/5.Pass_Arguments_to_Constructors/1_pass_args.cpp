#include <iostream>
using namespace std;
class Triangle
{
  private:
    double base;
    double height;

  public:
    // Constructor
    Triangle(double b, double h)
    {
        base = b;
        height = h;
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
    Triangle t(1.2, 3.4); // looks like a function but we are using a constructor b =1.2, h = 3.4
    // We can use an initialization list as well e.g. Triangle t {1.2, 3.4};
    cout << "Area: " << t.getArea() << endl;
    return 0;
}
