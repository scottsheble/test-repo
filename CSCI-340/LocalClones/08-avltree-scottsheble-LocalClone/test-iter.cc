/******************************************************************************
 * This file is provided as a part of an NIU CSCI 340 Assignment. IT IS NOT   *
 * TO BE CHANGED. To complete the assignment, please put your code in the     *
 * files detailed in the assignment writeup.     `                            *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/
#include <iostream>
#include <set>
#include <vector>

#include "avl_set.decl.h"
#include "avl_set.h"

using namespace std;

const std::vector <int> input_data{ 1,2,3,4,5,6,7,8,9,10 };
const int N = 5; // how many to print

auto dbgprint = [] (auto x) { 
  cout << "    "
       << "node (" << std::hex << x << ") "
       << "has data " << std::dec << x->data << ", "
       << "left=(" << std::hex << x->left << "), "
       << "right=(" << std::hex << x->right << "), "
       << "parent=(" << std::hex << x->parent << std::dec << ")\n";
};

template <typename CONTAINER, bool TREEDEBUG=false>
void test_container_iterators(const char * label) {
  cout << "  //////////////////////////////////////////////////////////////////////////////\n";
  cout << "  // Testing iterators for " << label << "\n";
  cout << "  //////////////////////////////////////////////////////////////////////////////\n";
  cout << "  Constructing your container with the input data.\n";
  CONTAINER cont(input_data.begin(), input_data.end());

  if constexpr(TREEDEBUG) {
    cout << "  Dumping contents of tree after construction to help you debug issues.\n";
    cout << "  These addresses will obviously be different so don't expect them to\n";
    cout << "  match the reference output.\n";
    cont.preorder(dbgprint);
  }

  cout << "  Calling begin().\n";
  auto first = cont.begin();
  cout << "    test dereference, *begin(); expect: " << input_data.front() << ", got: " << *first << "\n";
  cout << "  Calling end().\n";
  auto last = cont.end(); // end is 1 past last element
  cout << "  Check if the bidi iterator can come back from off the end; i.e. *(--end)\n";
  --last;  // back up to that last element, hopefully
  cout << "    Prefix --x  expect " << input_data.back() << " got " << *last << "\n";
  last = cont.end();
  last--;
  cout << "    Postfix x-- expect " << input_data.back() << " got " << *last << "\n";

  cout << "  Check if the bidi iterator can come back from before beginning, i.e. *(++(--begin))\n";
  cout << "  | this is technically undefined behavior, so std::set is allowed to be \n";
  cout << "  | wrong, but your iterator must support it. )\n";

  first = cont.begin(); --first; ++first; 
  cout << "    --x then ++x expect " << input_data.front() << " got " << *first << "\n";

  first = cont.begin(); --first; first++;
  cout << "    --x then x++ expect " << input_data.front() << " got " << *first << "\n";
  
  first = cont.begin(); first--; ++first;
  cout << "    x-- then ++x expect " << input_data.front() << " got " << *first << "\n";

  first = cont.begin(); first--; first++;
  cout << "    x-- then x++ expect " << input_data.front() << " got " << *first << "\n";
  
  auto it = cont.begin();

  cout << "  Print out first " << N << " values from begin(), prefix increment (not using end)\n";
  cout << "    [ ";
  it = cont.begin();
  for(int i = 0; i < N; ++i) {
    cout << *it << " ";
    ++it;
  }
  cout << "]\n";
  
  cout << "  Print out first " << N << " values from begin(), postfix increment (not using end)\n";
  cout << "    [ ";
  it = cont.begin();
  for(int i = 0; i < N; ++i) {
    cout << *it << " ";
    it++;
  }
  cout << "]\n";
  
  cout << "  Print out whole contents from begin to end, prefix\n";
  cout << "    [ ";
  for(auto x = cont.begin(); x != cont.end(); ++x) {
    cout << *x << " ";
  }
  cout << "]\n";
  
  cout << "  Print out whole contents from begin to end, postfix\n";
  cout << "    [ ";
  for(auto x = cont.begin(); x != cont.end(); x++) {
    cout << *x << " ";
  }
  cout << "]\n";

  cout << "  Calling rbegin()\n";
  auto rfirst = cont.rbegin();
  cout << "    test dereference, *rbegin(); expect: " << input_data.back() << ", got: " << *rfirst << "\n";

  cout << "  Calling rend()\n";
  auto rlast = cont.rend();

  cout << "  Testing iteration from rbegin to rend, prefix ++x on adapter (your --x)\n";
  cout << "    [ ";
  for(auto x = cont.rbegin(); x != rlast; ++x) {
    cout << *x << " "; cout.flush();
  }
  cout << "]\n";
  
  cout << "  Testing iteration from rbegin to rend, postfix x++ on adapter (your x--)\n";
  cout << "    [ ";
  for(auto x = cont.rbegin(); x != rlast; x++) {
    cout << *x << " "; cout.flush();
  }
  cout << "]\n";
  cout << "\n";
}

int main() {

  // test begin and end
  // begin should dereference to first value
  // --end should dereference to the last value
  // confirmed that this is behavior even of std::set and std::list 

  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "// test-iter - Test your avl_set's iterators, avl_iterator  \n"; 
  cout << "//\n";
  cout << "//  This program allows you to test the iterators provided by your container to \n"; 
  cout << "// make sure they behave the same way as other bidirectional iterators. First,  \n"; 
  cout << "// it runs the tests on std::list and std::set so you can see what is expected. \n"; 
  cout << "// Then it runs the same tests on your avl_set.  \n"; 
  cout << "//   \n"; 
  cout << "//   I tried to make smaller tests so you can identify problems in isolation, \n"; 
  cout << "// but I needed to be able to construct the container, so you'll need to  \n"; 
  cout << "// make sure to implement your iterator-range-based constructor first.  \n"; 
  cout << "////////////////////////////////////////////////////////////////////////////////\n";
  cout << "\n";

  test_container_iterators<std::set<int>, false>("std::set bidi iterator");
  test_container_iterators<avl_set<int>, true>("avl_set bidi iterator");
}
