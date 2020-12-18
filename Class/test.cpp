#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
class Circle {
private:
  double radius;
  double x, y;
  typedef struct object {
    string objects;
  } Obj;
  Obj obj;

public:
  Circle();
  Circle(double radius, double x, double y);
  double GetArea(Circle &);
  double GetPerimeter(Circle &);
  void Display();
};
void ss() { cout << "You are my sunshine."; }
int main(void) {
  Circle circle(2, 3, 3);
  Circle cir;
  double area = circle.GetArea(circle);
  double area1 = cir.GetPerimeter(cir);
  cout << area << endl;
  cout << area1 << endl;
  ss();
  for (int i = 0; i < 5; i++) {
    cout << "Never" << endl;
  }
  cir.Display();
  return 0;
}
double Circle::GetArea(Circle &circle) {
  double area = 3.14 * pow(circle.radius, 2);
  return area;
}

double Circle::GetPerimeter(Circle &circle) {
  double perimeter = 3.14 * 2 * circle.radius;
  return perimeter;
}

Circle::Circle() {
  radius = 1;
  x = y = 0;
  obj.objects = "wheel";
}

Circle::Circle(double radius, double x, double y) {
  this->radius = radius;
  this->x = x;
  this->y = y;
}

void Circle::Display() { cout << obj.objects; }
