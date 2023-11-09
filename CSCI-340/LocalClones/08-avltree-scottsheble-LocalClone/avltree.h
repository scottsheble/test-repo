#ifndef NIU_CSCI_340_AVLTREE_H
#define NIU_CSCI_340_AVLTREE_H

#include "avltree.decl.h"

#include <iostream>

// requires a node with a parent pointer
template <typename NODEP>
void rotate_left(NODEP * &pivot) {
  // XXX You must implement this properly.
}

// requires a node with a parent pointer
template <typename NODEP>
void rotate_right(NODEP * &pivot) {
  // XXX You must implement this properly.
}

// return true iff balanced according to the avl condition
template <typename NODE>
bool is_avl(NODE * root) {
  // XXX You must implement this properly.
  return false;
}

template <typename NODEP>
int fix_avl_tree(NODEP * & root, NODEP *node) {
  // XXX You must implement this properly.
  return 9999999;
}

#endif
