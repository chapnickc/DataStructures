#include <iostream> 
#include "LabeledPoint.h"
using namespace std;

int main(){
    LabeledPoint p(1.0, 2.0, "Kevin");
    LabeledPoint q(3.0, 5.0, "Chad");
    LabeledPoint r(3.0, 6.0);

    r.setX(5.1);

    cout << r << endl;

}
