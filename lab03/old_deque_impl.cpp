#include "Deque.h"
#include <stdexcept>

template <typename T>
Deque<T>::Deque(){
  // using a header node
  front = rear = new Link<T>();
  //rear = front;
  size = 0;
}

template <typename T>
Deque<T>::~Deque(){
  clear();
  delete front;
}

template <typename T>
int Deque<T>::length() const{
  return size;
}

template <typename T>
void Deque<T>::clear() {
  while(front->next != NULL){
    // this is okay since the node before the tail
    // points to the rear, so no memory link
    rear = front->next;
    delete rear;
  }
  rear = front;
  size = 0;
}

template <typename T>
void Deque<T>::enqueue(const T& item, bool top){
  if (top){
    // add an item to the top/beginning of deque
    //front->next = newLink = new Link<T>(item, front->next);
    front->next = new Link<T>(item, front->next);
  }
  else {
    // add an item to the bottom/end of deque
    rear->next = new Link<T>(item, NULL);     // point to a new link
    rear = rear->next;                        // make the rear the new link
    size++;
  }
}

template <typename T>
T Deque<T>::dequeue(bool top){
  // declare identifiers outside of conditionals
  T item;
  Link<T>* dequeued;   
  if ( not (length() > 0) ) {
    throw std::length_error("Deque is empty");
  }
  // if the user wants to dequeue from the top (default behavior)
  if (top){
    item = front->next->element;      // take item off top of deque
    dequeued  = front->next;     // store the dequeued element
    front->next= dequeued->next; // point the header to the next item to be dequeued
    if (rear == dequeued){ rear = front; }
  }
  else {
    // take item off bottom of deque
    item = rear->element;
    dequeued= rear;
    rear = rear->prev;
    rear->next = NULL;
  }
  size--;
  delete dequeued;
  return item;
}

template <typename T>
const T& Deque<T>::frontValue() const {
  if ( not (length() > 0) ) {
    throw std::length_error("Deque is empty");
  } 
  else {
    return front->next->element;
  }
}
 

template <typename T>
const T& Deque<T>::rearValue() const {
  if (not (length() > 0)){
    throw std::length_error("deque is empty");
  }
  else{
    return rear->element;
  }
}


