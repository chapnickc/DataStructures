
#include "GraphL.h"
#include "graph_utils.cpp" 

#include <cmath>
#include <ctime>
#include <fstream>
#include <stdlib.h>  
#include <stdio.h>  
#include <vector>

using namespace std;

// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(int argc, char** argv){
  srand(2100);  // for reproducibility

  double runtime;
  clock_t start;
  ofstream logfile("dijk0.log");

  int N = 12;
  std::vector<GraphL*> graphs(N);
  cout << "Building Graphs\n";
  complete_graphs<GraphL>(graphs, logfile);
  cout << "Testing Graphs\n";
  test_graph_vector(graphs, linear_dijkstra, logfile);

  return 0;
}

//GraphL* graph = import_graph<GraphL>("../data/bkdijk.json");
//dijkstra_test(graph, linear_dijkstra);

