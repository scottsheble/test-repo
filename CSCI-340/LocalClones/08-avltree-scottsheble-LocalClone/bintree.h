#ifndef LEHUTA_BINTREE_H_IMPL
#define LEHUTA_BINTREE_H_IMPL

#include "bintree.decl.h"

// height of tree, defined as the number of edges in the longest path
// from the root to a leaf. If you're off the tree, this should return -1.
template <typename NODE>
int height(NODE * node) {
  // XXX You need to implement this
  return 9999999;
}
template <typename NODE>
int count(NODE * root) {
  // XXX You need to implement this
  return 9999999;
}

template <typename NODE, typename FN>
void preorder(NODE *root, FN fn) {
  // XXX You need to implement this
}

template <typename NODE, typename FN>
void inorder(NODE *root, FN fn) {
  // XXX You need to implement this
}

template <typename NODE, typename FN>
void postorder(NODE *root, FN fn) {
  // XXX You need to implement this
}

template <typename NODE, typename FN>
void levelorder(NODE *root, FN fn) {
  // XXX You need to implement this
}

template <typename BINTREENODE>
void delete_tree(BINTREENODE * &node) {
  // XXX You need to implement this
  // The valgrind program will be used to check whether you're actually
  // deleting everything.
}

#endif
