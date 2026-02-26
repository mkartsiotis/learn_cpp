#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string name;
  std::cout << "Enter name" << endl;
  std::cin >> name;
  if (name == "Macro") {
    std::cout << "BINGO" << endl;
  }
  return 0;
}    
