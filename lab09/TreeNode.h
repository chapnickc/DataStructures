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
  TreeNode(const E& val) { 
    element = val; size = 0; par = NULL;
  }

  TreeNode(const E& val, TreeNode<E>* parent){
    element = val; par = parent; size = 0;
  }  

  ~TreeNode() {}                     // Destructor

  E value(){ return element; }

  bool isLeaf(){ return size == 0; }

  TreeNode* parent(){ return par; }

  TreeNode* leftmostChild(){ 
    if ( !isLeaf() ){
      children.moveToStart();
      return children.getValue();
    }
    return NULL;
  }

  TreeNode* rightSibling(){
    if (par->size > 1){
      par->children.moveToStart();
      do {
        par->children.next();
      } while (par->children.getValue() != this);
      par->children.next();
      cout << "MADE IT HERE" << endl;
      return par->children.getValue();
    }
    return NULL;
  }

  void setValue(E& val){ element = val; }

  void insertFirst(TreeNode<E>* node){  // Insert first child
    node->par = this;
    children.moveToStart(); 
    children.insert(node);
    size++;
  } 

  void insertNext(TreeNode<E>* node){  // Insert next sibling
    par->children.moveToStart();
    while (par->children.getValue() != this){
      par->children.next();
    }
    par->children.next();
    node->par = par;
    children.insert(node);
    par->size++;
  }

  void removeFirst(){           // Remove first child
    children.moveToStart();
    children.remove();
    size--;
  }

  void removeNext(){            // Remove right sibling
    if (par->size > 1){
      par->children.moveToStart();
      while (par->children.getValue() != this){
        par->children.next();
      }
      par->children.next();
      par->children.remove();
      par->size--;
    }
  } 

};

#endif
