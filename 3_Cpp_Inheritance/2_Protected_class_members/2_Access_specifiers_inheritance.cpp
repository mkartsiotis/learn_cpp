/*
Cpp class inheritance access specifier keywords:
1. Public
2.Protected
3. Private
You already know them! But what and why do we say when creating derived classes : public ?
*/
class Foo
{
  private:
    int x;

  protected:
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
class Bar : private Foo // Why public???
/*
 Derived class member properties according to specifier:
 public: public members => public, protected => protected, private => private.
 protected: public => protected, protected => protected, private => private.
 private => everything becomes private.
The best thing you can do right now is change that specifier and see how the properties' access changes from the error
messages!
*/
{
  public:
    Bar()
    {
        // We can do this:
        setX(8);
        y = 8;  // Protected so fine
        z = 10; // Fine since z is public
    }
};
int main(void)
{
    // Check the difference with different access specifiers in the derived class.
    Bar b;
    b.x = 4;
    b.y = 2;
    b.z = 2;
    return 0;
}
/*
This was it! Now you should be able to understannd class access specifiers!
*/
