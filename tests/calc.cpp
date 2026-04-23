#include <iostream>
#include "calc.h"
using namespace std;

int main()
{
  Chessboard ch;
  ch.print();
}
void set_pawn_to_pos(char y, char x)
{
}
Chessboard::Chessboard() : is_visible(true)
{
  for(int i =0;i < 8;i++)
    for(int j = 0;j < 8;j++)
      box[i][j] = 0;
}
Chessboard::~Chessboard()
{
}
void Chessboard::set_pawn_to_pos(char y, char x)
{
  box[y - 'a'][x - 1] = 1;
}
void Chessboard::print() 
{
  for(int i =0;i < 8;i++)
  {
    char letter = i + 'a';
    for(int j = 0;j < 8;j++)
    {
      cout << "\e[31m" << letter << "\e[0m" << "\e[38;2;0;150;255m" << j << "\e[0m" << "\e[32m"<< '|' << "\e[0m";
    }
    cout << endl;
  }
}
