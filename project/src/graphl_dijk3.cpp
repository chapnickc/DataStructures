#include "Graphl.h"
#include "heap.h"

#include <chrono>
#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <thread>


using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds

template <typename GraphT>
Graph* _handshake_graph(int nvert){
  Graph* graph = new GraphT(nvert);
  for (int i=0; i < nvert; i++){
    for (int j=0; j < nvert; j++){
      if (i != j && (not graph->isEdge(i, j)) ){
        graph->setEdge(i, j, rand() % 20 + 1);
      }
    }
  }
  return graph;
}


int minVertex(Graph* G, int* D) { // Find min cost vertex
  int i, v = -1;
  // Initialize v to some unvisited vertex
  for (i=0; i<G->n(); i++)
    if (G->getMark(i) == UNVISITED) { v = i; break; }
  for (i++; i<G->n(); i++)  // Now find smallest D value
    if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
      v = i;
  return v;
}


// Compute shortest path distances from "s".
// Return these distances in "D".
void dijkstra(Graph* G, int* D, int s) {
  int i, v, w;
  for (i=0; i<G->n(); i++) {      // Process the vertices
    v = minVertex(G, D);
    if (D[v] == INFINITY) return; // Unreachable vertices
    G->setMark(v, VISITED);
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w)))
        D[w] = D[v] + G->weight(v, w);
  }
}




// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(){
  srand(2100);

  int N = 9;
  Graph* graphs[N];

  std::clock_t start;
  double duration;

  for (int i=0; i < N; i++){
    start = std::clock();
    cout << "Building graph " << i;
    graphs[i] = _handshake_graph<Graphl>(pow(2, i+1));
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"\t\tElapsed Time: "<< duration <<'\n';
  }


  Graph* graph;
  for (int n=0; n < N; n++){
    start = std::clock();
    graph = graphs[n];
    int D[graph->n()];
    for (int i = 0; i < graph->n(); i++){ 
      D[i] = INFINITY; 
    }

    D[0] = 0;
    dijkstra(graph, D, 0);

    cout<< "|V|: " << graph->n() << "\t\t|E|: " << graph->e();
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"\tElapsed Time: "<< duration <<'\n';
  }

  return 0;
}


