#include "Deque.h"
#include <iostream>

using namespace std;

Deque<int> deck;

int main(){
  deck.enqueue(10);
  cout << "Deque length: " << deck.length() << endl;
  deck.enqueue(20);
  cout << "Deque length: " << deck.length() << endl;
  cout << "Deque frontValue: " << deck.frontValue() << endl;
  cout << "Deque rearValue: " << deck.rearValue() << endl;
  deck.enqueue(30);
  deck.enqueue(40);
  deck.enqueue(50);
  deck.dequeue(false);
  cout << "Deque length: " << deck.length() << endl;
  return 0;
}
