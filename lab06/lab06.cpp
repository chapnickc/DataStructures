#include "book.h"
#include "BSTNode.h"
#include <iostream>
using namespace std;

/* 1 */
template <typename Key, typename E>
void printSortedBST(BSTNode<Key, E>* root){
  if (root->left()){
    printSortedBST(root->left());
  }

  cout << root->element() << endl;

  if (root->right()){
    printSortedBST(root->right());
  }
}

/* 2 */
template <typename Key, typename E>
void printRange(BSTNode<Key,E>* root, Key lowkey, Key highkey){
  if (root->left()){ printRange(root->left(), lowkey, highkey); }

  if ( root->key() > lowkey && root->key() < highkey ){
    cout << root->element() << endl;
  }

  if (root->right()){ printRange(root->right(), lowkey, highkey); }
}



/* 3 */
template <typename E>
bool checkBST(BinNode<E>* root){
  if (root->isLeaf()){ return true; }

  bool leftok = true;
  bool rightok = true;

  if (root->left()){
    if (root->left()->element() < root->element()){
      leftok = checkBST(root->left());
    }
    else{ return false; }
  }

  if (root->right()){
    if (root->right()->element() > root->element()){
      rightok = checkBST(root->right());
    }
    else {
      return false;
    }
  }

  if (leftok && rightok){ return true; }
  else { return false; }
}






int main(){

  BSTNode<int,int>* left = new BSTNode<int,int>(50,50); 
  left->setLeft(new BSTNode<int,int>(10,10));
  left->setRight(new BSTNode<int,int>(75,75));


  BSTNode<int,int>* right = new BSTNode<int,int>(200,200);
  right->setLeft(new BSTNode<int,int>(150,150));
  right->setRight(new BSTNode<int,int>(300,300));

  BSTNode<int,int>* root = new BSTNode<int,int>(100,100);
  root->setLeft(left);
  root->setRight(right);


  BSTNode<int,int>* newroot = new BSTNode<int,int>(50,50); 
  newroot->setLeft(new BSTNode<int,int>(60,60));
  newroot->setRight(new BSTNode<int,int>(40,40));


  cout << "Calling printSortedBST()..." << endl;
  printSortedBST(root);

  cout << "Calling printRange()..." << endl;
  printRange(root, 5,101);

  cout << "Calling checkBST()..." << endl;
  cout << checkBST(root) << endl;
  cout << checkBST(newroot) << endl;

  return 0;

}
