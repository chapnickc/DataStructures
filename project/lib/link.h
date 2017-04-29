#ifndef LINK_H
#define LINK_H
#define NULL 0
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> 
class Link {

  public:
    E element;
    Link *next;

    Link(const E& elemval, Link* nextval =NULL) { 
      element = elemval;  
      next = nextval; 
    }

    Link(Link* nextval = NULL) { 
      next = nextval; 
    }
};

#endif
