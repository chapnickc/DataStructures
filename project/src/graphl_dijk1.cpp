#include "GraphL.h"
#include "graph_utils.cpp" 

#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <fstream>

using namespace std;

// Version for Adjancency List representation
int main(){
  srand(2100);

  double runtime;
  clock_t start;
  ofstream logfile("dijk1.log");

  int N = 12;
  std::vector<GraphL*> graphs(N);
  
  complete_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, heap_dijkstra, logfile);

  return 0;
}

