#include <iostream>
using namespace std;

class Rectangle
{
private:
  double width;
  double height;
public:
  void setWidth(double); //mutators
  void setHeight(double);
  double getWidth() const; //accessors
  double getHeight() const;
  double getArea() const;
};

int main(void)
{
  cout << "This is my intro into classes. This program calculates different parameters of the class rectangle." << endl;
  Rectangle R;
  double w,h;
  cout << "WHAT IS THE HEIGHT:" << endl;
  cin >> h;
  cout << "WHAT IS THE WIDTH:" << endl;
  cin >> w;
  R.setHeight(h);
  R.setWidth(w);
  Rectangle* R2 = &R;
  cout << "HERE IS THE POINTER Rectangle Height: " << R2->getHeight() << endl;
  cout <<  "AREA: " << R.getArea() << "\tHEIGHT: " <<  R.getHeight() << "\tWIDTH: " << R.getWidth() << endl;
  return 0;
}


//We specify our functions here after the declaration on the class
void Rectangle::setWidth(double d)
{
  width = d;
}
void Rectangle::setHeight(double d)
{
  height = d;
}
double Rectangle::getWidth() const
{
  return width;
}
double Rectangle::getHeight() const
{
  return height;
}
double Rectangle::getArea() const
{
  return width * height;
}

