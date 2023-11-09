/******************************************************************************
 * This file is provided as a part of an NIU CSCI 340 Assignment. IT IS NOT   *
 * TO BE CHANGED. To complete the assignment, please put your code in the     *
 * files detailed in the assignment writeup.     `                            *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#include <iostream>
#include <algorithm>

#include "nodes.h"

#include "bintree.decl.h"
#include "bintree.h"

#include "bst.decl.h"
#include "bst.h"

#include "avltree.decl.h"
#include "avltree.h"

#include "testing.h"

template <typename CONTAINER>
void test_rotate(const char * label, CONTAINER input, direction dir, int rotate_val) {
  using namespace std;
  typedef NodeLRP <int> NODE;

  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// test-rotate - " << label << "\n";
  cout << "////////////////////////////////////////////////////////////////////////////////\n";

  NODE * root = nullptr;

  cout << "  Constructing BST by inserting [ ";
  for(auto x: input) {
    cout << x << " ";
    bst_insert(root, x);
  }
  cout << "]\n";

  cout << "  Before rotation: \n";
  print_tree_stats(root);
  
  cout << "  After rotation " << dirstr(dir) << " on node containing " << rotate_val << ": \n";
  NODE * cur = bst_find(root, rotate_val);
  if(cur == nullptr) {
    cout << "ERROR: Did not find the value requested!\n";
  }
  if(dir == direction::left) {
    if(cur == root) rotate_left(root); 
    else rotate_left(pointerref(cur)); }
  else {
    if(cur == root) rotate_right(root);
    else rotate_right(pointerref(cur));
  }
  print_tree_stats(root);
  delete_tree(root);
}
int main() {
  using std::cout;
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// test-rotate - test your tree rotation functions\n";
  cout << "//   \n";
  cout << "//   For these tests, a sequence of numbers is inserted in the order given into\n";
  cout << "// your tree using bst_insert (no AVL fixing is done). A rotation is then \n";
  cout << "// performed using the specified node as a pivot.  \n";
  cout << "//   Statistics about your tree are printed out before and after the rotation. It\n";
  cout << "// will likely be helpful to sketch out the actual trees so you have an idea of  \n";
  cout << "// what to expect. The number of nodes should never change, and is_bst should  \n";
  cout << "// always stay true for these examples. \n";
  test_rotate<std::vector<int>>("1,2,3", {1,2,3}, left, 1);
  test_rotate<std::vector<int>>("3,2,1", {3,2,1}, right, 3);
  test_rotate<std::vector<int>>("right at root of 4,2,5,1,3", {4,2,5,1,3}, right, 4);
  test_rotate<std::vector<int>>("left at root of 2,1,4,3,5",  {2,1,4,3,5}, left, 2);
  test_rotate<std::vector<int>>("1-7, rotate left at bottom (5)", {1,2,3,4,5,6,7}, left,  5);
  test_rotate<std::vector<int>>("7-1, rotate right at bottom (3)", {7,6,5,4,3,2,1}, right, 3);
}
