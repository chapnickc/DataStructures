#ifndef DEQUE_H
#define DEQUE_H

#include "dlinkFL.h"
#include <stdexcept>
//#include <iostream>
//using namespace std;


template <typename T> 
class Deque {
private:
  Link<T>* front;         // Pointer to front queue node
  Link<T>* rear;          // Pointer to rear queue node
  int size;                // Number of elements in queue

public:
  Deque(){
    // using a header node
    front = rear = new Link<T>();
    size = 0;
  }

  ~Deque(){
    clear();
  }

  int length() const{
    return size;
  }

  void clear(){
    Link<T>* prevLink;
    while (rear->prev != front){
      prevLink = rear->prev;
      delete rear;
      rear = prevLink;
    }
    size = 0;
  }

  void enqueue(const T& item, bool top=false){
    if (top && length() > 0){
      // add an item to the top/beginning of deque
      front->next = new Link<T>(item, front, front->next);
      //if (rear == front){rear = front->next;}
    }
    else {
      // add an item to the bottom/end of deque
      rear->next = new Link<T>(item, rear, NULL);     // point to a new link
      rear = rear->next;                        // make the rear the new link
      //if (rear->prev == NULL){ rear->prev = front; };
    }
    size++;
  }

  T dequeue(bool top=true){
    // declare identifiers outside of conditionals
    T item;
    Link<T>* dequeued;   

    if ( not (length() > 0) ) {
      throw std::length_error("Deque is empty");
    }

    // if the user wants to dequeue from the top (default behavior)
    if (top){
      item = frontValue();      // take item off top of deque
      dequeued = front->next;     // store the dequeued element
      front->next= dequeued->next; // point the header to the next item to be dequeued
      if (dequeued == rear){ rear = front; }
      delete dequeued;
    }
    else { // take item off bottom of deque
      item = rearValue();
      dequeued = rear;
      rear = dequeued->prev;
      rear->next = NULL;
      delete dequeued;
    }
    size--;
    return item;
  }

  const T& frontValue() const{
    if ( not (length() > 0) ) {
      throw std::length_error("Deque is empty");
    } 
    else {
      return front->next->element;
    }
  }


  const T& rearValue() const{
    if (not (length() > 0)){
      throw std::length_error("deque is empty");
    }
    else{
      return rear->element;
    }
  }

};

#endif
