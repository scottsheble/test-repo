/**********************************************************************************************
 * NIU CSCI 340 Section 1                                                                     *
 * Assignment 6                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIU_CSCI330_BINTREE_IMPL_H
#define NIU_CSCI330_BINTREE_IMPL_H

#include "bintree.decl.h"
#include <vector>
#include <queue> 
#include <iostream> 


/**
 * @brief Each of these functions performs the traversal it is named after on the tree with 
 * root as its root, calling fn as it visits each node. Preorder.
 * 
 * @tparam BINTREENODE 
 * @tparam FN 
 * @param root 
 * @param fn 
 */
template <typename BINTREENODE, typename FN>
void preorder(BINTREENODE *root, FN fn) {
      if (root) {
        fn(root);
        preorder(root->left, fn);
        preorder(root->right, fn);
    }
}

/**
 * @brief Each of these functions performs the traversal it is named after on the tree with 
 * root as its root, calling fn as it visits each node. Inorder.
 * 
 * @tparam BINTREENODE 
 * @tparam FN 
 * @param root 
 * @param fn 
 */
template <typename BINTREENODE, typename FN>
void inorder(BINTREENODE *root, FN fn) {
      if (root) {
        inorder(root->left, fn);
        fn(root);
        inorder(root->right, fn);
    }
}

/**
 * @brief Each of these functions performs the traversal it is named after on the tree with 
 * root as its root, calling fn as it visits each node. Postorder.
 * 
 * @tparam BINTREENODE 
 * @tparam FN 
 * @param root 
 * @param fn 
 */
template <typename BINTREENODE, typename FN>
void postorder(BINTREENODE *root, FN fn) {
      if (root) {
        postorder(root->left, fn);
        postorder(root->right, fn);
        fn(root);
    }
}

/**
 * @brief Each of these functions performs the traversal it is named after on the tree with 
 * root as its root, calling fn as it visits each node. Levelorder.
 * 
 * @tparam BINTREENODE 
 * @tparam FN 
 * @param root 
 * @param fn 
 */
template <typename BINTREENODE, typename FN>
void levelorder(BINTREENODE *root, FN fn) {
      if (!root) return;

    std::queue<BINTREENODE*> q;
    q.push(root);

    while (!q.empty()) {
        BINTREENODE* current = q.front();
        q.pop();

        fn(current);

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

/**
 * @brief This function returns a vector containing pointers to all of the nodes that are 
 * direct children of node in the non-binary tree represented by this tilted binary tree. If 
 * node is nullptr or a leaf node, then return an empty vector.
 * 
 * @tparam BINTREENODE 
 * @param node 
 * @return std::vector <BINTREENODE *> 
 */
template <typename BINTREENODE>
std::vector <BINTREENODE *> tilted_get_children(BINTREENODE * node) {
    // return all of the direct children of the given node
    if(node == nullptr){
        return {};
    }
    std::vector<BINTREENODE*> result;
    node = node->left;
    while (node != nullptr){
        result.push_back(node);
        node = node->right;
    } 
    return result; 

}

/**
 * @brief This function returns a pointer to the node that is the real parent of the current 
 * node, on the non-binary tree represented by this tilted binary tree. If it has no parent, 
 * return nullptr.
 * 
 * @tparam BINTREENODE 
 * @param node 
 * @return BINTREENODE* 
 */
template <typename BINTREENODE>
BINTREENODE * tilted_find_parent(BINTREENODE *node) {
    if (node != nullptr){
        if(node->parent != nullptr && node->parent->right == node){
            return tilted_find_parent(node->parent);
        }
        else{
            return node->parent;
        }
    }
    return nullptr;
}

/**
 * @brief This function performs a level order traversal of the non-binary tree that was tilted 
 * to create the binary tree with root root. It will call fn to visit each node. This traversal 
 * is best done non-recursively. I recommend using a queue. Remember that each of your nodes 
 * can actually have multiple children instead of just the two that it would have if we were 
 * treating the binary tree normally.
 * 
 * @tparam BINTREENODE 
 * @tparam FN 
 * @param root 
 * @param fn 
 */
template <typename BINTREENODE, typename FN>
void tilted_levelorder(BINTREENODE *root, FN fn) {
    if (!root) return;

    std::queue<BINTREENODE*> q;
    q.push(root);

    while (!q.empty()) {
        BINTREENODE* current = q.front();
        q.pop();

        fn(current);

        // Use 'tilted_get_children' to get the children of the current node.
        std::vector<BINTREENODE*> children = tilted_get_children(current);

        for (BINTREENODE* child : children) {
            q.push(child);
        }
    }
}

/**
 * @brief Deletes all of the nodes in the tree with root as its root, freeing up any 
 * dynamically-allocated memory used.
 * 
 * @tparam BINTREENODE 
 * @param node 
 */
template <typename BINTREENODE>
void delete_tree(BINTREENODE * &node) {
      if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
        node = nullptr;
    }
}

#endif

