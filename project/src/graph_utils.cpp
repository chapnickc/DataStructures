#ifndef _GRAPH_UTILS_
#define _GRAPH_UTILS_

#include "Graph.h"
#include "GraphL.h"
#include "GraphM.h"

#include "heap.h"
#include "json.hpp"

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

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



template <typename GraphT>
GraphT* complete_graph(int nvert){
  GraphT* graph = new GraphT(nvert);
  for (int i=0; i < nvert; i++){
    for (int j=0; j < nvert; j++){
      if ( not graph->isEdge(i, j) && not graph->isEdge(j, i) ){
        graph->setEdge(i, j, rand() % 20 + 1);
      }
    }
  }
  return graph;
}


template <typename GraphT>
void complete_graphs(std::vector<GraphT*>& graphs, ostream& logfile){
  double runtime;
  clock_t start;

  for (int i=0; i < graphs.size(); i++){ 
    start = clock(); 
    cout << "Building graph with " << pow(2,i+1) << " nodes...\n";
    graphs[i] = complete_graph<GraphT>(pow(2, i+1));
    runtime = (clock() - start) / (double) CLOCKS_PER_SEC;
    logfile << "("<< graphs[i]->n() << "," << graphs[i]->e() <<")";
    logfile <<" complete_graph(N): "<< runtime <<'\n';
  }
}


template <typename GraphT, typename Dijkstra>
void dijkstra_test(GraphT* graph, Dijkstra dijkstra, ostream& output){
  double runtime;
  clock_t start;

  int D[graph->n()];
  for (int i = 0; i < graph->n(); i++){ 
    D[i] = INFINITY; 
  }
  D[0] = 0;
  
  start = clock();
  dijkstra(graph, D, 0);
  output << "("<< graph->n() << "," << graph->e() <<")";
  runtime = (clock() - start) / (double) CLOCKS_PER_SEC;
  output << "\tdijkstra(N): "<< runtime <<'\n';
}


template <typename GraphT, typename Dijkstra>
void test_graph_vector(std::vector<GraphT*> graphs, Dijkstra dijkstra, ostream& output){
  GraphT* graph;
    for (int n=0; n < graphs.size(); n++){
      graph = graphs[n];
      dijkstra_test(graph, dijkstra, output);
  }
}






int linear_minVertex(Graph* graph, int* D){
  int i, v = -1;

  for (i = 0; i < graph->n(); i++){
    if (graph->getMark(i) == UNVISITED){ 
      v = i; break; 
    }
  }

  for (i++; i < graph->n(); i++){
    if ( graph->getMark(i) == UNVISITED && D[i] < D[v] ){ 
      v = i; 
    }
  }

  return v;
}


void linear_dijkstra(Graph* graph, int* D, int s) {
/* Compute shortest path distances from "s".
 * Return these distances in "D". 
 */
  int i, v, w;
  for (i=0; i < graph->n(); i++) {     // Process the vertices
    v = linear_minVertex(graph, D);
    graph->setMark(v, VISITED);

    if (D[v] == INFINITY){            // Unreachable vertices
      return; 
    }
    
    for (w = graph->first(v); w < graph->n(); w = graph->next(v,w))
      if (D[w] > (D[v] + graph->weight(v, w))){
        D[w] = D[v] + graph->weight(v, w);
      }
  }
}



// Simple class to represent objects to be stored in the priority queue
// Store a vertex and its best known distance
class DijkElem {

public:
  int vertex, distance;
  DijkElem(){ 
    vertex = -1; distance = -1; 
  }

  DijkElem(int v, int d){ 
    vertex = v; distance = d; 
  }
};

// Comparator class for comparing DijkElem's
class DDComp {

public:
  static bool prior(DijkElem v0, DijkElem v1){ 
    return v0.distance < v1.distance; 
  }
};

// Dijkstra's shortest paths algorithm with priority queue
void heap_dijkstra(Graph* graph, int* D, int s) {
  // v is current vertex
  int i, v, w;            

  DijkElem element;
  element.distance = 0; 
  element.vertex = s;

  DijkElem E[graph->e()];     // Heap array with lots of space
  E[0] = element;            // Initialize heap array

  heap<DijkElem, DDComp> H(E, 1, graph->e()); // Create heap
  for (i=0; i < graph->n(); i++) {         // Now, get distances
    while (graph->getMark(v) == VISITED){
      if (H.size() == 0){ return; } // Nothing to remove
      element = H.removefirst();
      v = element.vertex;
    } 

    graph->setMark(v, VISITED);

    if (D[v] == INFINITY) return;    // Unreachable vertices

    for (w = graph->first(v); w < graph->n(); w = graph->next(v,w))
      if (D[w] > ( D[v] + graph->weight(v, w) )){

        D[w] = D[v] + graph->weight(v, w);

        element.distance = D[w]; 
        element.vertex = w;
        H.insert(element);   // Insert new distance in heap
      }
  }
}


#endif
