#include "Graphl.h"

#include <chrono>
#include <cmath>
#include <string>
#include <thread>
#include <stdlib.h>  
#include <ctime>

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



int minVertex(Graph* graph, int* D){
  int i, v = -1;

  for (i = 0; i < graph->n(); i++) 
    if (graph->getMark(i) == UNVISITED){ 
      v = i; break; 
    }

  // find smallest D value (linear search?)
  for (i++; i < graph->n(); i++)
    if ( graph->getMark(i) == UNVISITED && D[i] < D[v] ){ 
      v = i; 
    }

  return v;
}



void dijkstra(Graph* graph, int* D, int s) {
/* Compute shortest path distances from "s".
 * Return these distances in "D". 
 */
  int i, v, w;
  for (i=0; i < graph->n(); i++) {     // Process the vertices
    v = minVertex(graph, D);
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


// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(){
  srand(2100);

  int N = 9;
  Graph* graphs[N];

  std::clock_t start;
  double duration;

  for (int i=0; i < N; i++){ start = std::clock(); cout << "Building graph " << i; graphs[i] = _handshake_graph<Graphl>(pow(2, i+1));
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"\t\tElapsed Time: "<< duration <<'\n';

    //if (i < 4){ graphs[i]->print_matrix(); }
  }


  Graph* graph;
  double avg_cost; 
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
