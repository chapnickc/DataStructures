
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

  ifstream infile("./data/completesingle.json");
  graph->import_json(infile);
}
