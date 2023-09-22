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

//#warning The provided version of simple_linked_list.h does not actually implement things. 


template <typename T>
template <typename ITERATOR> //constructor copying the contents of another container
simple_linked_list<T>::simple_linked_list(ITERATOR beg, ITERATOR end) : n_elements(0), head(nullptr), tail(nullptr) {
    for (ITERATOR it = beg; it != end; ++it) {
        push_back(*it);
    }
}

template <typename T>
bool simple_linked_list<T>::empty() const {
  if(head == nullptr || n_elements == 0){
    return true;
  }else{
    return false;
  }
}


template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::begin() {
    return simple_linked_iterator<T>(head);
}

template <typename T>
simple_linked_iterator<T> simple_linked_list<T>::end() {
    return simple_linked_iterator<T>(nullptr);
}

template <typename T>
T & simple_linked_list<T>::front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}
    
template <typename T>
T & simple_linked_list<T>::back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

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
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    n_elements--;
}

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

template <typename T>
simple_linked_list<T>::~simple_linked_list() {
    clear();
}

template <class T>
size_t simple_linked_list<T>::size() const {
    return n_elements;
}

template <typename T>
void simple_linked_list<T>::clear() {
    while (!empty()) {
        pop_back();
    }
}

// IMPLEMENTATIONS FOR ITERATOR

template <typename T>
bool simple_linked_iterator<T>::operator == (const simple_linked_iterator<T> &other) const {
    return pos == other.pos;
}

template <typename T>

//preincrement
simple_linked_iterator <T> & simple_linked_iterator <T>::operator ++ () { 
    pos = pos->next;

    return *this;
}
  
//postincrement
template <typename T>
simple_linked_iterator <T> simple_linked_iterator<T>::operator ++ (int) { 
    simple_linked_iterator <T> temp = *this;
    ++(*this);
    return temp;
}
    
template <typename T>
T & simple_linked_iterator<T>::operator * () { // dereference operator
    if (!pos) {
        throw std::out_of_range("Iterator is out of range");
    }
    else {
      return pos->data;
    }
    
}

#endif

