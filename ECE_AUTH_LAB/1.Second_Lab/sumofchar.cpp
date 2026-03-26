#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string list1 = "123";
    string list2 = "345";
    int var1 = stol(list1);
    int var2 = stol(list2);
    cout << "SUM IS: " << (var1 + var2) << endl;
}
