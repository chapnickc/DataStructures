//#include "book.h"
#include "Graphl.h"
#include <string>
#include <cmath>


int minVertex(Graph* graph, int* D) {
  int i, v = -1;

  for (i = 0; i < graph->n(); i++) 
    if (graph->getMark(i) == UNVISITED){ 
      v = i; break; 
    }

  // find smallest D value
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

  graph = createGraph<Graphl>(fid);

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



  int D[graph->n()];
  for (int i = 0; i < graph->n(); i++){ 
    D[i] = INFINITY; 
  }
  D[0] = 0;

  dijkstra(graph, D, 0);

  for (int k = 0; k < graph->n(); k++){ 
    cout << D[k] << " "; 
  }
  cout << endl;

  return 0;
}
