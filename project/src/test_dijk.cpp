#include "GraphL.h"
#include "graph_utils.cpp" 

#include <stdlib.h>  
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

// Test Dijkstra's algorithm

int main(int argc, char** argv){
  srand(2100);  // for reproducibility

  int N = 7;
  double runtime;
  clock_t start;
  ofstream logfile;

  // Adjacency List and Linear minVertex
  logfile.open("dijk0.log");
  std::vector<GraphL*> graphs(N);

  complete_graphs<GraphL>(graphs, logfile);
  test_graph_vector(graphs, linear_dijkstra, logfile);
  logfile.close();


  // Adjacency List and Heap minVertex
  logfile.open("dijk1.log");
  std::vector<GraphL*> graphs1(N);
  
  complete_graphs<GraphL>(graphs1, logfile);
  test_graph_vector(graphs1, heap_dijkstra, logfile);
  logfile.close();


  // Adjacency Matrix and Linear minVertex
  logfile.open("dijk2.log");
  std::vector<GraphM*> graphs2(N);

  complete_graphs<GraphM>(graphs2, logfile);
  test_graph_vector(graphs2, linear_dijkstra, logfile);
  logfile.close();


  // Adjacency Matrix and Heap minVertex
  logfile.open("dijk3.log");
  std::vector<GraphM*> graphs3(N);
  
  complete_graphs<GraphM>(graphs3, logfile);
  test_graph_vector(graphs3, heap_dijkstra, logfile);
  logfile.close();


  return 0;
}
//GraphL* graph = import_graph<GraphL>("../data/bkdijk.json");
