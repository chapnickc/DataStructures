
#include "GraphL.h"
#include "GraphM.h"
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

  //GraphL* graph = import_graph<GraphL>("../data/bkdijk.json");
  //dijkstra_test(graph, linear_dijkstra);

  double runtime;
  clock_t start;
  ofstream logfile("dijk0.log");

  int N = 6;
  std::vector<GraphL*> graphs(N);

  complete_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, linear_dijkstra, logfile);

  complete_bintrees<GraphL>(graphs, logfile);
  test_graph_vector(graphs, linear_dijkstra, logfile);

  linear_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, linear_dijkstra, logfile);



  return 0;

}

