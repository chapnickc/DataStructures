#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "VectorND.h"
#include <iostream>
using namespace std;

class Vector3D : public VectorND {

  public:
    Vector3D(); 
    Vector3D(const Vector3D& v); 
    Vector3D(float* v); 
};


ostream& operator<<(ostream& out, const Vector3D& v3D);

#endif
