#ifndef VECTOR3D_H
#define VECTOR3D_H
class Vector3D {

  private:
    float c[3];

  public:
    Vector3D(); 
    Vector3D(const Vector3D& v); 
    Vector3D(float x, float y, float z); 
    void setCoordinate(int i, float val);
    float getCoordinate(int i) const;
    float magnitude() const;
    void normalize();
    void absoluteValue();

    // Overload + operator to add the 
    Vector3D operator+(const Vector3D& other) const; // vector sum
    float operator*(const Vector3D& other) const; // dot product
};
#endif
