#include "Graphl.h"
#include <gperftools/profiler.h>
#include <cmath>


#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
  using namespace std::chrono; // nanoseconds, system_clock, seconds


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
  ProfilerStart("./output.prof");

  Graph* graph0 = _basic_graph(10);
  sleep_until(system_clock::now() + seconds(1));

  Graph* graph1 = _basic_graph(100);
  sleep_until(system_clock::now() + seconds(1));

  Graph* graph2 = _basic_graph(1000);
  sleep_until(system_clock::now() + seconds(1));

  Graph* graph3 = _basic_graph(10000);
  sleep_until(system_clock::now() + seconds(1));

  ofstream filename("testgraph.json");
  cout << "Writing graph to testgraph.json...\n"; 
  graph0->export_json(filename);

  std::cout << "\nExported Matrix:\n";
  graph0->print_matrix();

  ifstream infile("./testgraph.json");
  Graph* g = import_json(infile);

  std::cout << "\nImported Matrix:\n";
  g->print_matrix();
  return 0;
  //ProfilerStop();
}


