#include<iostream>
using namespace std;

class GooglePin
{
private:
  string label;
  float x;
  float y;
public:
  string getLabel() const;
  float getX() const;
  float getY() const;
  void setX(float _x)
  {
    x = _x;
  }
  void setY(float _y)
  {
    y = _y;
  }
  void setLabel(string s)
  {
    label = s;
  }
  void status()
  {
    cout << "OBJ name: " << label << " X: " << x << " Y: " << y << endl; 
  }
  float estimateDistance(float x1, float y1);
  float estimatePinDistance(const GooglePin& P);
  GooglePin(string s, float a, float b);
  ~GooglePin();
};
int main(void)
{
  class GooglePin P1("a", 0, 0), P2("B", 100, 100);
  P1.status();
  cout << "DIS: " << P1.estimatePinDistance(P2) << endl;
}
GooglePin::GooglePin(string s, float a, float b) : label(s), x(a), y(b)
{
  cout << "Constructed" << endl;
}
GooglePin::~GooglePin()
{
  cout<< "Destructed: " << label << endl;
}

float GooglePin::getX() const
{
  return x;
}
float GooglePin::getY() const 
{
  return y;
}
float GooglePin::estimateDistance(float x1, float y1)
{
  return (x - x1) * (x - x1) + (y - y1) * (y - y1);
}
float GooglePin::estimatePinDistance(const GooglePin& P)
{
  return estimateDistance(P.getX(), P.getY());
}
