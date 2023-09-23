/**********************************************************************************************
 * NIU CSCI 340 Section YOUR_SECTION                                                          *
 * Assignment 2b                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIUCSCI340_LIST_H
#define NIUCSCI340_LIST_H

#include "simple_linked_list.decl.h"

#include <iostream>

/**
 * @brief Construct a new simple linked list<T>::simple linked list object setting 
 * "head" to "nullptr", "tail" to "nullptr", and setting the number of elements
 * (n_elements) in the linked list to 0.
 * 
 * @tparam T 
 * @tparam ITERATOR 
 * @param beg 
 * @param end 
 */
template <typename T>
template <typename ITERATOR> //constructor copying the contents of another container
simple_linked_list<T>::simple_linked_list(ITERATOR beg, ITERATOR end) : n_elements(0), head(nullptr), tail(nullptr) {
    for (ITERATOR it = beg; it != end; ++it) {
        push_back(*it);
    }
}

/**
 * @brief Boolean returning true if the linked list is empty and false
 *  if it does contain elements.
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <typename T>
bool simple_linked_list<T>::empty() const {
  if(head == nullptr || n_elements == 0){
    return true;
  }else{
    return false;
  }
}

/**
 * @brief This function returns the beginning of the linked list.
 * 
 * @tparam T 
 * @return simple_linked_iterator<T> 
 */
template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::begin() {
    return simple_linked_iterator<T>(head);
}

/**
 * @brief This function returns the end of the linked list.
 * 
 * @tparam T 
 * @return simple_linked_iterator<T> 
 */
template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::end() {
    return simple_linked_iterator<T>(nullptr);
}

/**
 * @brief This function returns a reference to the data member of the head node.
 * Throws an out_of_range exception if the container is empty.
 * 
 * @tparam T 
 * @return T& 
 */
template <typename T>
T & simple_linked_list<T>::front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

/**
 * @brief This function returns a reference to the data member of the tail node.
 * Throws an out_of_range exception if the container is empty.
 * 
 * @param T
 * @return T& 
 */
template <typename T>
T & simple_linked_list<T>::back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

/**
 * @brief Modifies the container to remove the last node and thows an out_of_range
 * exception if the container is empty.
 * 
 * @tparam T 
 */
template <typename T>
void simple_linked_list<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    if (n_elements == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        linked_node<T> *current = head;
        while (current->next != tail) 
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    n_elements--;
}

/**
 * @brief Adds a new node containing the provided value to the end of the container.
 * 
 * @tparam T 
 * @param x 
 */
template <typename T>
void simple_linked_list<T>::push_back(const T &x) {
    linked_node<T> *new_node = new linked_node<T>(x);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    n_elements++;
}

/**
 * @brief Called when the container goes out of scope and deletes any new objects
 * created.
 * 
 * @tparam T 
 */
template <typename T>
simple_linked_list<T>::~simple_linked_list() {
    clear();
}

/**
 * @brief Returns how many elements are currently in the container.
 * 
 * @tparam T 
 * @return size_t 
 */
template <class T>
size_t simple_linked_list<T>::size() const {
    return n_elements;
}

/**
 * @brief Removes all of the nodes from the container and resets it to an empty
 * state.
 * 
 * @tparam T 
 */
template <typename T>
void simple_linked_list<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

// IMPLEMENTATIONS FOR ITERATOR

/**
 * @brief This returns "true" if and only if both simple_linked_iterators 
 * (*this and the parameter) are pointing to the same node.
 * 
 * @tparam T 
 * @param other 
 * @return true 
 * @return false 
 */
template <typename T>
bool simple_linked_iterator<T>::operator == (const simple_linked_iterator<T> &other) const {
    return pos == other.pos;
}

/**
 * @brief Called when you increment your iterator with ++ before the name, i.e. ++i. 
 * This changes the current iterator so it points to the next node, and returns a 
 * reference to the current iterator, which will be at the new position.
 * 
 * @tparam T 
 * @return simple_linked_iterator <T>& 
 */
template <typename T>
simple_linked_iterator <T> & simple_linked_iterator <T>::operator ++ () { 
    pos = pos->next;
    return *this;
}
  
/**
 * @brief Called when you increment your iterator with ++ after the variable name, i.e. i++. 
 * This also changes the current iterator so it points to the next node, but it returns 
 * another iterator that points to the original node position.
 * 
 * @tparam T 
 * @return simple_linked_iterator <T> 
 */
template <typename T>
simple_linked_iterator <T> simple_linked_iterator<T>::operator ++ (int) { 
    simple_linked_iterator <T> tempContainer = *this;
    ++(*this);
    return tempContainer;
}

/**
 * @brief This should return a reference to the data member of the linked_node that the 
 * current iterator points to. 
 * 
 * @tparam T 
 * @return T& 
 */
template <typename T>
T & simple_linked_iterator<T>::operator * () { 
    if (!pos) {
        throw std::out_of_range("Iterator is out of range");
    }
    else {
      return pos->data;
    }
}

#endif

