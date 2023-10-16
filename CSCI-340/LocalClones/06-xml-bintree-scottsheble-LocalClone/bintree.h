#ifndef NIU_CSCI330_BINTREE_IMPL_H
#define NIU_CSCI330_BINTREE_IMPL_H

#include "bintree.decl.h"

#include <vector>

template <typename BINTREENODE, typename FN>
void preorder(BINTREENODE *root, FN fn) {
  // XXX you must implement this function
}

template <typename BINTREENODE, typename FN>
void inorder(BINTREENODE *root, FN fn) {
  // XXX you must implement this function
}

template <typename BINTREENODE, typename FN>
void postorder(BINTREENODE *root, FN fn) {
  // XXX you must implement this function
}

template <typename BINTREENODE, typename FN>
void levelorder(BINTREENODE *root, FN fn) {
  // XXX you must implement this function
}

// return all of the direct children of the given node
template <typename BINTREENODE>
std::vector <BINTREENODE *> tilted_get_children(BINTREENODE * node) {
  // XXX you must implement this function
  return {}; 
}

// this function requires that BINTREENODE have the parent member
template <typename BINTREENODE>
BINTREENODE * tilted_find_parent(BINTREENODE *node) {
  // XXX you must implement this function
  return nullptr; // you'll fix this when you implement the function
}

template <typename BINTREENODE, typename FN>
void tilted_levelorder(BINTREENODE *root, FN fn) {
  // XXX you must implement this function
}

template <typename BINTREENODE>
void delete_tree(BINTREENODE * &node) {
  // XXX you must implement this function
}

#endif

