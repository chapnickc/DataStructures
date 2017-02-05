#include "Vector3D.h"
#include "VectorND.h"
#include <iostream>
using namespace std;

const int ndim = 3;
const char axes[] = "xyz";
float coordinate;

Vector3D v3D;
VectorND vND;


int main(void){
   for (int i=0; i < ndim; i++){
        cout << "Please enter the " << axes[i] << " axis coordinate: "<< endl;
        cin >> coordinate;
        v3D.setCoordinate(i, coordinate);
    }

    for (int i=0; i < ndim; i++){
        cout << " " << axes[i] <<": " << v3D.getCoordinate(i);
    }
    cout << endl; // newline

    v3D.setCoordinate(4, 10.0);
    cout << "fourth element of v3D: " << v3D.getCoordinate(4) << endl;

    cout << "Length of v3D: " << v3D.getLength() << endl;
    cout << "testing << overload:\n"  << v3D << endl;
    return 0;
}
