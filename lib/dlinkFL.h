#ifndef DLINKFL_H
#define DLINKFL_H

#include <stddef.h>
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Doubly linked list link node with freelist support
template <typename T> class Link {
private:
  static Link<T>* freelist; // Reference to freelist head

public:
  T element;       // Value for this node
  Link* next;         // Pointer to next node in list
  Link* prev;         // Pointer to previous node

  // Constructors
  Link(const T& it, Link* prevp, Link* nextp) {
    element = it;
    prev = prevp;
    next = nextp;
  }
  Link(Link* prevp =NULL, Link* nextp =NULL) {
    prev = prevp;
    next = nextp;
  }

  void* operator new(size_t) {  // Overloaded new operator
    if (freelist == NULL) return ::new Link; // Create space
    Link<T>* temp = freelist; // Can take from freelist
    freelist = freelist->next;
    return temp;                 // Return the link
  }

  // Overloaded delete operator
  void operator delete(void* ptr) {
    ((Link<T>*)ptr)->next = freelist; // Put on freelist
    freelist = (Link<T>*)ptr;
  }
};

// The freelist head pointer is actually created here
template <typename T>
Link<T>* Link<T>::freelist = NULL;
#endif
