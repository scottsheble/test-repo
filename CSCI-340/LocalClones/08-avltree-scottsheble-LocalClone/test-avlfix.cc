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

template <typename NODE, typename T>
void describe_insertion(NODE * cur, const T & x) {
  using namespace std;
  if(cur == nullptr) {
    cout << "  Attempted but failed to insert node with value " << x << "\n";
  }
  else {
    cout << "  Inserted node with value " << x;
    if(cur->parent == nullptr) {
      cout << " as the root.\n";
    }
    else if(cur->parent->left == cur) {
      cout << " to the left of the node containing " << cur->parent->data << "\n";
    }
    else if(cur->parent->right == cur) {
      cout << " to the right of the node containing " << cur->parent->data << "\n";
    }
    else {
      cout << " and didn't set the parent pointer properly. Fix your code.\n";
    }
  }
}

template <typename T>
void test_avlfix(const std::string &label, std::vector <T> v) {
  using namespace std;
  typedef NodeLRP <T> NODE;

  NODE * root = nullptr;
  NODE * cur = nullptr;

  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// Constructing and testing - " << label << "\n";
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "\n";

  cout << "Inserting nodes in tree:\n";
  for(auto x: v) {
    cur = bst_insert(root, x);
    describe_insertion(cur, x); 
  }
 
  cout << "\n";
  cout << "Stats before fix_avl_tree\n";
  print_tree_stats(root);
  
  // cur is pointing to the last node inserted, which is the one that will have caused the violation
  int n = fix_avl_tree(root, pointerref(cur)); 
  cout << "Your fix_avl_tree fixed " << n << " problem(s) with AVL\n\n";

  cout << "Stats after fix_avl_tree\n";
  print_tree_stats(root);
  
  delete_tree(root);
}

int main() {
  using namespace std; 
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// test-avlfix - tests your fix_avl_tree function on known trees  \n";
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "\n";

  test_avlfix<int>("1->2->3 straight to the right, RR condition",    { 1,2,3 });
  test_avlfix<int>("1<-2<-3 straight to the left, LL condition",     { 3,2,1 });
  test_avlfix<int>("1,3,2 to the right and then left, RL condition", { 1,3,2 });
  test_avlfix<int>("3,1,2 to the left and then right, LR condition", { 3,1,2 });
  test_avlfix<int>("4,3,5,2,1 - LL condition at 3", { 4,3,5,2,1});
  test_avlfix<int>("4,3,5,1,2 - LR condition at 3", { 4,3,5,1,2});
  test_avlfix<int>("2,1,3,5,4 - RL condition at 3", { 2,1,3,5,4});
  test_avlfix<int>("2,1,3,4,5 - RR condition at 3", { 2,1,3,4,5});

}

