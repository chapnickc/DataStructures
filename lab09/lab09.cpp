#include "TreeNode.h"
#include "Tree.h"


// Driver for testing the general tree implementation
int main() {
  Tree<int> tree;
  TreeNode<int>* ptr;
  Tree<int> tree2;
  TreeNode<int>* ptr2;

  tree.newroot(1);
  ptr = tree.root();
  cout << "Is Leaf?: " << ptr->isLeaf() << endl;
  cout << "Print the tree with one node\n";
  tree.print();
  ptr->insertFirst(new TreeNode<int>(2));
  cout << "Print the tree with two nodes\n";
  tree.print();
  ptr = ptr->leftmostChild();
  cout << "ptr now at node " << ptr->value() << "\n";
  ptr->insertNext(new TreeNode<int>(3));
  cout << "Print the tree with three nodes\n";
  tree.print();
  ptr->insertNext(new TreeNode<int>(4));
  cout << "Print the tree with four nodes\n";
  tree.print();
  ptr = ptr->rightSibling();
  cout << "ptr now at node " << ptr->value() << "\n";
  ptr->insertFirst(new TreeNode<int>(5));
  cout << "Print the tree with 5 nodes\n";
  tree.print();

  tree2.newroot(11);
  ptr2 = tree2.root();
  ptr2->insertFirst(new TreeNode<int>(12));
  ptr2 = ptr2->leftmostChild();
  ptr2->insertNext(new TreeNode<int>(13));

  return 0;
}
