
// Print using a preorder traversal
template <typename E> 
void Tree<E>::printpreorder(TreeNode<E>* theroot) {
  if ( theroot->isLeaf() ){ cout << "Leaf: " };
  else { cout << "Internal: " };
  cout << theroot->value() << "\n";

  // Now process the children of "root"
  for (TreeNode<E>* temp = theroot->leftmostChild();
       temp != NULL; 
       temp = temp->rightSibling())
    printpreorder(temp);
}

template <typename E> Tree<E>::Tree() { root = NULL; }  
template <typename E> Tree<E>::Tree(TreeNode<E>* rt) { root = rt; }

// bad! Throw away the storage
template <typename E> Tree<E>::~Tree() { root = NULL; }

/* Attributes */
template <typename E> TreeNode<E>* Tree<E>::getRoot(){ return root; }

template <typename E> void Tree<E>::newroot(const E& value)
{ // Combine two trees
  clear(); root = new TreeNode<E>(value); }

void Tree<E>::clear() { delete root = NULL; }

void Tree<E>::print() { printpreorder(root); }

