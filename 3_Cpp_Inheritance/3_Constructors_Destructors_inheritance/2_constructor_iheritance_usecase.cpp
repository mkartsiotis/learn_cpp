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
    int s;

  public:
    Derived(int q, int r, int x) : Base(q, r) // We want to pass those onto the base constructor
    {
        s = x;
    }
    int getS()
    {
        return s;
    }
    ~Derived()
    {
    }
};

int main(void)
{
    // We are using dynamic memmory allocation
    cout << "Construct!\n";
    Derived d(8, 3, 1); // This moves the arguments.
    d.print();
    cout << "S: " << d.getS() << endl;
    cout << "Destruct!\n";
    return 0;
}
