#ifndef DEQUE_H
#define DEQUE_H

#include "dlinkFL.h"
#include <stdexcept>
#include <iostream>
using namespace std;


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
    cout << "clearing..." << endl; 
    Link<T>* prevLink;
    while (rear->prev != front){
      prevLink = rear->prev;
      delete rear;
      rear = prevLink;
    }
    size = 0;
  }

  void enqueue(const T& item, bool top=false){
    if (top){
      cout << "adding to top" << endl;
      // add an item to the top/beginning of deque
      //front->next = newLink = new Link<T>(item, front->next);
      front->next = new Link<T>(item, front, front->next);
      if (rear == front){rear = front->next;}
    }
    else {
      cout << "adding to rear" << endl;
      // add an item to the bottom/end of deque
      if (rear->prev == NULL){ rear->prev = front; };
      rear->next = new Link<T>(item, rear->prev, NULL);     // point to a new link
      rear = rear->next;                        // make the rear the new link
    }
    size++;
  }

  T dequeue(bool top=true){
    // declare identifiers outside of conditionals
    T item;
    Link<T>* dequeued;   

    if ( not (length() > 0) ) {
      cout << "throwing length error" << endl;
      throw std::length_error("Deque is empty");
    }

    // if the user wants to dequeue from the top (default behavior)
    if (top){
      cout << "dequeueing from top" << endl;
      item = frontValue();      // take item off top of deque
      dequeued = front->next;     // store the dequeued element
      front->next= dequeued->next; // point the header to the next item to be dequeued
      if (dequeued == rear){ rear = front; }
      delete dequeued;
    }
    else { // take item off bottom of deque
      cout << "dequeueing from bottom" << endl;
      item = rearValue();
      dequeued = rear;
      rear = rear->prev;
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
