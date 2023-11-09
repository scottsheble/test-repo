#ifndef NIU_CSCI340_AVL_SET_H
#define NIU_CSCI340_AVL_SET_H

#include "avl_set.decl.h"

////////////////////////////////////////////////////////////////////////////////
// avl_iterator implementations
template <typename T>
avl_iterator<T>::avl_iterator(const avl_iterator <T> & source) {
  // XXX You must implement this
}

template <typename T>
avl_iterator <T> & avl_iterator<T>::operator ++ () {  // prefix increment - go forward one
  // XXX You must implement this properly
  return *this;
}

template <typename T>
avl_iterator <T>   avl_iterator<T>::operator ++ (int) { // postfix increment - go forward one
  // XXX You must implement this properly.
  return *this;
}

template <typename T>
avl_iterator <T> & avl_iterator<T>::operator -- () {  // prefix decrement - go back one
  // XXX You must implement this properly.
  return *this;
}

template <typename T>
avl_iterator <T>   avl_iterator<T>::operator -- (int) { // postfix decrement - go back one
  // XXX You must implement this properly.
  return *this;
}

template <typename T>
T & avl_iterator<T>::operator * () {  // dereference
  // XXX You must implement this properly
  static T x = 0; // this allows compilation of provided file w/o changes, but is wrong 
  return x;  
}

template<typename T>
bool avl_iterator<T>::operator == (const avl_iterator <T> & other) const {
  // XXX You must implement this properly
  return true;
}


////////////////////////////////////////////////////////////////////////////////
// avl_set implementations

template <typename T>
template <typename InputIterator>
avl_set<T>::avl_set(InputIterator start, InputIterator end) {
  // XXX You must implement this properly
}

// destructor
template <typename T>
avl_set<T>::~avl_set() {
  // XXX You must implement this properly
}

// return iterator at beginning
template <typename T>
avl_iterator <T> avl_set<T>::begin() {
  // XXX You must implement this properly
  return avl_iterator<T>(root); // this is wrong
}

// return iterator one past the end
template <typename T>
avl_iterator <T> avl_set<T>::end() {
  // XXX You must implement this properly
  return avl_iterator<T>(root); // this is wrong
}

// reverse iterator at *its* beginning
template<typename T>
std::reverse_iterator<avl_iterator <T>> avl_set<T>::rbegin() {
  // XXX You must implement this properly
  return std::reverse_iterator<avl_iterator<T>>(root); // this is wrong
}

// reverse iterator end
template<typename T>
std::reverse_iterator<avl_iterator <T>> avl_set<T>::rend() {
  // XXX You must implement this properly
  return std::reverse_iterator<avl_iterator<T>>(root); // this is wrong
}

// these just call the traversals you did in the previous assignment
template <typename T> template <typename FN>
void avl_set<T>::inorder(FN fn) const { 
  // XXX You must implement this properly
}

template <typename T> template <typename FN>
void avl_set<T>::preorder(FN fn) const {
  // XXX You must implement this properly
}
template <typename T> template <typename FN>
void avl_set<T>::postorder(FN fn) const { 
  // XXX You must implement this properly
}
template <typename T> template <typename FN>
void avl_set<T>::levelorder(FN fn) const {
  // XXX You must implement this properly
}

template <typename T>
void avl_set<T>::clear() {
  // XXX You must implement this properly
}

template <typename T>
std::pair<avl_iterator<T>, bool> avl_set<T>::insert(const value_type & value) {
  // XXX You must implement this properly
  return std::make_pair(nullptr, false);
}

template <typename T>
typename avl_set<T>::size_type avl_set<T>::erase(const key_type &key) {
  // XXX You must implement this properly
  return 9999999;
}

template <typename T>
typename avl_set<T>::size_type avl_set<T>::count(const key_type &key) {
  // XXX You must implement this properly
  return 9999999;
}

template <typename T>
int avl_set<T>::height() const {
  // XXX You must implement this properly
  return 9999999;
}

template <typename T>
bool avl_set<T>::is_bst() const {
  // XXX You must implement this properly
  return false;
}

template <typename T>
bool avl_set<T>::is_avl() const {
  // XXX You must implement this properly
  return false;
}

template <typename T>
typename avl_set<T>::size_type avl_set<T>::size() const {
  // XXX You must implement this properly
  return 9999999;
}

#endif
