#include "Deque.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Deque<int> deck;


int main(){
  try {
    cout << "Testing length errors:" << endl;
    deck.frontValue();
  }
  catch (length_error& e){
    cout << "\t" << e.what() << endl;
  }
  cout << "Deque length: " << deck.length() << endl;
  for (int i=0;i<25;i++){
    deck.enqueue(i);
  }
  cout << "Deque length: " << deck.length() << endl;
  cout << "Deque frontValue: " << deck.frontValue() << endl;
  cout << "Deque rearValue: " << deck.rearValue() << endl;

  deck.dequeue(false);
  cout << "Deque rearValue: " << deck.rearValue() << endl;
  cout << "Deque frontValue: " << deck.frontValue() << endl;
  

  return 0;
}
