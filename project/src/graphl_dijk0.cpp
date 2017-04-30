#include "GraphL.h"
#include "graph_utils.cpp" 

#include <stdlib.h>  
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;


// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(int argc, char** argv){
  srand(2100);  // for reproducibility
  int N = 9;
  std::vector<GraphL*> graphs(N);

  double runtime;
  clock_t start;

  for (int i=0; i < N; i++){ 
    start = clock(); 
    graphs[i] = complete_graph<GraphL>(pow(2, i+1));
    runtime = (clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "("<< graphs[i]->n() << "," << graphs[i]->e() <<")";
    cout<<" build-time: "<< runtime <<'\n';
  }

  test_graph_array(graphs, linear_dijkstra);

  return 0;
}

