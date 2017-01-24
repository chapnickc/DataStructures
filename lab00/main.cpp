#include "Vector3D.h"
#include <iostream>
using namespace std;

const int ndim = 3;
const char axes[] = "xyz";

float coordinate;
Vector3D v;

int main(void){
  for (int i=0; i < ndim; i++){
    cout << "Please enter the " << axes[i] << " axis coordinate: "<< endl;
    cin >> coordinate;
    v.setCoordinate(i, coordinate);
  }

  v.absoluteValue();

  for (int i=0; i < ndim; i++){
    cout << " " << axes[i] <<": " << v.getCoordinate(i);
  }

  cout << endl;
  return 0;
}
