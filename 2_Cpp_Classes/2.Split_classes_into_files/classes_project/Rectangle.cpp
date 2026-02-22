#include "Rectangle.h"
// We specify our functions here after the declaration on the class
void Rectangle::setWidth(double d) { width = d; }
void Rectangle::setHeight(double d) { height = d; }
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }
double Rectangle::getArea() const { return width * height; }
