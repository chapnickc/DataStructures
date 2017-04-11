#include "book.h"
#include "compare.h"
#include "heap.h"

#include <exception>
#include <iostream>
using namespace std;

class jobCompare {
  public:
    static bool prior(Job jobX, Job jobY) { return jobX.getPriority() > jobY.getPriority(); }
};

class PriorityQueue {
  private:
    Job* job_arr = NULL;
    heap<Job, jobCompare>* jobHeap;
    int njobs;

  public:
    PriorityQueue(int maxsize){ 
      njobs = 0;
      job_arr = new Job[maxsize];
      jobHeap = new heap<Job, jobCompare>(job_arr, njobs, maxsize);
    }

    // return jobID of job with max priority
    int dequeue(bool debug){ 
      Job job = jobHeap->removefirst();
      njobs--;
      if (debug){
        cout << job.getJobID() << '\t' << job.getPriority() << endl;
      }
      return job.getJobID(); 
    } 

    void enqueue(int jobID, int priority){ jobHeap->insert(Job(jobID, priority)); njobs++;}
    bool changeweight(int jobID, int newPriority){ 
      if ( !(jobHeap->size() > 0) ) { throw length_error("there aren't any elements in the queue"); }
      else {
        for (int i=0; i<njobs;i++){
          if (job_arr[i].getJobID() == jobID){
            job_arr[i].setPriority(newPriority);
            return true;
          }
        }
        return false; // if job not found 
      }
    }
};
