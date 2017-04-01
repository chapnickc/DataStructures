#include "Job.h"
#include "PriorityQueue.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

PriorityQueue pq = PriorityQueue(30);

int main(){
  srand(time(NULL));
  cout << "enqueueing..." << endl;
  for (int i=0; i < 25; i++){
    int jobid = rand();
    int priority = rand() % 10 + 1;
    pq.enqueue(jobid, priority);
  }

  
  cout << "dequeueing.." << endl;
  for (int i=0; i < 25; i++){
    pq.dequeue(true);
  }

  return 0;
}
