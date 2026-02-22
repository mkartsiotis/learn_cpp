/* Pros and Cons:
   1. For easy code it is faster to write and easier to read.
   2. Quick execution. Because for repettive calls the logic is differnt.
   The compiler does not copy-paste during execution. It copy pastes before execution.
   Cons:
   Copy-pasting before compilation results in bigger file names.
*/
#include <cstdlib> //For exit
#include <iostream>
using namespace std;
// INLINE: DEFINITION INSIDE THE CLASS DECLARATION!!!
class Square
{
  private:
    double side;

  public:
    void setSide(double); // Mutator
    // Accessors
    double getSide()
        const // NOTE: WE NEVER EVER SAY Square::getSide when doing inline declarations. Be very careful!!!!!
    {
        return side;
    }
    double getArea() const
    {
        return side * side;
    } // yes
};

int main(void)
{
    Square s;
    s.setSide(1.1);
    cout << s.getSide() << endl;
}

void Square::setSide(double s)
{
    if (s > 0)
        side = s;
    else
        exit(EXIT_FAILURE);
}
