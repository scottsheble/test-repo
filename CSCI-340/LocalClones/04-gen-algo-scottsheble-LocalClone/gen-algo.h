/**********************************************************************************************
 * NIU CSCI 340 Section 1                                                                     *
 * Assignment 4                                                                               *
 * Scott Sheble - Z1963374 - scottsheble                                                      *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/
#ifndef NIU_CSCI340_GEN_ALGO_IMPL_H
#define NIU_CSCI340_GEN_ALGO_IMPL_H

#include "gen-algo.decl.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <sstream>

/**
 * @brief This function will use getline on the istream passed in as instream. Every line in the
 * file should be read, until the EOF. For each line read, call the "callback" function, linecb, 
 * and pass the string read to that function.
 * 
 * @tparam FN 
 * @param instream 
 * @param linecb 
 * @return size_t 
 */
template <typename FN>
size_t read_lines(std::istream &instream, FN linecb) {
    std::string line; // string to store lines.
    size_t lineCount = 0;
    while (std::getline(instream, line)) { // read lines from instream, call linecb function, increment lineCount.
        linecb(line);
        ++lineCount;
    }
    return lineCount;
}

/**
 * @brief This function goes through the whole string passed in, splitting it into tokens based 
 * on the delimiter character. This is the strict version, which means that a delimiter always
 * indicates the end of one token and the start of another, even if that means the token is empty.
 * 
 * @tparam FN 
 * @param instring 
 * @param tokencb 
 * @param delim 
 * @return size_t 
 */
template <typename FN>
size_t split_string_strict(const std::string &instring, FN tokencb, char delim) {
    std::istringstream iss(instring); // string stream for instring. 
    std::string token; // string to store tokens.
    size_t tokenCount = 0;
    while (std::getline(iss, token, delim)) { // check for delimiter, call tokencb and increment tokenCount.
        tokencb(token);
        ++tokenCount;
    }
    return tokenCount;
}

/**
 * @brief This function goes through the whole string passed in, splitting it into tokens based 
 * on the delimiter character. This is the greedy version, which means:
 * There is no such thing as an empty token unless the whole string was empty.
 * Any delimiters that occur before the first token should be ignored, not included in the token
 * When there are several delimiters in a row, the first one splits the token, and the rest are
 * ignored until a non-delimiter character begins the next token.
 * 
 * @tparam FN 
 * @param instring 
 * @param tokencb 
 * @param delim 
 * @return size_t 
 */
template <typename FN>
size_t split_string_greedy(const std::string &instring, FN tokencb, char delim) {
    std::string token; // string to store tokens.
    size_t tokenCount = 0;
    // check for delimiter, else call tokencb for string/token detected. 
    for (char c : instring) {
        if (c != delim) {
            token += c;
        } else {
            if (!token.empty()) { // check for empty token. calls for tokencb and then clears the token for the next token.
                tokencb(token);
                ++tokenCount;
            }
            token.clear();
        }
    }
    if (!token.empty()) { // check last token. if not empty, calls tokencb and increments tokenCount.
        tokencb(token);
        ++tokenCount;
    }
    return tokenCount;
}

/**
 * @brief This function is responsible for printing out your table in a tidy format.
 * 
 * @tparam TABLE 
 * @tparam ARRLIKE 
 * @param ost 
 * @param table 
 * @param widths 
 * @param maxcol 
 * @param pre 
 * @param sep 
 * @param post 
 * @param leftalign 
 */
template <typename TABLE, typename ARRLIKE>
void print_table(std::ostream & ost, 
                 const TABLE & table, 
                 const ARRLIKE & widths, 
                 unsigned int maxcol, 
                 const std::string &pre, 
                 const std::string &sep,
                 const std::string &post,
                 bool leftalign) 
  // {
    

  //   for (size_t i = 0; i < table.size(); i++) {
  //     ost << pre;
  //     unsigned int count = 0;
  //     for (size_t j = 0; j < table[i].size(); j++) {
  //       if (count >= maxcol){
  //         break;

  //       }
  //       if (leftalign) {
  //         ost << std::left;
  //       }

  //       ost << std::setw(widths[count]) << table[i][j] << sep;
  //       count++;

  //     }
  //     ost << post << std::endl;
  //   }

  // }
{
    // iterate through each row in table
    for (const auto &row : table) {  
        ost << pre; // prefix.
        for (unsigned int i = 0; i < maxcol; ++i) {
            if (i < row.size()) { // check for current column in the row.
                ost << std::setw(widths[i]); // column width.
                if (leftalign) { // aligns left.
                    ost << std::left;
                }
                ost << row[i]; // print current index.
                if (i < row.size() - 1) {  // check for last element in current row.
                    ost << sep; // separator. 
                }
            } else {
                ost << std::setw(widths[i]) << ""; // empty index if no column. 
                if (i < maxcol - 1) {  // check for last element in the table.
                    ost << sep; // separator.
                }
            }
        }
        ost << post << "\n"; // postfix and new line.
    }
}

/**
 * @brief This function looks at each of the rows in the table provided, and returns the width 
 * of the shortest row present.
 * 
 * @param table 
 * @return int 
 */
// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
int table_min_cols(const STR_TABLE &table) {
    int minCols = std::numeric_limits<int>::max(); // maximum integer value.
    for (const auto &row : table) {
        minCols = std::min(minCols, static_cast<int>(row.size())); // minimum value and current row size.
    }
    return minCols;
}
    
/**
 * @brief This function returns a vector of integers. Each integer in the vector will contain 
 * the width (in characters) of the longest string in the corresponding column of the STR_TABLE
 * passed in, table.
 * 
 * @tparam STR_TABLE 
 * @param table 
 * @return std::vector <int> 
 */
template <typename STR_TABLE>
std::vector <int> calc_widths(const STR_TABLE & table) { // calculate column widths for table.
    int maxCols = table_min_cols(table); // max number of columns for table.
    std::vector<int> widths(maxCols, 0); // intialize vector to store width values.

    for (const auto &row : table) { // find maximum columns or size of current row. 
        for (int i = 0; i < maxCols && i < static_cast<int>(row.size()); ++i) {
            widths[i] = std::max(widths[i], static_cast<int>(row[i].length()));
        }
    }
    return widths;
}

/**
 * @brief This function is responsible for loading a table from the file given, which must be 
 * a tab-separated values file. This data will be returned as a STR_TABLE.
 * 
 * @param filename 
 * @return STR_TABLE 
 */
// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
STR_TABLE load_tsv(const std::string & filename) {
    STR_TABLE table; // table to store tsv file. 
    std::ifstream infile(filename);
    std::string line; // string to store each line. 
    while (std::getline(infile, line)) {
        std::vector<std::string> row; // vector to store elements. 
        split_string_greedy(line, [&row](const std::string &token) { // split line into tokens using tab delimiter.
            row.push_back(token);
        }, '\t');
        table.push_back(row); // push back row to table. 
    }
    infile.close(); // close input stream.
    return table;
}

/**
 * @brief Using the version of the std::sort algorithm that allows you to pass a custom 
 * comparator, order the rows in the table so that column number col is sorted in ascending 
 * order, alphabetically. The reference output used a case sensitive comparator.
 * 
 * @param table 
 * @param col 
 */
// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
void table_sort_alpha(STR_TABLE & table, unsigned int col) { // std::sort function used to sort specific column. compares indexes at two rows for sorting based on alphanumeric sorting. 
    std::sort(table.begin(), table.end(), [col](const std::vector<std::string> &a, const std::vector<std::string> &b) {
        return a[col] < b[col];
    });
}

/**
 * @brief Using the version of the std::sort algorithm that allows you to pass a custom 
 * comparator, order the rows in the table so that column number col is sorted in ascending 
 * order, numerically. This order will be different than the alphabetical sort for numbers of
 * differing lengths. To convert a string value to a double, you can use the function strtod.
 * 
 * @param table 
 * @param col 
 */
// NOTE: This is not a template, and typically you should not put non-templated
// function definitions in header files. I'm leaving it anyway to keep things
// simpler for the assignment, but it could cause problem if multiple files
// were separately compiled after including this header. This is not happening
// for this assignment.
void table_sort_numer(STR_TABLE & table, unsigned int col) { // use std::sort on the column for numerical sorting.
      std::sort(table.begin(), table.end(), [col](const std::vector<std::string> &a, const std::vector<std::string> &b) {
        double numA, numB;
        char* endptrA; // character pointers for use in strtod function.
        char* endptrB; // character pointers for use in strtod function.
        numA = std::strtod(a[col].c_str(), &endptrA); // string to double conversion using strtod.
        numB = std::strtod(b[col].c_str(), &endptrB); // string to double conversion using strtod.

        return numA < numB; // comparison between numerical values for numerical sorting. 
    });
}
#endif
