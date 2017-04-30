#ifndef _GRAPH_UTILS_
#define _GRAPH_UTILS_

#include "Graph.h"

#include "GraphM.h"
#include "GraphL.h"
#include "heap.h"

#include <cmath>
#include <vector>


template <typename GraphT>
GraphT* complete_graph(int nvert){
  GraphT* graph = new GraphT(nvert);
  for (int i=0; i < nvert; i++){
    for (int j=0; j < nvert; j++){
      if ( (i != j) && (not graph->isEdge(i, j)) ){
        graph->setEdge(i, j, rand() % 20 + 1);
      }
    }
  }
  return graph;
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


template <typename GraphT, typename Dijkstra>
void test_graph_array(std::vector<GraphT*> graphs, Dijkstra dijkstra){
  GraphT* graph;
  double runtime;
  clock_t start;

  for (int n=0; n < graphs.size(); n++){
    graph = graphs[n];

    int D[graph->n()];
    for (int i = 0; i < graph->n(); i++){ 
      D[i] = INFINITY; 
    }
    D[0] = 0;
    
    start = clock();
    dijkstra(graph, D, 0);

    cout << "("<< graph->n() << "," << graph->e() <<")";
    runtime = (clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "\tDijk-runtime: "<< runtime <<'\n';
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
  DijkElem E[graph->e()];     // Heap array with lots of space

  element.distance = 0; 
  element.vertex = s;

  E[0] = element;            // Initialize heap array

  heap<DijkElem, DDComp> H(E, 1, graph->e()); // Create heap
  for (i=0; i < graph->n(); i++) {         // Now, get distances
    do {
      if (H.size() == 0) return; // Nothing to remove
      element = H.removefirst();
      v = element.vertex;
    } 
    while (graph->getMark(v) == VISITED);

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







/*
int main(int argc, char** argv) {

  FILE *fid;
  Graph* graph;

  if (argc != 2) { 
    cout << "Usage: grdijkl1 <file>\n"; 
    exit(-1); 
  }

  if ((fid = fopen(argv[1], "rt")) == NULL) { 
    cout << "Unable to open file |" << argv[1] << "|\n";
    exit(-1);
  }

  if (graph == NULL) { 
    cout << "Unable to create graph\n"; 
    exit(-1); 
  }
  else {
    string fpath = argv[1];
    string fname = fpath.substr(0, fpath.rfind("."));
    ofstream outfile(fname + ".json");
    graph->export_json(outfile);
  }



    return 0;
}
*/

#endif
