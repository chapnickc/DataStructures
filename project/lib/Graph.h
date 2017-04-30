#ifndef GRAPH_H
#define GRAPH_H

#include "json.hpp"
#include "utils.h"

#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>

using json = nlohmann::json;
using namespace std;



// Graph Abstract Class (ADT)
//  Note: assumes that the number of vertices is fixed when the graph is created.
class Graph {

private:

  Graph(const Graph&){}            // Protect copy constructor
  void operator =(const Graph&){}  // Protect assignment

  // Initialize a graph of n vertices
  virtual void _init(int n) = 0;

  void _json_nodes(json& j, Graph* g){
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

  void _json_edges(json& j, Graph* g){
    std::vector<json> edges(g->e());
    int i=0; 
    json edge;
    for (int m = 0; m < g->n(); m++) { 
      for (int n = 0; n < g->n(); n++){
        if ( g->isEdge(m,n) ){
          edge = {
            { "source", m },
            { "target", n },
            { "weight", g->weight(m,n) },
            { "relation", "edge relationship" },
            { "label", "edge label" },
            { "metadata", { "user-defined", "values"}}
          };
          edges[i] = edge; i++;
        }
      }
    }
    j["edges"] = edges;
  }

  void _json_graph(json& j, Graph* g){
    j["graph"] = { 
      { "size", g->n() },
      { "directed", false }, 
      { "type", "graph type" }, 
      { "label", "graph label" },
      { "metadata", 
        { "user-defined", "values" }
      }
    };
    _json_nodes(j, g);
    _json_edges(j, g);
  }

public:

  Graph(){}
  Graph(int n){}

  ~Graph(){}

  // Return: the number of vertices and edges
  // (should make these const)
  virtual int n() = 0;
  virtual int e() = 0;

  // return v's first neighbor
  virtual int first(int v) =0;

 // returns next neighboring vertex of v after w 
  virtual int next(int v, int w) =0;

  // v1, v2: the edge indicies, wgt: Edge weight
  virtual void setEdge(int v1, int v2, int wght) =0;
  virtual void delEdge(int v1, int v2) =0;

  // Determine if an edge is in the graph
  // i, j: The vertices
  // Return: true if edge i,j has non-zero weight
  // ....could devirtualize
  virtual bool isEdge(int i, int j) =0;

  // i, j: The vertices
  // Return: The weight of edge i,j, or zero
  virtual int weight(int v1, int v2) =0;

  // v: The vertex index
  // val: The value to set
  virtual int getMark(int v) =0;
  virtual void setMark(int v, int val) =0;


  void print_matrix(){
    cout << "|V|: " << n() << "\t";
    cout << "|E|: " << e() << endl;
    cout << "Adjacency Matrix is:\n";
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < n(); j++){ 
        cout << isEdge(i, j) << " "; 
      } cout << "\n";
    }
  }

  //virtual void import_json(istream& instream) =0;

  void export_json(ostream& output) {
    json j;
    _json_graph(j, this);
    output << setw(4) << j << endl;
  }

};

template <typename GraphT>
GraphT* import_graph(string filename){ 
  ifstream infile(filename);
  json j; 
  infile >> j; 

  int graph_size = j["graph"]["size"];
  GraphT* graph = new GraphT(graph_size);

  for (auto& edge : j["edges"]) {
    if ( not graph->isEdge(edge["source"], edge["target"]) ){
      graph->setEdge(edge["source"], edge["target"], edge["weight"]);
    }
  }

  return graph;
}


#endif
