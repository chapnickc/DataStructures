#include <iostream>
using namespace std;

int dim = 3;
float* data = new float[dim];

void embed(int newdim){
  if (newdim <= dim){ return; }

  float* temp = new float[dim];
  copy(data, data+dim, temp);
  delete[] data;

  float* data = new float[newdim];
  copy(temp,temp+dim,data);
  delete[] temp;

  for (int i=dim;i<newdim;i++){
    data[i] = 0;
  }
  
  dim = newdim;
  cout << '('<< endl;
  for (int  i=0;i<dim;i++){
    cout << data[i] << ',' << endl;
  }
  cout << ')'<< endl;
}

int main(){
  data[0] = 4.0;
  data[1] = 2.0;
  data[2] = 5.0;

  cout << '('<< endl;
  for (int  i=0;i<dim;i++){
    cout << data[i] << ',' << endl;
  }
  cout << ')'<< endl;


  embed(6);
  return 0;
}
