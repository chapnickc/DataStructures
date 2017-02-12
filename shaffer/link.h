// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Singly linked list node
template <typename E> class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list, 
                    // we want a pointer to the entire class
  // Constructors
  Link(const E& elemval, Link* nextval = NULL){  
    // NULL, this is the 0 pointer. This is used to 
    // indicate if the pointer is set to anything useful
        element = elemval;  
        next = nextval; 
  }
  Link(Link* nextval = NULL) { 
      next = nextval; 
  }
};
