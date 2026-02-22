#include "Rectangle.cpp"
int main(void) {
  cout << "This is my intro into classes. This program calculates different "
          "parameters of the class rectangle."
       << endl;
  Rectangle R;
  double w, h;
  cout << "WHAT IS THE HEIGHT:" << endl;
  cin >> h;
  cout << "WHAT IS THE WIDTH:" << endl;
  cin >> w;
  R.setHeight(h);
  R.setWidth(w);
  Rectangle *R2 = &R;
  cout << "HERE IS THE POINTER Rectangle Height: " << R2->getHeight() << endl;
  cout << "AREA: " << R.getArea() << "\tHEIGHT: " << R.getHeight()
       << "\tWIDTH: " << R.getWidth() << endl;
  return 0;
}
