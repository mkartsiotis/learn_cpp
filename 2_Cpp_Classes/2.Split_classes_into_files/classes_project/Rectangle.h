#include <iostream>
using namespace std;

class Rectangle {
private:
  double width;
  double height;

public:
  void setWidth(double); // mutators
  void setHeight(double);
  double getWidth() const; // accessors
  double getHeight() const;
  double getArea() const;
};
