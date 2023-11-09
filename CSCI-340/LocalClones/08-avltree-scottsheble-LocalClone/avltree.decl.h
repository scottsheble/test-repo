/******************************************************************************
 * This file is provided as a part of an NIU CSCI 340 Assignment. IT IS NOT   *
 * TO BE CHANGED. To complete the assignment, please put your code in the     *
 * files detailed in the assignment writeup.     `                            *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#ifndef NIU_CSCI_340_AVLTREE_DECL_H
#define NIU_CSCI_340_AVLTREE_DECL_H

template <typename NODEP>
void rotate_left(NODEP * &pivot);

template <typename NODEP>
void rotate_right(NODEP * &pivot);

template <typename NODE>
bool is_avl(NODE * root);

template <typename NODEP>
int fix_avl_tree(NODEP * & root, NODEP *node);

#endif
