#include "GraphL.h"
#include "graph_utils.cpp" 

#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <fstream>
#include <vector>


using namespace std;

// Adjancency List and Heap minVertex
int main(){
  srand(2100);

  double runtime;
  clock_t start;
  ofstream logfile("dijk1.log");

  int N = 9;
  std::vector<GraphL*> graphs(N);
  
  complete_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, heap_dijkstra, logfile);

  complete_bintrees<GraphL>(graphs, logfile);
  test_graph_vector(graphs, heap_dijkstra, logfile);

  linear_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, heap_dijkstra, logfile);


  return 0;
}

