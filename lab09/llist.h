// Modified from:
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation

// First, get the declaration for the base list class
#ifndef LLIST_H
#define LLIST_H

#include "book.h"
#include "link.h"
#include "list.h"
//#include <iostream>
//using namespace std;

template <typename E> class LList: public List<E> {
private:
  Link<E>* head;       // Pointer to list header
  Link<E>* tail;       // Pointer to last element
  Link<E>* curr;       // Access to current element
  int cnt;    	       // Size of list

  void init() {        // Intialization helper method
    curr = tail = head = new Link<E>; // new always returns a pointer
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  LList(int size=defaultSize) { init(); }    // Constructor
  ~LList() { removeall(); }                   // Destructor

  int length() const { return cnt; }    // Return length

  void moveToStart() { curr = head; }   // Place curr at list start
  void moveToEnd()   { curr = tail; }   // Place curr at list end

  // Move curr one step right; no change if already at end
  void print() const;                   // Print list contents
  void clear() { removeall(); init(); } // Clear list

  const E& getValue() const { // Return current element
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }

  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  void next() { if (curr != tail) curr = curr->next; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return;           // No previous element
    Link<E>* temp = head;

    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // Insert "it" at current position
  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);  
    if (tail == curr)
     { tail = curr->next; } // New tail
    cnt++;
  }

  // Remove and return current element
  E remove() {
    Assert(curr->next != NULL, "No element");
    E it = curr->next->element;         // Remember value
    Link<E>* ltemp = curr->next;        // Remember link location

    if (tail == curr->next)
      { tail = curr; }                  // Reset tail

    curr->next = curr->next->next;      // set pointer to NULL

    delete ltemp;                       // Reclaim space at link location
                                        // we can also drop this into a pool
    cnt--;			                        // Decrement the count
    return it;
  }

  void reverse(){
    // compiler complains if no nextLink init
    Link<E>* nextLink = new Link<E>; 
    Link<E>* prevLink = NULL; 

    moveToStart();
    curr = head->next;
    tail = curr;

    while(nextLink != NULL){
      nextLink = curr->next;
      curr->next = prevLink;
      prevLink = curr;
      curr = nextLink;
    }

    head->next= prevLink;   
    delete nextLink;
  }
 
};
#endif

/*
  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }
  void append(const E& it) { // Append "it" to list
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
  }
*/ 
