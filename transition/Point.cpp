#include "Point.h"
// 'this' is a pointerr to the current object

// we are defining here, as opposed to declaring
Point::Point() {
   _x = 0;
   _y = 0;
}
Point::Point(double x, double y) {
   _x = x;
   _y = y;
}

// '::' is a scoping operator
//double Point::getX() const {
double Point::getX(){
   if (_x < 0) {
      _x = 0;
   }
   return _x;
}

double Point::getY() const {
   return _y;
}

void Point::setX(double val) {
   (*this)._x = val;
}

void Point::setY(double val) {
   _y = val;
}
