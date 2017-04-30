#include "GraphM.h"
#include "graph_utils.cpp"

#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>

using namespace std;

// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(){
  srand(2100);
  double runtime;
  clock_t start;
  ofstream logfile("dijk2.log");

  int N = 9;
  std::vector<GraphM*> graphs(N);

  complete_graphs<GraphM>(graphs, logfile);

  test_graph_vector(graphs, linear_dijkstra, logfile);

  return 0;
}

