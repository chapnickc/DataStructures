#ifndef JSONGRAPH_H
#define JSONGRAPH_H

#include "Graph.h"
#include "Graphl.h"
#include "json.hpp"

#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

using json = nlohmann::json;
using namespace std;


class JSONGraph : public Graphl {

private:
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

public:
  JSONGraph(int numVert)
    { Init(numVert); }

  ~JSONGraph() {       // Destructor
    delete [] mark; // Return dynamically allocated memory
    for (int i=0; i<numVertex; i++) delete vertex[i];
    delete [] vertex;
  }

  void import_json(istream& instream) {
    json j;
    instream >> j;
    cout << j << endl;
  }

  void export_json(ostream& output) {
    json j;
    _build_graph(j, this);
    output << setw(4) << j << endl;
  }

};
