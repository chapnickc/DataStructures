#ifndef VECTORND_H
#define VECTORND_H
#include <iostream>

using namespace std;

class VectorND {

  private:
    int alloc;
    float* vec; 

    void resize(int newalloc);

  public:
    VectorND(); 
    VectorND(int n); 
    VectorND(const VectorND& v); 
    VectorND(float* v, int dimension); 
    ~VectorND();

    void setCoordinate(int i, float val);
    float getCoordinate(int i) const;
    int getLength() const;

    float magnitude() const;
    void normalize();
    void absoluteValue();

    // Overload + operator to add the 
    VectorND operator+(const VectorND& other) const; // vector sum
    float operator*(const VectorND& other) const; // dot product
};


ostream& operator<<(ostream& out, const VectorND& v);

#endif
