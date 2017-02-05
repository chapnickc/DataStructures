#include <iostream>
using namespace std;
#include "Point.h"

int main(){
   Point p;
   p.setX(10);
   p.setY(20);

   cout << "p = (" << p.getX() << "," << p.getY() << ")" << endl;
   return 0;
}
