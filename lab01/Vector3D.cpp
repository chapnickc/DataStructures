#include "Vector3D.h"
#include "VectorND.h"

Vector3D::Vector3D() : VectorND() {}

Vector3D::Vector3D(const Vector3D& v) : VectorND(v) {}

Vector3D::Vector3D(float* v) : VectorND(v, 3) {}



ostream& operator<<(ostream& out, const Vector3D& v3D){

    const char axes[] = "xyz";
    for (int i=0; i < v3D.getLength() ; i++){
        cout << " " << axes[i] <<": " << v3D.getCoordinate(i);
    }

    out << '\n' << (VectorND) v3D;
    return out;
}

