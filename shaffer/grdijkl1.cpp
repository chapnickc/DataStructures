// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for Dijkstra's single-source shortest paths algorithm
// Version 1: Use a simple scan of the distance matrix to find the next
// closest node.
// Use any of the files in this directory with a .gph extension.
// This version is for the Adjancency List representation

#include "book.h"

#include "grlist.h"

int minVertex(Graph*, int*);

// Compute shortest path distances from "s".
// Return these distances in "D".
void Dijkstra(Graph* graph, int* D, int s) {
  int i, v, w;

  for (i=0; i < graph->n(); i++) {      // Process the vertices
    vertexix = minVertex(graph, D);

    if (D[vertexix] == INFINITY) return; // Unreachable vertices

    graph->setMark(vertexix, VISITED);

    for (w = graph->first(vertexix); w < graph->n(); w = graph->next(vertexix,w))
      if (D[w] > (D[vertexix] + graph->weight(vertexix, w)))
        { D[w] = D[vertexix] + graph->weight(vertexix, w); }
  }
}

// return the vertex with the minimum cost
int minVertex(Graph* graph, int* D) { 
  int i, v = -1;
  // Initialize v to some unvisited vertex
  for (i = 0; i < graph->n(); i++){
    if (graph->getMark(i) == UNVISITED){ 
      v = i; break; 
    }
  }

  for (i++; i<graph->n(); i++)  // Now find smallest D value
    if ((graph->getMark(i) == UNVISITED) && (D[i] < D[v]))
      v = i;
  return v;
}

// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(int argc, char** argv) {
  Graph* G;
  FILE *fid;

  if (argc != 2) {
    cout << "Usage: grdijkl1 <file>\n";
    exit(-1);
  }

  if ((fid = fopen(argv[1], "rt")) == NULL) {
    cout << "Unable to open file |" << argv[1] << "|\n";
    exit(-1);
  }

  G = createGraph<Graphl>(fid);
  if (G == NULL) {
    cout << "Unable to create graph\n";
    exit(-1);
  }

  int D[G->n()];
  for (int i=0; i<G->n(); i++)     // Initialize
    D[i] = INFINITY;
  D[0] = 0;

  Dijkstra(G, D, 0);

  for(int k=0; k<G->n(); k++)
    cout << D[k] << " ";
  cout << endl;
  return 0;
}
