/*What we want to see with this example is the order in which constructors and destructors are executed.
  Run the code and see for yourself!(theory in the end of the file)
 */
#include <iostream>
using namespace std;
class Base
{
  private:
    int a, b;

  public:
    Base() : a(0), b(0)
    {
        cout << "Base Constructor \n";
    }
    Base(int x, int y) : a(x), b(y)
    {
        cout << "Base Constructor 2\n";
    }
    // Accessor
    void print() const
    {
        cout << a << " , " << b << endl;
    }
    ~Base()
    {
        cout << "Base Destructor\n";
    }
};

// Derived class
class Derived : public Base
{
  public:
    Derived()
    {
        cout << "Derived constructor\n";
    }
    ~Derived()
    {
        cout << "Derived Destructor\n";
    }
};

int main(void)
{
    // We are using dynamic memmory allocation
    cout << "Construct!\n";
    Derived *p = new Derived; // Triggers the constructor
    cout << "Destruct!\n";
    delete p; // Triggers the destructor
    return 0;
}

/*
**Theory:**
Order of execution:
1.Base class constructor
2.Derived class constructor
3.Derived class destructor
4.Base class destructor
It is like the derived class constructor is nested!
 */
