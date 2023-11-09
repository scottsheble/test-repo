/******************************************************************************
 * This file is provided as a part of an NIU CSCI 340 Assignment. IT IS NOT   *
 * TO BE CHANGED. To complete the assignment, please put your code in the     *
 * files detailed in the assignment writeup.     `                            *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#ifndef NIU_CSCI340_AVLSET_DECL
#define NIU_CSCI340_AVLSET_DECL

#include <cstddef> 
#include <iterator>
#include <utility>
#include "nodes.h"
#include "bintree.h"
#include "bst.h"
#include "avltree.h"

// simple bidirectional iterator for avl nodes
template <typename T>
class avl_iterator {
  typedef NodeLRP<T> NODE;
  NODE * pos;
  NODE * prev; // previous position, if we reached the end from forward iteration, or nullptr
  NODE * next; // next position, if we went past the beginning from reverse iteration, or nullptr
  public:

    typedef T value_type;
    typedef ssize_t difference_type;

    avl_iterator() = delete;

    // These constructors all create an iterator pointing to a specific location
    avl_iterator(NODE * nodeptr)
      : pos(nodeptr), prev(nullptr), next(nullptr) {}
    avl_iterator(NODE * nodeptr, NODE *prev, NODE * next) 
      : pos(nodeptr), prev(prev), next(next) { } 
    avl_iterator(const avl_iterator <T> & source); // copy constructor

    avl_iterator <T> & operator ++ ();  // prefix increment - go forward one
    avl_iterator <T> operator ++ (int); // postfix increment - go forward one
					// 
    avl_iterator <T> & operator -- ();  // prefix decrement - go back one
    avl_iterator <T> operator -- (int); // postfix decrement - go back one

    T & operator * ();  // dereference

    bool operator == (const avl_iterator & other) const; 
};

template <typename T>
class avl_set {
  typedef NodeLRP<T> NODE;
  
  NODE * root;
  size_t node_count;

  public:
    typedef T value_type;
    typedef T key_type;
    typedef size_t size_type;
    typedef ssize_t difference_type;

    // default constructor starts empty
    avl_set() : root(nullptr), node_count(0) {};

    // you have to write this, insert everything from this iterator range
    template <typename InputIterator>
    avl_set(InputIterator start, InputIterator end);

    // destructor frees up memory from nodes
    ~avl_set();

    NODE * get_root() const { return root; }
    NODE * &get_root() { return root; }

    avl_iterator <T> begin();
    avl_iterator <T> end();
    
    std::reverse_iterator<avl_iterator <T>> rbegin();
    std::reverse_iterator<avl_iterator <T>> rend();

    bool empty() const;
    size_type size() const;
    bool is_bst() const;
    bool is_avl() const;


    template <typename FN>
    void inorder(FN fn) const; 
    template <typename FN>
    void preorder(FN fn) const; 
    template <typename FN>
    void postorder(FN fn) const; 
    template <typename FN>
    void levelorder(FN fn) const; 

    void clear();
    std::pair<avl_iterator<T>, bool> insert(const value_type & value);
    size_type erase(const key_type &key);

    size_type count(const key_type &key); 

    int height() const;
};


#endif
