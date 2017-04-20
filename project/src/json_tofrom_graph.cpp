#include "json.hpp"
#include "Graphl.h"

#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using json = nlohmann::json;
using namespace std;

Graphl* _basic_graph(int nvert){
  Graphl* graph = new Graphl(nvert);//graph(nvert);
  for (int i = 0; i < nvert;i++){
    graph->setEdge(i, (i + 1) % nvert, 1);

    if (i % 2 == 0)
      { graph->setEdge(i,  1, 1); }
  }
  return graph;
}


void _build_nodes(json& j, Graph* g){
  json node;
  std::vector<json> nodes(g->n());
  for (int i=0; i < g->n(); i++){ 
    node = {
      { "id", i },
      { "type", "node type" },
      { "label", "node label(" + std::to_string(i) + ")" },
      { "metadata", {"user-defined", "values"} }
    };
    nodes[i] = node; 
  }
  j["nodes"] = nodes;
}

void _build_edges(json& j, Graph* g){
  json edge;
  std::vector<json> edges(g->e());

  /* O(n^2) ... */
  int i=0;
  for (int m = 0; m < g->n(); m++) { 
    for (int n = 0; n < g->n(); n++){ 
      if ( g->isEdge(m,n) ){
        edge = {
          { "source", m },
          { "target", n },
          { "directed", false },
          { "relation", "edge relationship" },
          { "label", "edge label" },
          { "metadata", { "user-defined", "values"}}
        };
        edges[i] = edge;
        i++;
      }
    }
  }

  j["edges"] = edges;
}

void _build_graph(json& j, Graph* g){
  j["graph"] = { 
    { "size", g->n() },
    { "directed", false }, 
    { "type", "graph type" }, 
    { "label", "graph label" },
    { "metadata", 
      { "user-defined", "values" }
    }
  };

  _build_nodes(j, g);
  _build_edges(j, g);
}


void _print_matrix(Graph* graph){
  cout << "|V|: " << graph->n() << endl;
  cout << "|E|: " << graph->e() << endl;
  cout << "Adjacency Matrix is:\n";
  for (int m = 0; m < graph->n(); m++) {
    for (int n = 0; n < graph->n(); n++){ 
      cout << graph->weight(m, n) << " "; 
    } cout << "\n";
  }
}


void export_json(ostream& output, Graph* g) {
  json j;
  _build_graph(j, g);
  output << setw(4) << j << endl;
}


int main(){
  int nvert = 3;
  Graph* graph = _basic_graph(nvert);
  _print_matrix(graph);

  ofstream filename("grap_test.json");
  cout << "Writing graph to test.json...\n"; 
  export_json(filename, graph);

}

