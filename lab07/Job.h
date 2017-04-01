class Job {
  private:
    int id;
    int priority;

  public:
    Job(){id = 0; priority = 0; }
    Job(int jobid, int p){id = jobid; priority = p; }
    int getJobID(){ return id; }
    int getPriority(){ return priority; }
    void setJobID(int jobid){ id = jobid; }
    void setPriority(int p){ priority = p; }
};
