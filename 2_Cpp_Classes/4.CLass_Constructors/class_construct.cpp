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
  private:
    double r;

  public:
    // Constructor(Same name. NO RETURN TYPE)
    Circle() // Constructor executes automatically. Test it!!!
    {
        r = 0;
        // cout << "THIS MESSAGE MEANS THAT THE CONSTRUCTORS IS EXECUTE AS SOON AS THE CLASS IS INITIALIZED!!!!!!!"
        << endl;
    }
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
/*
Alternative Constuctor Methods:
1.Member initialization list: Circle() : r(0.0);
If we have multiple variables Circle() : r(0.0), PI(3.14);
2.
*/
