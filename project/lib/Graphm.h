#ifndef GRMAT_H
#define GRMAT_H
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Include this file to access Graph representation implemented using an
// Adjacency Matrix.

#include <stdio.h>
#include <ctype.h>

// Used by the mark array
#define UNVISITED 0
#define VISITED 1

#include "graph.h"

// Implementation for the adjacency matrix representation
class Graphm : public Graph {

  private:
    // Store number of vertices, edges
    int numVertex, numEdge;

    // Pointer to adjacency matrix, 
    int** matrix;          
    int* mark;              

  public:
    Graphm(int numVert){ 
      _init(numVert); 
    }

    ~Graphm() {
      delete[] mark; 
      for (int i=0; i < numVertex; i++){
        delete[] matrix[i];
      }
      delete[] matrix;
    }

    void _init(int n){
      int i;
      numVertex = n;
      numEdge = 0;
      mark = new int[n];
      for (i = 0; i < numVertex; i++){
        mark[i] = UNVISITED;
      }

      matrix = (int**) new int*[numVertex]; // Make matrix, numVertex rows
      for (i=0; i < numVertex; i++){
        matrix[i] = new int[numVertex];
      }

      // Initialize weights to 0 
      for (i = 0; i < numVertex; i++) {
        for (int j = 0; j < numVertex; j++){
          matrix[i][j] = 0;
        }
      }
    }

    int n(){ return numVertex; }
    int e(){ return numEdge; } 
    
    int first(int v) {
      /* Return first neighbor of "v" */
      for (int j=0; j<numVertex; j++)
        if (matrix[v][j] != 0) return j;
      return numVertex;           // Return n if none
    }


    int next(int v, int w) {
      /* Return v's next neighbor after w */
      for(int j=w+1; j<numVertex; j++)
        if (matrix[v][j] != 0)
          return j;
      return numVertex;           // Return n if none
    }

    // Set edge (v1, v2) to "wt"
    void setEdge(int v1, int v2, int wt) {
      Assert(wt>0, "Illegal weight value");
      if (matrix[v1][v2] == 0) numEdge++;
      matrix[v1][v2] = wt;
    }

    void delEdge(int v1, int v2) { 
      if (matrix[v1][v2] != 0){ numEdge--; }
      matrix[v1][v2] = 0;
    }

    bool isEdge(int i, int j) { 
      return matrix[i][j] != 0; 
    }

    int weight(int v1, int v2) { return matrix[v1][v2]; }

    int getMark(int v) { return mark[v]; }
    void setMark(int v, int val) { mark[v] = val; }
};

#include "graphutil.cpp"
#endif
