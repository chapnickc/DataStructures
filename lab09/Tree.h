#ifndef TREE_H
#define TREE_H

#include "gentree.h"
#include "TreeNode.h"

template <typename E> 
class Tree: public GenTree<E> {
private:
  TreeNode<E>* rt;

  // Print using a preorder traversal
  void printhelp(TreeNode<E>* theroot) {
    if (theroot->isLeaf()) cout << "Leaf: ";
    else cout << "Internal: ";
    cout << theroot->value() << "\n";
    // Now process the children of "root"
    for (TreeNode<E>* temp = theroot->leftmostChild();
         temp != NULL; temp = temp->rightSibling())
      printhelp(temp);
  }

public:
  Tree() { rt = NULL; }          // Constructor

  // AWFUL! Throw away the storage
  ~Tree() { rt = NULL; }         // Destructor

  // AWFUL! Throw away the storage
  void clear() { rt = NULL;}       // Send all nodes to free store

  // Return the root of the tree
  TreeNode<E>* root() { return rt; }

  // Combine two trees
  void newroot(const E& value){
    clear();
    rt = new TreeNode<E>(value);
  }

  void print() { printhelp(rt); }   // Print a tree

};


#endif
