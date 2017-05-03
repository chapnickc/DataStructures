#include "GraphM.h"
#include "graph_utils.cpp"

#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Test Dijkstra's algorithm:
// Version for Adjancency Matrix representation
// Heap V
int main(){
  srand(2100);
  double runtime;
  clock_t start;
  ofstream logfile("dijk3.log");

  int N = 6;
  std::vector<GraphM*> graphs(N);
  
  complete_graphs<GraphM>(graphs, logfile);
  test_graph_vector(graphs, heap_dijkstra, logfile);

  return 0;
}

