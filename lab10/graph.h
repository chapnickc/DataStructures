#ifndef GRAPH_H
#define GRAPH_H

#include "json.hpp"

#include <iostream>
#include <iomanip>      // std::setw
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>


using json = nlohmann::json;
using namespace std;

// Graph abstract class
// This ADT assumes that the number
// of vertices is fixed when the graph is created.
class Graph {

private:
  Graph(const Graph&) {} // Protect copy constructor
  void operator =(const Graph&) {} // Protect assignment

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


public:
  Graph(){}
  Graph(int n){}
  ~Graph(){}

  // Initialize a graph of n vertices
  virtual void Init(int n) =0;

  // Return: the number of vertices and edges
  // 
  // (should make these const)
  virtual int n() =0;
  virtual int e() =0;

  // Return v's first neighbor
  virtual int first(int v) =0;

 // Return v's next neighbor
 // returns next vertex of v after w
  virtual int next(int v, int w) =0;

  // Set the weight for an edge
  // i, j: The vertices
  // wgt: Edge weight
  virtual void setEdge(int v1, int v2, int wght) =0;

  // Delete an edge
  // i, j: The vertices
  virtual void delEdge(int v1, int v2) =0;

  // Determine if an edge is in the graph
  // i, j: The vertices
  // Return: true if edge i,j has non-zero weight
  // ....could devirtualize
  virtual bool isEdge(int i, int j) =0;

  // Return: The weight of edge i,j, or zero
  // i, j: The vertices
  virtual int weight(int v1, int v2) =0;

  // Get and Set the mark value for a vertex
  // v: The vertex,  val: The value to set
  virtual int getMark(int v) =0;
  virtual void setMark(int v, int val) =0;

  void print_matrix(){
    cout << "|V|: " << n() << "\t";
    cout << "|E|: " << e() << endl;
    cout << "Adjacency Matrix is:\n";
    for (int i = 0; i < n(); i++) {
      for (int j = 0; j < n(); j++){ 
        cout << weight(i, j) << " "; 
      } cout << "\n";
    }
  }

  void export_json(ostream& output) {
    json j;
    _build_graph(j, this);
    output << setw(4) << j << endl;
  }

};


Graph* import_json(istream& instream);

#endif
