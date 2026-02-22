/*
This exaple showcases the class inheritance concept.
It is crucial to highlight here that we are going to use some non-practical names for our classes since the scope of
this example is to show the technique. Remember to always carefully select your class names. This is vital to ensure the
readbility of your code and increase the chances or reusability in the future. Class inheritance has indeed many
applications and its primary usecase is prevention of code duplication.
*/
#include <iostream>
using namespace std;

class Foo
{
  private:
    int x;

  public:
    void setX(int _x)
    {
        x = _x;
    } // mutator
    int getX() const
    {
        return x;
    } // Accessor
};
// Now if we want to create another class that has the same properties with class Foo, we would have to copy-paste the
// exact same code. But, with class inheritance we can define the new class as a "subclass" of the original andthus
// force all the original properties to be inherited by the new class Here is how this is done

// The is-a relationship
// Class bar is a Foo. Bar is the child class or the derived class. Class Foo is the parent class
class Bar : public Foo // What class am I inheriting the properties from.
{
  private:
    int y;

  public:
    // Mutator
    void setY(int _y)
    {
        y = _y;
    }
    // Accessor
    int getY()
    {
        return y;
    }
};

int main(void)
{
    Bar b;
    b.setX(8); // We cannot see setX in the class declaration it is an inherited property
    b.setY(6);
    cout << "X is: " << b.getX() << " Y is: " << b.getY() << endl;
    // We can still create a Foo class
    Foo f;
    f.setX(4);
    cout << "X is: " << b.getX() << endl;
}

// Here we can ddefine our functions
