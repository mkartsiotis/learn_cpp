#include <iostream>
class Point
{
  protected:
    float x, y;

  public:
    Point(float x, float y);
    ~Point();
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
};
class GooglePin : public Point
{
  protected:
    std::string label;

  public:
    GooglePin(std::string s, float x, float y) : Point(x, y), label(s);
    void setLabel(std::string s);
    float estimateDistance(float x2, float y2);
    float estimatePinDistance(GooglePin p);
};
class GooglePin3D : public GooglePin
{
  protected:
    float z;

  public:
    GooglePin3d(std::string s, float x_, float y_, float z_) : GooglePin(x_, y_), z(z_);
    void setLabel(std::string s);
    float estimateDistance3D(float x2, float y2, float z2);
    float estimatePinDistance3D(GooglePin3D p);
};
