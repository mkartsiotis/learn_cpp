#include <iostream>
#include <string>
using namespace std;

class Matrix
{
  private:
    int size;

  public:
    // Accessors
    int getSize(void) const
    {
        return size;
    }
    // Mutator
    void setSize(int s)
    {
        size = s;
    }
    void sortMatrix(void);
};

int main(void)
{
    string s = "";
    s += "HELLO bdhsd hdsajhduj jsuhu jhsahu hbsh jsgcjs hbcsha jascjb";
    int index = s.find(' ');
    while (index != string::npos)
    {
        s.replace(index, 1, "%20");
        index = s.find(' ');
    }

    cout << "STRING IS:\n" << s << endl;
    cout << "HELLO" << endl;
    return 0;
}
