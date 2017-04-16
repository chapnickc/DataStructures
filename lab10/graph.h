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
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Graph abstract class. This ADT assumes that the number
// of vertices is fixed when the graph is created.
class Graph {
  private:
    void operator =(const Graph&) {}     // Protect assignment
    Graph(const Graph&) {}         // Protect copy constructor

  public:
    Graph() {}          // Default constructor
    virtual ~Graph() {} // Base destructor

    // Initialize a graph of n vertices
    virtual void Init(int n) =0;

    // Return: the number of vertices and edges
    // should make these const
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

    // Return an edge's weight
    // i, j: The vertices
    // Return: The weight of edge i,j, or zero
    virtual int weight(int v1, int v2) =0;

    // Get and Set the mark value for a vertex
    // v: The vertex
    // val: The value to set
    virtual int getMark(int v) =0;
    virtual void setMark(int v, int val) =0;


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

    void print_matrix(Graph* graph){
      cout << "|V|: " << graph->n() << endl;
      cout << "|E|: " << graph->e() << endl;
      cout << "Adjacency Matrix is:\n";
      for (int m = 0; m < graph->n(); m++) {
        for (int n = 0; n < graph->n(); n++){ 
          cout << graph->weight(m, n) << " "; 
        } cout << "\n";
      }
    }


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
      std::vector<json> edges(g->e());
      int i=0; 
      json edge;
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

};
#endif
