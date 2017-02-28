#ifndef AQUEUE_H
#define AQUEUE_H

#include "queue.h"

// This is the declaration for AStack.
// Array-based queue implementation
template <typename E> class AQueue: public Queue<E> {
  private:
    int maxSize;               // Maximum size of queue
    int front;                 // Index of front element
    int rear;                  // Index of rear element
    int sz;
    E *listArray;           // Array holding queue elements

  public:
    AQueue(int size =defaultSize) {  // Constructor 
      // Make list array one position larger for empty slot
      // we do this to so that the array is never actually filled
      maxSize = size+1;
      rear = 0;  front = 1;
      listArray = new E[maxSize];
      sz = 0;
    }

    ~AQueue() { delete [] listArray; } // Destructor

    void clear() { rear = 0; front = 1; sz=0;} // Reinitialize

    void enqueue(const E& it) {     // Put "it" in queue
      Assert(((rear+2) % maxSize) != front, "Queue is full"); // check if full
      rear = (rear+1) % maxSize; //increment after enqueue. use modulus to make sure we are less than or equal to maxsize
      listArray[rear] = it;
      sz++;
    }

    E dequeue() {           // Take element out
      Assert(length() != 0, "Queue is empty");
      E it = listArray[front];        // front of 1st thing in queue
      front = (front+1) % maxSize;    // Circular increment
      sz--;
      return it;
    }

    const E& frontValue() const {  // Get front value
      Assert(length() != 0, "Queue is empty");
      return listArray[front];
    }

    virtual int length() const {
      // see class notes
      //return ((rear+maxSize) - front + 1) % maxSize; 
      return sz;
    }
};

#endif
