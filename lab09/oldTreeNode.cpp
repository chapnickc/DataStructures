
#include "TreeNode.h"

E TreeNode::value(){ return value; }

bool TreeNode::isLeaf(){ return size > 0; }

TreeNode* TreeNode::parent(){ return parent; }

TreeNode* TreeNode::leftmostChild(){ 
  if ( !isLeaf() ){
    children.moveToStart();
    return children.getValue();
  }
  else {
    return -1;
  }
}

TreeNode* rightSibling(){
  if (parent->size > 1){
    parent->children.moveToStart();
    while (parent->children.getValue() != this){
      parent->children.next();
    }
    parent->children.next();
    return parent->children.getValue();
  }
  else{
    return -1;
  }

}

template <typename E>
void TreeNode::setValue(E& val){ value = val; }

template <typename E>
void TreeNode::insertFirst(TreeNode<E>* node){  // Insert first child
  node->parent = this;
  children.moveToStart(); 
  children.insert(node);
  size++;
} 

template <typename E>
void TreeNode::insertNext(TreeNode<E>* node){  // Insert next sibling
  parent->children.moveToStart();
  while (parent->children.getValue() != this){
    parent->children.next();
  }
  parent->children.next()
  node->parent = parent;
  children.insert(node);
  parent->size++;
}

void TreeNode::removeFirst(){           // Remove first child
  children.moveToStart();
  children.remove();
  size--;
}

void TreeNode::removeNext(){            // Remove right sibling
  if (parent->size > 1){
    parent->children.moveToStart();

    while (parent->children.getValue() != this){
      parent->children.next();
    }

    parent->children.next();
    parent->children.remove();
    parent->size--;
  }
} 

