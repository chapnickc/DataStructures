#ifndef LQUEUE_H
#define LQUEUE_H

#include "book.h"
#include "linkFL.h"
#include "queue.h"

template <typename E> class LQueue: public Queue<E> {
private:
  Link<E>* front;         // Pointer to front queue node
  Link<E>* rear;          // Pointer to rear queue node
  int size;                // Number of elements in queue

public:
  LQueue(int sz = defaultSize){ 
    front = rear = new Link<E>(); 
    size = 0; 
  }

  ~LQueue() { clear(); delete front; }      // Destructor

  void clear() {           // Clear queue
    while(front->next != NULL) { // Delete each link node
      rear = front;
      delete rear;
    }
    rear = front;
    size = 0;
  }

  void enqueue(const E& it) { // Put element on rear
    rear->next = new Link<E>(it, NULL);
    rear = rear->next;
    size++;
  }

  E dequeue() {              // Remove element from front
    Assert(size != 0, "Queue is empty");
    E it = front->next->element;  // Store dequeued value
    Link<E>* ltemp = front->next; // Hold dequeued link
    front->next = ltemp->next;       // Advance front
    if (rear == ltemp) rear = front; // Dequeue last element
    delete ltemp;                    // Delete link
    size --;
    return it;                       // Return element value
  }

  const E& frontValue() const { // Get front element
    Assert(size != 0, "Queue is empty");
    return front->next->element;
  }

  int length() const { return size; }
};
#endif
