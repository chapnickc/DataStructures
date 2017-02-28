#ifndef LSTACK_H
#define LSTACK_H
#include <stddef.h>
#include "book.h"
#include "link.h"
#include "stack.h"

template <typename T> class LStack: public Stack<T> {
private:
  Link<T>* top;             // Pointer to first element
  int size;                   // Number of elements

public:
  LStack(int sz = defaultSize){ 
    top = NULL; 
    size = 0; 
  }

  ~LStack(){ 
    clear(); 
  }

  void clear() {                  // Reinitialize
    while (top != NULL) {         // Delete link nodes
      Link<T>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const T& item) { 
    /* Add an item to the top of the stack by 
     * reassigning the top Link pointer, 
     * and constructing a new one with it's 
     * "next" pointer set to the Link currently at 
     * the top of the stack
     */
    top = new Link<T>(item, top);
    size++;
  }

  T pop() {                
    // make sure stack is not empty
    Assert(top != NULL, "Stack is empty");

    // grab element at the top of the stack
    T item = top->element;
    Link<T>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return item;
  }

  const T& topValue() const { // Return top value
    Assert(top != 0, "Stack is empty");
    return top->element;
  }

  int length() const { 
    /* Return number of items in stack*/
    return size; 
  } 

  bool isEmpty() const {
    if (size > 0){
      return false;
    }
    else {
      return true;
    }
  }
};
#endif
