#include "Job.h"
#include "PriorityQueue.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

bool DEBUG = true;
PriorityQueue pq = PriorityQueue(30);

int main(){

  srand(time(NULL));
  cout << "enqueueing..." << endl;
  int jobid, priority;
  for (int i=0; i < 25; i++){
    jobid = rand();
    priority = rand() % 10 + 1;
    pq.enqueue(jobid, priority);
  }

  cout << "Changing weight of jobid " << jobid << 
    " from " << priority << " to 10" << endl;
  pq.changeweight(jobid,10);

  cout << "dequeueing..\n" << endl;
  cout << "Job ID\t\tPriority" << endl;
  for (int i=0; i < 25; i++){
    jobid = pq.dequeue(DEBUG);
  }

  return 0;
}
