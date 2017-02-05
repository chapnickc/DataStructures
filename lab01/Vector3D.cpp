#include "Vector3D.h"
#include "VectorND.h"

Vector3D::Vector3D() : VectorND() {}

Vector3D::Vector3D(const Vector3D& v) : VectorND(v) {}

Vector3D::Vector3D(float* v) : VectorND(v, 3) {}

/*

ostream& operator<<(ostream& out, const Vector3D& v3D){
    out << (VectorND) v3D;
    return out;
}

*/
