#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  int arr[64] = {0};
  for (int i=0; i<64;i++){
    cout << arr[i] << endl;
  }
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
    cout << rand() << endl;
    }
    return 0;
}
