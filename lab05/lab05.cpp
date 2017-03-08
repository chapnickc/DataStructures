#include "book.h"
#include "BSTNode.h"

#include "lqueue.h"
#include <algorithm>

using std::max;

// Count the number of nodes in a binary tree
template <typename E>
int count(BinNode<E>* root) {
  if (root == NULL) return 0;  // Nothing to count
  return 1 + count(root->left())
           + count(root->right());
}

// The height of a tree is the number of edges 
// from the root node to the deepest leaf
template <typename E>
int height(BinNode<E>* root) {
  if (root == NULL) return -1;
  return 1 + max(height(root->left()), height(root->right()));
}

template <typename E>
int leaf_count(BinNode<E>* root) {
  if (root->isLeaf()) return 1; 
  return leaf_count(root->left()) + leaf_count(root->right());
}


template <typename E>
int sum_nodes(BinNode<E>* root) {
  if (root == NULL) return 0;
  return root->element() + sum_nodes(root->left()) +  sum_nodes(root->right());
}

template <typename E>
bool search(BinNode<E>* root, const E& val) {
  if (root == NULL) return false;
  if (root->element() == val) return true; 
  return search(root->left(), val) || search(root->right(), val);
}

template <typename E>
void print_tree(BinNode<E>* root) {
  // print the tree "inorder"
  if (root == NULL) return;
  cout << root->element() << endl;
  print_tree(root->left());
  print_tree(root->right());
}
/*
template <typename E>
void print_tree_by_level(BinNode<E>* root) {
    // adaptation of level printing based on the implementation from:
    // https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html
    // 
    // Note: this is based on preorder 
  LQueue<BinNode<E>* > nodeQueue;
  nodeQueue.enqueue(root);

  int nodesCurrentLevel = 1;
  int nodesNextLevel = 0;       
  BinNode<E>* currNode; 
  do {
    currNode = nodeQueue.dequeue();
    nodesCurrentLevel--;

    if ( currNode != NULL ){
      cout << currNode->element() << endl;
      if (currNode->left())
        { nodeQueue.enqueue(currNode->left()); nodesCurrentLevel++; }
      
      if (currNode->right())
        { nodeQueue.enqueue(currNode->right()); nodesCurrentLevel++; }
    }

    // will not run until the children of a given level are printed
    if (nodesCurrentLevel == 0){          
      nodesCurrentLevel = nodesNextLevel;
      nodesNextLevel = 0; 
    }

  } while (nodeQueue.length() > 0);


}
*/

template <typename E>
void print_tree_by_level(BinNode<E>* root) {
  LQueue<BinNode<E>* > nodeQueue;
  nodeQueue.enqueue(root);
  BinNode<E>* current;
  do {
    current = nodeQueue.dequeue();
    if (current != NULL){
      cout << current->element() << endl;
      nodeQueue.enqueue(current->left());
      nodeQueue.enqueue(current->right());
    }
  } while(nodeQueue.length() > 0);
}


/*
template <typename E>
E getMaxValue(BinNode<E>* root){
  if (root->isLeaf()) { return root->element(); }
  
  else if (getMaxValue(root->left()) > getMaxValue(root->right()) && getMaxValue(root->left()) > root->element()){
    return getMaxValue(root->left());
  }

  else if (getMaxValue(root->right()) > getMaxValue(root->left()) && getMaxValue(root->right()) > root->element()){
    return getMaxValue(root->right());
  }
  else {
    return root->element();
  }
}
*/

/*
template <typename E>
E getMaxValue(BinNode<E>* root){
  if (root->isLeaf()) { return root->element(); }

  E maxval = root->element(); 
  if (root->left() != NULL){
    maxval = max(maxval, getMaxValue(root->left())); 
  }

  if (root->right() != NULL){
    maxval = max(maxval, getMaxValue(root->right()));
  }
  return maxval;

}
*/

template <typename E>
E getMaxValue(BinNode<E>* root){
  if (root->isLeaf()) { return root->element(); }
  E maxval = getMaxValue(root->left()) > getMaxValue(root->right()) ? getMaxValue(root->left()) : getMaxValue(root->right());
  return root->element() > maxval ? root->element() : maxval;
}



int main()
{
  BSTNode<int,int>* root = new BSTNode<int,int>(100,100);
  BSTNode<int,int>* left = new BSTNode<int,int>(2,2);
  BSTNode<int,int>* right = new BSTNode<int,int>(3,3);
  right->setLeft(new BSTNode<int,int>(10,10));
  right->setRight(new BSTNode<int,int>(20,20));
  left->setLeft(new BSTNode<int,int>(4,4));
  left->setRight(new BSTNode<int,int>(5,5));
  left->setRight(new BSTNode<int,int>(6,6));
  root->setLeft(left);
  root->setRight(right);

  cout << "\nCalling print_tree()..." << endl;
  print_tree(root);


  cout << "\nNode count = " << count(root) << endl;
  cout << "Height = " << height(root) << endl;
  cout << "Leaf count = " << leaf_count(root) << endl;
  cout << "Sum of node values = " << sum_nodes(root) << "\n\n";
  for (int i=0; i <= 6; i++) {
    if (search(root, i)) {
      cout << "Found " << i << " in the tree..." << endl;
    }
    else {
      cout << "Did not find " << i << " in the tree..." << endl;
    }
  }

  cout << "\nCalling print_tree_by_level()..." << endl;
  print_tree_by_level(root);

  int maxval = getMaxValue(root);
  cout << "Max value is: " <<maxval << endl;

}
