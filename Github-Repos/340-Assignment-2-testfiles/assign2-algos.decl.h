/******************************************************************************
 * This file is provided as a part of NIU CSCI 340 Assignment 2. IT IS NOT TO *
 * BE CHANGED. To complete the assignment, please implement the methods that  *
 * are declared here in the file `340list.h`                                  *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#ifndef NIUCSCI340ASSIGN2_ALGOS_DECL_H
#define NIUCSCI340ASSIGN2_ALGOS_DECL_H

#include <string>

template <typename ITERATOR>
int    range_sum(ITERATOR begin, ITERATOR end);

template <typename ITERATOR>
double range_avg(ITERATOR begin, ITERATOR end);

template <typename ITERATOR>
auto range_maxval(ITERATOR begin, ITERATOR end);

template <typename ITERATOR>
auto range_minval(ITERATOR begin, ITERATOR end);

template <typename ITERATOR>
int range_count(ITERATOR begin, ITERATOR end);

template <typename ITERATOR>
void   print_range(std::ostream & ost, ITERATOR begin, ITERATOR end, const std::string &pre, const std::string &sep, const std::string &post, int width=0);

template<typename ITERATOR, typename RANDOM_ACCESS>
void   histogram(ITERATOR begin, ITERATOR end, RANDOM_ACCESS & nums, int N=10, int divisor=10);


// structure to hold info used by the tokenizer -- these will be used in a templated context, so a tokenization algo that
// requires more info can extend it
template <typename ITERATOR>
struct iter_token_info {
  ITERATOR b; // iterator at the start of the current token range
  ITERATOR e; // iterator just past the end of the current token
  ITERATOR n; // iterator indicating the beginning of the next token

  // these allow the struct to be used in range-based functions like another container would
  ITERATOR begin() { return b; }
  ITERATOR end()   { return e; }
};

template <typename ITERATOR, typename T>
iter_token_info<ITERATOR> get_next_token_strict(ITERATOR begin,
                                                ITERATOR end, 
                                                T delim);

template <typename ITERATOR, typename T>
iter_token_info<ITERATOR> get_next_token_greedy(ITERATOR begin, 
                                                ITERATOR end, 
                                                T delim);


#endif /* NIUCSCI340ASSIGN2_ALGOS_DECL_H */
