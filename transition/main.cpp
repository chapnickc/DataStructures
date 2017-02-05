#include <iostream>
#include "RichPoint.h"
using namespace std;

int main(){

   RichPoint p(0,0);
   RichPoint q(1,1);
   RichPoint r(2,2);

   // this is bitwise copy
   // since we haven't overloaded the '=' operator
   p = q;

   //RichPoint& pref = p;
   //RichPoint& qref = q;
   //cout << "pref = " << pref << endl;
}
