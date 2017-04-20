
#include "Graphl.h"

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
  Graph* graph = _basic_graph(10);
  ofstream filename("testgraph.json");
  cout << "Writing graph to testgraph.json...\n"; 
  graph->export_json(filename);

  std::cout << "\nExported Matrix:\n";
  graph->print_matrix();

  ifstream infile("./testgraph.json");
  Graph* g = import_json(infile);

  std::cout << "\nImported Matrix:\n";
  g->print_matrix();
}
