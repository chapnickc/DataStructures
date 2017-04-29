#include "Graphl.h"
#include <cmath>

#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

Graph* _basic_graph(int nvert, int repeat){
  Graph* graph = new Graphl(nvert);
  for (int i = 0; i < nvert; i++){
    graph->setEdge(i, (i + 1) % nvert, 1);
    if (i % 2 == 0)
      { graph->setEdge(i,  1, 1); }
  }
  return graph;
}


Graph* _basic_graph(int nvert){
  Graph* graph = new Graphl(nvert);
  for (int i = 0; i < nvert;i++){
    graph->setEdge(i, (i + 1) % nvert, 1);
    if (i % 2 == 0)
      { graph->setEdge(i,  1, 1); }
  }
  return graph;
}


int main(){

  Graph* graphs[4];
  for (int i=0; i<4; i++){
    graphs[i] = _basic_graph(10^(i+1));
    sleep_until(system_clock::now() + seconds(1));
  }

  cout << "Writing graph to testgraph.json...\n"; 
  ofstream filename("testgraph.json");
  graphs[3]->export_json(filename);

  std::cout << "\nExported Matrix:\n";
  graphs[3]->print_matrix();

  ifstream infile("./testgraph.json");
  Graph g;
  json j; infile >> j; j >> g;

  //Graph* g = import_json(infile);

  std::cout << "\nImported Matrix:\n";
  g.print_matrix();
  return 0;

}


