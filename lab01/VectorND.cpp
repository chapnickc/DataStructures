#include "VectorND.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

VectorND::VectorND() {
    alloc = 3;
    vec = new float[alloc];
    for (int i=0; i < alloc; i++){
        vec[i] = 0.0;
    }
}

VectorND::VectorND(int n) {
    alloc = n;
    vec = new float[n];
    for (int i=0; i < n; i++) {
        vec[i] = 0.0;
    }
}

VectorND::VectorND(const VectorND& v) {
    alloc = v.alloc;
    vec = new float[alloc];
    copy(v.vec, v.vec+alloc, vec);
}

VectorND::VectorND(float* v, int dimension) {
    alloc = dimension;
    vec = new float[alloc];
    copy(v, v+alloc, vec);
}


VectorND::~VectorND(){
    delete[] vec; 
}

void VectorND::resize(int newalloc){
    if (newalloc > alloc) {
        float* temp = new float[alloc];
        copy(vec, vec+alloc, temp);
        delete[] vec;

        vec = new float[newalloc];
        copy(temp, temp+alloc, vec);
        delete[] temp;
        alloc = newalloc;
    }
}

void VectorND::setCoordinate(int i, float val) {
    if (i > alloc){
        resize(i);
    }
    vec[i] = val;
}

float VectorND::getCoordinate(int i) const {
    return vec[i];
}


int VectorND::getLength() const {
    return alloc;

}

float VectorND::magnitude() const {
    float ans = 0.0;
    for (int i=0; i < alloc; i++) {
        ans += vec[i]*vec[i]; 
    }
    return sqrt(ans);
}

void VectorND::normalize(){
    float m = magnitude();
    if (m != 0.0) {
        for (int i=0; i < alloc; i++) {
            vec[i] /= m;
        }
    }
}

void VectorND::absoluteValue(){
    for (int i=0; i < sizeof(vec)/sizeof(*vec); i++){
        if (vec[i] < 0){
            vec[i] *= -1;
        }
    }
}

VectorND VectorND::operator+(const VectorND& other) const {
    if (alloc == other.alloc){
        float* temp = new float[alloc];
        for (int i=0; i < alloc; i++){
            temp[i] = vec[i] + other.vec[i];
        }

        VectorND new_vec = VectorND(temp, alloc);
        delete[] temp;
        return new_vec;
    } 
    else {
        cout << "Vectors are not of the same length!" << endl; 
        return VectorND();
    }
}

float VectorND::operator*(const VectorND& other) const {
    float ans = 0.0;
    if (alloc != other.alloc){
        return ans;
    }
    else{
        for (int i=0; i < alloc; i++) {
            ans += vec[i] * other.vec[i]; 
        }
        return ans;
    }
}

ostream& operator<<(ostream& out, const VectorND& v) {
    out << "magnitude: " << v.magnitude() << "| length: " << v.getLength();
    return out;
}
