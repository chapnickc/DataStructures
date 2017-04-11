#ifndef UF_H
#define UF_H

#include "alist.h"

// General tree representation for UNION/FIND
template <typename E>
class ParPtrTree {
  private:
    //int* nodeArray;
    AList nodeList;
    int size;                       // Size of node array
    int FIND(int) const;            // Find root
  public:
    ParPtrTree(int);
    ~ParPtrTree() { delete [] nodeArray; }
    void UNION(int, int);           // Merge equivalences
    bool differ(int, int);          // True if not in same tree
};

template <typename E>
ParPtrTree::ParPtrTree(int sz) {
  size = sz;
  nodeArray = new E[sz];
  for(int i=0; i < sz; i++){ nodeArray[i] = ROOT };
}

// Return true if nodes are in different trees
bool ParPtrTree::differ(int a, int b) {
  int root1 = FIND(a);
  int root2 = FIND(b);
  return root1 != root2;
}

// Merge subtrees
void ParPtrTree::UNION(int a, int b) {
  int root1 = FIND(a);
  int root2 = FIND(b);
  if (root1 != root2) nodeArray[root2] = root1; // Merge
}

// FIND with path compression
int ParPtrTree::FIND(int curr) const {
  if (nodeArray[curr] == ROOT) return curr; // At root
  nodeArray[curr] = FIND(nodeArray[curr]);
  return nodeArray[curr];
}

#endif
