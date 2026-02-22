/*
 Cpp access specifier keywords:
1. Public
2.Protected
3. Private
If you followed the lesson series you should by now be familiar with the private and the public keywords.
But what is protected?Today we will answer that question.
So now take a look at the example and read the comments. Does it appear natural to you?
*/
#include <iostream>
using namespace std;

class Foo
{
  private:
    int x;

  protected: // The first time you read this line you won't have a clue. Do not worry for now. You will come back once
             // you reach to the main point of the example that is adressed below.
    int y;

  public:
    int z;
    Foo() : x(0) // Class Constructor
    {
    }
    // Mutator
    void setX(int _x)
    {
        x = _x;
    }
    // Accessor
    int getX(void)
    {
        return x;
    }
};
// Now with class inheritance as we know by now we can do something like this:
// Derived class
class Bar : public Foo
{
  public:
    Bar()
    {
        // We can do this:
        setX(8);
        /*
        **But why can't I say**
        x = 0;
        Because x is private in the parent class and thus not accessible by external code.
        If you don't believe me dare to try it out!It will not compile.
        Now what if there was a keyword that made its parameters accessible to external child classes but not other
        code? Lucky for you there is and it is called  **protected:**
        */
    }
};
int main(void)
{
    Bar b;
    b.setX(); // Works well. Inheritance.
    b.getX(); // Works well. Inheritance.
    b.x = 4;  // Fine since x is private.
    b.y = 2;  // Wrong since it is protected. Note that y is accessible from the class bar that is the child class,
             //  but not by any other external code.
    b.z = 2; // Totally fine since z is public.
    return 0;
}
/*
 So what is protected?
 Protected is a hybrid of public and private in a sense that all the protected members of a class are visible to the
derived classes but not to external code. IMPORTANT: IF WE DISCOVER SOMETHING THAT WORKS DOES NOT MEAN THAT IT IS THE
ACCEPTED PRACTICE! So it is not a good practice to make many parameters protected instead of private since when setting
this parameters if there are restrictions we totally ignore them in the derived classesby avoiding use of the mutators.
It is better and safer in such cases to let the mutator function do the job.
*/
