#include "GraphL.h"
#include "graph_utils.cpp" 

#include <chrono>
#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <thread>


using namespace std;

// Version for Adjancency List representation
int main(){
  srand(2100);

  std::clock_t start;
  double runtime;

  int N = 9;
  std::vector<GraphL*> graphs(N);
  
  for (int i=0; i < N; i++){
    start = clock();
    cout << "Building graph " << i;
    graphs[i] = complete_graph<GraphL>(pow(2, i+1));
    runtime = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout<<"\t\tElapsed Time: "<< runtime <<'\n';
  }

  test_graph_array(graphs, heap_dijkstra);

  return 0;
}


