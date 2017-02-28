#ifndef ALIST_H
#define ALIST_H
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete AList template class

// First, get the declaration for the base list class
#include "list.h"

// templating to accept many differnt types
// this is a concrete class

// This is the declaration for AList. It is split into two parts
// because it is too big to fit on one book page
template <typename E> // Array-based list implementation
class AList : public List<E> {
  private:
    int maxSize;      // Maximum size of list
    int listSize;     // Number of list items now
    int curr;         // Position of current element
    E* listArray;     // Array holding list elements

  public:
    AList(int size=defaultSize) { 
      maxSize = size;
      listSize = curr = 0;
      listArray = new E[maxSize];
    }

    // "delete[]" allows us to deal with special objects
    // whereas "delete" can delete built in types
    ~AList() { delete [] listArray; } // Destructor

    const E& getValue() const { // Return current element
      Assert((curr>=0)&&(curr<listSize),"No current element");
      return listArray[curr];
    }
   
    int currPos() const { return curr; }  // Return current position
    int length() const  { return listSize; }      // Return list size
    void moveToStart() { curr = 0; }              // Reset position
    void moveToEnd() { curr = listSize; }         // Set at end
    void next() { if (curr < listSize) curr++; }  // Next
    void prev() { if (curr != 0) curr--; }        // Back up
    
    
    // Insert "it" at current position
    void insert(const E& it) {
      Assert(listSize < maxSize, "List capacity exceeded");
      for(int i=listSize; i>curr; i--){ // Shift elements up
        listArray[i] = listArray[i-1];  //   to make room
      }
      listArray[curr] = it;
      listSize++;                       // Increment list size
    }

    // Remove and return the current element.
    E remove() {
      Assert((curr>=0) && (curr < listSize), "No element");
      E it = listArray[curr];           // Copy the element
      for(int i=curr; i<listSize-1; i++){  // Shift them down
        listArray[i] = listArray[i+1];
      }
      listSize--;                          // Decrement size
      return it;
    }

    void clear() {                    // Reinitialize the list
      delete [] listArray;            // Remove the array
      listSize = curr = 0;            // Reset the size
      listArray = new E[maxSize];  // Recreate array
    }

};

/*    void append(const E& it) {       // Append "it"*/
      //// this is defined elsewhere
      //Assert(listSize < maxSize, "List capacity exceeded");
      //listArray[listSize] = it;
      //listSize++;
    /*}*/
/*    // Set current list position to "pos"*/
    //void moveToPos(int pos) {
      //Assert ((pos>=0)&&(pos<=listSize), "Pos out of range");
      //curr = pos;
    /*}*/

#endif