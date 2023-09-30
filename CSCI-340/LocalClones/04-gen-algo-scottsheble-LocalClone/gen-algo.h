#ifndef NIU_CSCI340_GEN_ALGO_IMPL_H
#define NIU_CSCI340_GEN_ALGO_IMPL_H

#include "gen-algo.decl.h"

#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>

template <typename FN>
size_t read_lines(std::istream &instream, FN linecb) {
  // XXX you must implement this function
}

template <typename FN>
size_t split_string_strict(const std::string &instring, FN tokencb, char delim) {
  // XXX you must implement this function
}


template <typename FN>
size_t split_string_greedy(const std::string &instring, FN tokencb, char delim) {
  // XXX you must implement this function
}

template <typename TABLE, typename ARRLIKE>
void print_table(std::ostream & ost, 
                 const TABLE & table, 
                 const ARRLIKE & widths, 
                 unsigned int maxcol, 
                 const std::string &pre, 
                 const std::string &sep,
                 const std::string &post,
                 bool leftalign) 
{
  // XXX you must implement this function
}

// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
int table_min_cols(const STR_TABLE &table) {
  // XXX you must implement this function
}

template <typename STR_TABLE>
std::vector <int> calc_widths(const STR_TABLE & table) {
  // XXX you must implement this function
}

// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
STR_TABLE load_tsv(const std::string & filename) {
  // XXX you must implement this function
}

// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
void table_sort_alpha(STR_TABLE & table, unsigned int col) {
  // XXX you must implement this function
}

// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
void table_sort_numer(STR_TABLE & table, unsigned int col) {
  // XXX you must implement this function
}
#endif
