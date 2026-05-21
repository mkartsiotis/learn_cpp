#include <iostream>
#include <vector>
using namespace std;
class Player
{
  public:
    int a;
};
int main()
{
    Player P1;
    P1.a = 10;
    vector<Player> MyTeam;
    MyTeam.push_back(P1);
    cout << MyTeam.at(0).a << endl;
}
