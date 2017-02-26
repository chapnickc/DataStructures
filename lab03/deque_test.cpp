#include "Deque.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Deque<int> deck;

void checkDeque(const Deque<int>& d){
  cout << "\nChecking..." << endl;
  cout << "\tDeque length: " << d.length() << endl;
  cout << "\tDeque frontValue: " << d.frontValue() << endl;
  cout << "\tDeque rearValue: " << d.rearValue() << endl;
};


int main(){
  try {
    cout << "\nTesting length errors:" << endl;
    deck.frontValue();
  }
  catch (length_error& e){
    cout << "\t" << e.what() << endl;
  }
  cout << "\nDeque length: " << deck.length() << endl;

  for (int i=0;i<25;i++){
    deck.enqueue(i);
  }

  checkDeque(deck);

  deck.dequeue(false);
  checkDeque(deck);

  deck.dequeue();
  checkDeque(deck);

  return 0;
}
