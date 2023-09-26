/**********************************************************************************************
 * NIU CSCI 340 Section YOUR_SECTION                                                          *
 * Assignment 2                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIUCSCI340ASSIGN2_ALGOS_H
#define NIUCSCI340ASSIGN2_ALGOS_H


#include <iomanip>
#include <iostream>
#include <string>
#include "assign2-algos.decl.h"


/**
 * @brief Iterates through container and dereferences the iterator
 * and stores the contents into the variable "sum", which it returns.
 * 
 * @tparam ITERATOR 
 * @param begin 
 * @param end 
 * @return int 
 */
template <typename ITERATOR>
int range_sum(ITERATOR begin, ITERATOR end) {
    int sum = 0;
    for (auto it = begin; it != end; it++) {
        sum += *it;
    }      
    return sum;
}

/**
 * @brief Iterates through container and counts the range of the number
 * of elements before diving it by the sum to store the range into a
 * variable "range", before diving it by the sum to store in the 
 * variable "avg", which it returns.
 * 
 * @tparam ITERATOR 
 * @param begin 
 * @param end 
 * @return double 
 */
template <typename ITERATOR>
    double range_avg(ITERATOR begin, ITERATOR end) {
    double sum = 0;
    double avg = 0;
    int range = 0;
    for (auto it = begin; it != end; it++) {
        range += 1
    }    
    for (auto it = begin; it != end; it++)
        sum += *it;
    avg = sum / range;

    return avg;
    
}

/**
 * @brief Iterates through container to find and compare the current value against
 * the current max value, and returns the maximum value in the variable "maxval".
 * 
 * @tparam ITERATOR 
 * @param begin 
 * @param end 
 * @return auto 
 */
template <typename ITERATOR>
auto range_maxval(ITERATOR begin, ITERATOR end) {
    double maxval = 0;
    for (auto it = begin; it != end; it++)
        if (maxval < *it)
            maxval = *it;

    return maxval;
    

}

/**
 * @brief Iterates through container to find and compare the current value against
 * the current min value, and returns the minimum value in the variable "minval".
 * 
 * @tparam ITERATOR 
 * @param begin 
 * @param end 
 * @return auto 
 */
template <typename ITERATOR>
auto range_minval(ITERATOR begin, ITERATOR end) {
    double minval = 0;
    for (auto it = begin; it != end; it++)
        if (minval > *it)
            minval = *it;

    return minval;
}

/**
 * @brief Iterates through container to find the amount of elements in the range
 * and returns and stores the value in the variable "range".
 * 
 * @tparam ITERATOR 
 * @param begin 
 * @param end 
 * @return int 
 */
template <typename ITERATOR>
int range_count(ITERATOR begin, ITERATOR end) {
    int range = 0;
    for (auto it = begin; it != end; it++)
        range += 1;
    
    return range;
  
}

/**
 * @brief Iterates through container and dereferences the container to
 * ostringstream while checking for trailing comma logic. Prints the
 * prefix and postfix depending on the position in the container. 
 * 
 * @tparam ITERATOR 
 * @param ost 
 * @param begin 
 * @param end 
 * @param pre 
 * @param sep 
 * @param post 
 * @param width 
 */
template <typename ITERATOR>
void print_range(std::ostream & ost, ITERATOR begin, ITERATOR end, const std::string &pre, const std::string &sep, const std::string &post, int width) {
    ost << pre;
    for (auto it = begin; it != end; it++)
        if (it != begin){
            ost << sep << *it;
        } else {
            ost << *it;
        }
    ost << post;
}

/**
 * @brief Iterates through container and derefernces the iterator to
 * the variable "bin_index" and then checks logic to increment
 * "nums[bin_index]".
 * 
 * @tparam ITERATOR 
 * @tparam RANDOM_ACCESS 
 * @param begin 
 * @param end 
 * @param nums 
 * @param N 
 * @param divisor 
 */
template<typename ITERATOR, typename RANDOM_ACCESS>
void histogram(ITERATOR begin, ITERATOR end, RANDOM_ACCESS & nums, int N, int divisor) {
    nums.assign(N, 0);

    for (ITERATOR it = begin; it != end; ++it) {
        int bin_index = (*it / divisor);

        if (bin_index >= 0 && bin_index < N) {
            nums[bin_index]++;
        }
    }
}

/**
 * @brief Get the next token strict object.
 * 
 * @tparam ITERATOR 
 * @tparam T 
 * @param begin 
 * @param end 
 * @param delim 
 * @return iter_token_info<ITERATOR> 
 */
template <typename ITERATOR, typename T>
iter_token_info<ITERATOR> get_next_token_strict(ITERATOR begin, ITERATOR end, T delim) {
    iter_token_info<ITERATOR> token;
    token.b = begin;
    token.e = end;
    
    for (auto i = token.b; i != token.e; ++i) {
        if (*i == delim) {
            token.e = i;
            token.n = i + 1;
            return token;
        }
    }

    token.n = token.e;
    
    return token;
}

/**
 * @brief Get the next token greedy object.
 * 
 * @tparam ITERATOR 
 * @tparam T 
 * @param begin 
 * @param end 
 * @param delim 
 * @return iter_token_info<ITERATOR> 
 */
template <typename ITERATOR, typename T>
iter_token_info<ITERATOR> get_next_token_greedy(ITERATOR begin, ITERATOR end, T delim) {
    iter_token_info<ITERATOR> token;
    token.b = begin;
    token.e = begin;

    while ((token.e != end) && (*token.e != delim)) {
        ++token.e;
    }

    if (token.e != end) {
        token.n = token.e + 1;
    } else {

        token.n = token.e;
    }

    return token;
}



#endif /*NIUCSCI340ASSIGN2_ALGOS_H*/
