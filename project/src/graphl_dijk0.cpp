
#include "GraphL.h"
#include "graph_utils.cpp" 

#include <stdlib.h>  
#include <stdio.h>  
#include <cmath>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(int argc, char** argv){
  srand(2100);  // for reproducibility

  double runtime;
  clock_t start;
  ofstream logfile("dijk0.log");

  int N = 9;
  std::vector<GraphL*> graphs(N);
  
  complete_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, linear_dijkstra, logfile);

  return 0;
}

//GraphL* graph = import_graph<GraphL>("../data/bkdijk.json");
//dijkstra_test(graph, linear_dijkstra);

