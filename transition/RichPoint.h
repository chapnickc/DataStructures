#ifndef RICHPOINT_H
#define RICHPOINT_H
#include <iostream>
using namespace std;

class RichPoint {

    private:
        double _x;
        double _y;

    public:
        RichPoint(double initialX=0.0, double initialY=0.0);
        double getX() const;
        double getY() const;
        void setX(double val);
        void setY(double val);

        void scale(double factor);
        double distance(const RichPoint other) const;
        void normalize();
        RichPoint operator+(const RichPoint other) const;
        RichPoint operator*(const double factor) const;  // scalar multiple
        double operator*(const RichPoint other) const; // dot product

};


// notice these are outside of the class
// "binary operators" usually have something to 
// the left and right

// Here we are defining the functinality of 
// number * p
RichPoint operator*(double factor, RichPoint p);

// for an instance P, this defines the functionality
// cout  << p
ostream& operator<<(ostream& out, RichPoint p);
#endif
