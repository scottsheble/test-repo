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

// Implement your algorithms for assignment 2 in this file.

template <typename ITERATOR>
int range_sum(ITERATOR begin, ITERATOR end) {
    int sum = 0;
    for (auto it = begin; it != end; it++)
        sum += *it;
    return sum;
}

template <typename ITERATOR>
    double range_avg(ITERATOR begin, ITERATOR end) {
    double sum = 0;
    double avg = 0;
    int range = 0;
    for (auto it = begin; it != end; it++)
            range += 1;
        
    for (auto it = begin; it != end; it++)
        sum += *it;
        
    avg = sum / range;
    
    return avg;
    
}

template <typename ITERATOR>
auto range_maxval(ITERATOR begin, ITERATOR end) {
    double maxval = 0;
    for (auto it = begin; it != end; it++)
        if (maxval < *it)
            maxval = *it;

    return maxval;
    

}

template <typename ITERATOR>
auto range_minval(ITERATOR begin, ITERATOR end) {
    double minval = 0;
    for (auto it = begin; it != end; it++)
        if (minval > *it)
            minval = *it;

    return minval;
}

template <typename ITERATOR>
int range_count(ITERATOR begin, ITERATOR end) {
    int range = 0;
    for (auto it = begin; it != end; it++)
        range += 1;
    
    return range;
  
}

template <typename ITERATOR>
void print_range(std::ostream & ost, ITERATOR begin, ITERATOR end, const std::string &pre, const std::string &sep, const std::string &post, int width) {
    std::setw(width);
    ost << pre;
    for (auto it = begin; it != end; it++)
        if (it == begin){
            ost << std::setw(width) << *it;
        } else {
            ost << std::setw(width) << sep << *it;
        }
    ost << post;
}


template<typename ITERATOR, typename RANDOM_ACCESS>
void histogram(ITERATOR begin, ITERATOR end, RANDOM_ACCESS & nums, int N, int divisor) {
    nums.assign(N, 0);

    //double bin_range = 1.0 * divisor / N;
    //static_cast<int>(

    for (ITERATOR it = begin; it != end; ++it) {
        int bin_index = (*it / divisor);

        if (bin_index >= 0 && bin_index < N) {
            nums[bin_index]++;
        }
    }
}



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
