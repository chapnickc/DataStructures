#include <iostream>
using namespace std;

int dim = 5;
float* nums = new float[dim];

float* resize(int newdim){
  if (newdim <= dim){ return nums; }
  
  float* temp = new float[dim];
  copy(nums, nums+dim, temp);
  delete[] nums;

  float* nums = new float[newdim];
  copy(temp,temp+dim, nums);
  delete[] temp;

  for(int i=dim; i<newdim;i++){
    nums[i] = 0.0;
  }
  dim = newdim;
  return nums;
}

int main(){
  nums[0] = 0.0;
  nums[1] = 1.0;
  nums[2] = 2.0;
  nums[3] = 3.0;
  nums[4] = 4.0;

  cout << "(" << endl;
  for (int i = 0; i< dim;i++){
    cout << nums[i]<< endl;
  }
  cout << ")" << endl;

  nums = resize(11);

  cout << "(" << endl;
  for (int i = 0; i< dim;i++){
    cout << nums[i]<< endl;
  }
  cout << ")" << endl;


  return 0;
}
