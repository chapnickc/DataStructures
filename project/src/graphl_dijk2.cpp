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


// Simple class to represent objects to be stored in the priority queue
// Store a vertex and its best known distance
class DijkElem {
public:
  int vertex, distance;
  DijkElem() { vertex = -1; distance = -1; }
  DijkElem(int v, int d) { vertex = v; distance = d; }
};

// Comparator class for comparing DijkElem's
class DDComp {
public:
  static bool prior(DijkElem x, DijkElem y)
    { return x.distance < y.distance; }
};

// Dijkstra's shortest paths algorithm with priority queue
void dijkstra(Graph* G, int* D, int s) {
  int i, v, w;            // v is current vertex
  DijkElem temp;
  DijkElem E[G->e()];     // Heap array with lots of space
  temp.distance = 0; temp.vertex = s;
  E[0] = temp;            // Initialize heap array
  heap<DijkElem, DDComp> H(E, 1, G->e()); // Create heap
  for (i=0; i<G->n(); i++) {         // Now, get distances
    do {
      if (H.size() == 0) return; // Nothing to remove
      temp = H.removefirst();
      v = temp.vertex;
    } while (G->getMark(v) == VISITED);

    G->setMark(v, VISITED);
    if (D[v] == INFINITY) return;    // Unreachable vertices
    for (w=G->first(v); w<G->n(); w = G->next(v,w))
      if (D[w] > (D[v] + G->weight(v, w))) { // Update D
        D[w] = D[v] + G->weight(v, w);
        temp.distance = D[w]; temp.vertex = w;
        H.insert(temp);   // Insert new distance in heap
      }
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


