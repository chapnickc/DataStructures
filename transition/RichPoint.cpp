#include "RichPoint.h"
#include <cmath>
/*
*/



// _x and _y are initialized by passing initialX and 
// initialY to the constructor of the two objects
RichPoint::RichPoint(double initialX, double initialY) : _x(initialX), _y(initialY) { }

double RichPoint::getX() const {
   return _x;
}

double RichPoint::getY() const {
   return _y;
}

void RichPoint::setX(double val) {
   _x = val;
}

void RichPoint::setY(double val) {
   _y = val;
}

void RichPoint::scale(double factor) {
   _x *= factor;
   _y *= factor;
}

// added const and & to function paraameters
//
double RichPoint::distance(const RichPoint& other) const {
   // note acccessing the private 
   // attributes of the other object // since we are in the implementation
   double dx = _x - other._x;
   double dy = _y - other._y;
   return sqrt(dx*dx + dy*dy);
}

void RichPoint::normalize() {
   double mag = distance(RichPoint(0.0,0.0));
   if (mag > 0) {
      scale(1.0/mag);
   }
}

RichPoint RichPoint::operator+(const RichPoint& other) const {
   return RichPoint(_x + other._x, _y + other._y);
}

RichPoint RichPoint::operator*(double factor) const {
   return RichPoint(_x * factor, _y * factor);
}

double RichPoint::operator*(const RichPoint& other) const {
   return _x * other._x + _y * other._y;
}

RichPoint operator*(double factor, RichPoint p) {
   return p * factor;
}


// note, since these are not methods, you don't have
// access to private data
ostream& operator<<(ostream& out, RichPoint p) {
   out << "<" << p.getX() << "," << p.getY() << ">";
   return out;
}
