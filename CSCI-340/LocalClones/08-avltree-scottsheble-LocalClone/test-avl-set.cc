/******************************************************************************
 * This file is provided as a part of an NIU CSCI 340 Assignment. IT IS NOT   *
 * TO BE CHANGED. To complete the assignment, please put your code in the     *
 * files detailed in the assignment writeup.     `                            *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <set>

#include "avl_set.decl.h"
#include "avl_set.h"

#include "testing.h"

template <typename CONTAINER, bool TREEDEBUG=false>
void test_set(const char * label, 
              const std::vector <int> &input, 
              const std::vector <int> &search,
              const std::vector <int> &remove) {
  using std::cout;
  CONTAINER cont;
  int i;

  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// Testing " << label << "\n";
  cout << "////////////////////////////////////////////////////////////////////////////////\n";

  cout << "Testing insert() for [ ";
  for(auto x : input) {
    cout << x << " ";
  }
  cout << "]\n";

  i = 0; // reset counter
  for(auto x : input) {
  if(i % 3 == 0) {
    if(i != 0) { cout << "\n"; }
      cout << "  ";
    }
    cout << "Insert " << x << ": ";
    auto ins_res = cont.insert(x);
    if(ins_res.second) { // insert succeeded
      cout << "success(" << *(ins_res.first) << ")\t";
    }
    else { 
      cout << "failure\t";
    }
    ++i;
  }
  cout << "\n";

  if constexpr(TREEDEBUG) {
    cout << "Showing avl_set tree info after insertion:\n";
    print_tree_stats_set<typename CONTAINER::value_type>(cont);
  }

  cout << "After insertion, " << cont.size() << " nodes. Iterating to print: [ ";
  { 
    auto end = cont.end();
    for(auto it = cont.begin(); it != end ; ++it) {
      cout << *it << " ";
    }
  }
  cout << "]\n\n";

  cout << "Testing count() for [ ";
  for(auto x: search) {
    cout << x << " ";
  }
  cout << " ]\n";

  // print the results of count for each item
  cout << "  ";
  for(auto x: search) {
    cout << "(" << x << "? ";
    cout << cont.count(x);
    cout <<") ";
  }
  cout << "\n";

  cout << "Testing erase() for [ ";
  for(auto x: remove) {
    cout << x << " ";
  }
  cout << " ]\n"; 

  cout << "  ";
  for(auto x: remove) {
    cout << "(" << x << "? " << cont.erase(x) << ") ";
  }
  cout << "\n";
  
  if constexpr(TREEDEBUG) {
    cout << "Showing avl_set tree info after erasure:\n";
    print_tree_stats_set<typename CONTAINER::value_type>(cont);
  }
  
  cout << "After erasure, " << cont.size() << " nodes. Iterating to print: [ ";
  { 
    auto end = cont.end();
    for(auto it = cont.begin(); it != end ; ++it) {
      cout << *it << " ";
    }
  }
  cout << "]\n\n";
}

int main() {
  using std::cout;
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// test-avl-set - tests your avl_set methods, comparing behavior to std::set \n";
  cout << "//    \n";
  cout << "//   Except for the extra tree debug info that will print for your avl_set, \n";
  cout << "// the output from doing these steps with avl_set should match what you get \n";
  cout << "// using std::set\n";
  std::vector <int> data{3, 2, 1, 9, 5, 6, 7, 8, 4, 1};
  std::vector <int> search{1, 2, 3, 4, 5, 6, 7, 8, 9, 42};
  std::vector <int> remove{2, 4, 6, 8, 4, 30};
  test_set<std::set<int>, false>("std::set", data, search, remove);
  test_set<avl_set<int>, true>("avl_set", data, search, remove);
}
