/*
Constructors:
-Execute Automatically
-Initialize the object
-Share the class name
-Have no return type
-Constructors are not necesszary cpp puts them automatically
*/
#include <iostream>
using namespace std;

class Circle
{
  private: // From c++ 11 you can do initialization directly. e.g doble r =0; etc.
    double r;
    double PI;
    int *p;

  public:
    // Constructor(Same name. NO RETURN TYPE)
    Circle()
    {
        // Whatever code goes on istantiation time goes here.
        r = 0;
        PI = 3.14;
        p = new int; // Dynamic Memory allocation.
    }
    /*
      We could also do something like this:
      Circle() : r(0), PI(3.14), p(new int);
      We can combine and mix and match those initialization options.
     */
    // Mutator
    void set(double _r)
    {
        r = _r;
    }
    // Accessors
    double get() const
    {
        return r;
    }
    double getArea()
    {
        return 3.14159 * r * r;
    }
};

int main(void)
{
    Circle c;
    cout << c.get() << endl;
    return 0;
}
