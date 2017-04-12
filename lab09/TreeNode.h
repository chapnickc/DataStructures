#ifndef TREENODE_H
#define TREENODE_H

#include "gentree.h"
#include "llist.h"

template <typename E> 
class TreeNode: public GTNode<E> {
private:
  E element;
  int size;
  TreeNode<E>* par;
  LList<TreeNode<E>* > children;

public:
  TreeNode(const E& val) 
    { element = val; size = 0; par = NULL; }

  TreeNode(const E& val, TreeNode<E>* parent)
    { element = val; par = parent; size = 0;  }  

  ~TreeNode(){}

  E value(){ return element; }
  void setValue(E& val){ element = val; }

  bool isLeaf(){ return size == 0; }

  TreeNode<E>* parent(){ return par; }

  TreeNode<E>* leftmostChild(){ 
    if ( !isLeaf() ){
      children.moveToStart();
      return children.getValue();
    }
    return NULL;
  }

  TreeNode<E>* rightSibling(){
    par->children.moveToStart();
    while ( par->children.getValue() != this ){ par->children.next(); }
    if (par->children.currPos() < par->children.length()-1){
      par->children.next();
      return par->children.getValue();
    }
    return NULL;
  }

  void insertFirst(TreeNode<E>* node){  // Insert first child
    node->par = this;
    children.moveToStart(); 
    children.insert(node);
    size++;
  } 

  void removeFirst(){           // Remove first child
    children.moveToStart();
    children.remove();
    size--;
  }

  void insertNext(TreeNode<E>* node){  // Insert next sibling
    par->children.moveToStart();
    while (par->children.getValue() != this){ par->children.next(); }
    par->children.next();
    node->par = par;
    par->children.insert(node);
    par->size++;
  }

  void removeNext(){            // Remove right sibling
    par->children.moveToStart();
    while ( par->children.getValue() != this ){ par->children.next(); }
    par->children.next();
    if (par->children.getValue() != this){
      par->children.remove();
      par->size--;
    }
  }

};

#endif
