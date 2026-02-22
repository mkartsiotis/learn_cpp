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
    }
    Base(int x, int y) : a(x), b(y)
    {
    }
    // Accessor
    void print() const
    {
        cout << a << " , " << b << endl;
    }
    ~Base()
    {
    }
};

// Derived class
class Derived : public Base
{
  private:
    // To inherit the constructor and destructor in private members space we just do:
    using Base::Base;
    // Note that this invokes the Bse constructor according to the parameters of the Derived constructor.
    // If we add a separate Derived constructor both will be executed. First the base and then the default.
  public:
};

int main(void)
{
    // We are using dynamic memmory allocation
    cout << "Construct!\n";
    Derived d(8, 3); // This moves the arguments.
    d.print();
    cout << "Destruct!\n";
    return 0;
}
