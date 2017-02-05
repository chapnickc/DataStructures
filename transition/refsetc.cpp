#include "RichPoint.h"
#include <iostream>
using namespace std;

/* Call by value and call by reference
 * stricktly speaking we are still making a copy
 * to the reference
 *

 *
 */

// void printScaled(RichPoint* p) {
// void printScaled(const RichPoint& p) {
// void printScaled(RichPoint& p) {
//
// ask yourself, if p will be modified. The answer is no

// References are "like a number"

/* The big problem here is that copying 
 * is inefficient if the objects are big
 */
void printScaled(RichPoint p) {
  p.scale(1.0/p.distance(RichPoint(0,0)));
  cout << p << endl;
}

/* We don't want the original object to change */
// this will noot compile as is since we need a 
// copy
/*
void printScaled(const RichPoint& p) {
  p.scale(1.0/p.distance(RichPoint(0,0)));
  cout << p << endl;
}
*/


/*
void printScaled(RichPoint* p) {
  (*p).scale(1.0/p->distance(RichPoint(0,0)));
  cout << *p << endl;
}
*/



int main() {

  RichPoint p(0,0);
  RichPoint q(1,1);
  RichPoint r(2,2);
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;
  cout << "r = " << r << endl;

  RichPoint* pptr = &p;
  RichPoint* qptr = &q;
  RichPoint* rptr = &r;
  cout << "pptr = " << pptr << endl;
  cout << "qptr = " << qptr << endl;
  cout << "rptr = " << rptr << endl;

  RichPoint& pref = p;
  RichPoint& qref = q;
  RichPoint& rref = r;
  cout << "pref = " << pref << endl;
  cout << "qref = " << qref << endl;
  cout << "rref = " << rref << endl;

  cout << "and now bitwise copy q to p" << endl;
  p = q;
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;
  cout << "pptr = " << &p << endl;
  cout << "qptr = " << &q << endl;

  cout << "and now copy via reference, not like Python!" << endl;
  qref = rref;
  cout << "q = " << q << endl;
  cout << "r = " << r << endl;
  cout << "qref = " << qref << endl;
  cout << "rref = " << rref << endl;
  cout << "qptr = " << &q << endl;
  cout << "rptr = " << &r << endl;

  cout << "p, scaled to unit length: ";
  printScaled(p);
  cout << "original p= " << p << endl;
}
