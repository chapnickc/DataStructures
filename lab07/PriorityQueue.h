#include "book.h"
#include "compare.h"
#include "heap.h"

#include <iostream>
using namespace std;

class jobCompare {
public:
  static bool prior(Job jobx, Job joby) { return jobx.getPriority() > joby.getPriority(); }
};

class PriorityQueue {
  private:
    Job* arr = NULL;
    heap<Job, jobCompare>* jobHeap;

  public:
    PriorityQueue(int maxsize){ 
      arr = new Job [maxsize];
      jobHeap = new heap<Job, jobCompare>(arr,0,maxsize);
    }

    // return jobID of job with max priority
    int dequeue(bool debug){ 
      Job job = jobHeap->removefirst();
      if (debug){
        cout << job.getJobID() << '\t' << job.getPriority() << endl;
      }
      return job.getJobID(); 
    } 
    void enqueue(int jobID, int priority){ jobHeap->insert(Job(jobID, priority)); }
    void changeweight(int jobID, int newPriority){}
};
