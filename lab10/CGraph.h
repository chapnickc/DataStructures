#ifndef GRAPH_H
#define GRAPH_H

#include "json.hpp"
using json = nlohmann::json;

class CGraph : public Graph {
  private:

  public:
    CGraph() {}          // Default constructor
    virtual ~CGraph() {} // Base destructor

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


    void exportJSON(ofstream& output){
    void exportCSV(ofstream& output)=0;

};


#include "graph.h"
#include "json.hpp"

using json = nlohmann::json;


      json j;
      j["graph"] = { 
          { "directed", false }, 
          { "type", "graph type" }, 
          { "label", "graph label" },
          { "metadata", { "user-defined": "values" }}
        };

      j["nodes"] = {"none"};
      j["edges"]= {"none"};

      output << std::setw(4) << j << std::endl;
    }



