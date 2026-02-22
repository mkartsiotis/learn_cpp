/*
Destructor: The code of the destructor is executed when the class is destoyed. We put here code to delete the array)
Remember!Constructors allocate resources. Destructors release resources.
It would be pointless to use parameters in the distructors, since they execute automatically just before the object
leaves the memory. We cannot overload destructors(only one per class)

Dynamically memory allocation works in a pretty similar way but the destructor jumps when we call delete ptr.
*/

#include <iostream>
using namespace std;

class Numbers
{
  private:
    int *p;
    int size;

  public: // Interface
    // Constructor. Dynamically allocates memory to store the number array.
    Numbers()
    {
        size = 5;
        p = new int[size];
        cout << "Now entering the constructor" << endl;
    }
    // Destructor:
    ~Numbers()
    {
        delete[] p; // Frees the allocated space for the  array.
        cout << "Now entering the destructor" << endl;
    }
    // Mutators:
    void setN(int i, int v)
    {
        p[i] = v;
    }
    // Accessors:
    int getN(int i) const
    {
        return p[i];
    }
    // Note that in all cases in this example we are using inline initialization of functions
    // For more complex cases we always declare into the class and define the function outside.(Do not forget the class
    // specification!!!!Class::Function)
};

/*
void class_call_function(void);
void class_call_function(void)
{
    cout << "Entering the function\n";
    Numbers n;
    for (int i = 0; i < 5; i++)
        n.setN(i, i * i);
    for (int i = 0; i < 5; i++)
        cout << n.getN(i) << " ";
    cout << "Leaving the function\n";
}
*/
int main(void)
{
    // Allocate
    Numbers *nptr = new Numbers;
    // Clean up the memory
    delete nptr;
    return 0;
}

/*As you can notice the constructor is called just after the memory allocation and the destructor just before the memory
 * is released.
 */
