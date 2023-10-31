#ifndef NIU_CSCI340_BST_H_IMPL
#define NIU_CSCI340_BST_H_IMPL

#include "bst.decl.h"
#include <iostream>

template <typename NODE, typename T>
NODE * bst_find(NODE *root, const T & value) {
  // XXX You need to implement this
  return nullptr;
}

// implement this for nodes that have parent pointers, and set them appropriately
template <typename NODEP, typename T>
NODEP * bst_insert(NODEP * &root, const T & value) {
  // XXX You need to implement this
  return nullptr;
}
// requires a node with a parent pointer
template <typename NODEP, typename T>
NODEP * bst_remove_value(NODEP * &root, const T & value) {
  // XXX You need to implement this
  return nullptr;
}

// only needs left and right pointers
template <typename NODE>
bool is_bst(NODE *root) {
  // XXX You need to implement this
  return false;
}

template <typename NODE>
inline NODE * bst_minimum(NODE * root) {
  // XXX You need to implement this
  return nullptr;
}

template <typename NODE>
inline NODE * bst_maximum(NODE * root) {
  // XXX You need to implement this
  return nullptr;
}

template <typename NODEP>
NODEP * successor(NODEP * node) {
  // XXX You need to implement this
  return nullptr;
}

#endif
