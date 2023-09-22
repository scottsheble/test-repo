/******************************************************************************
 * This file is provided as a part of NIU CSCI 340 Assignment 2. IT IS NOT TO *
 * BE CHANGED. To complete the assignment, please implement the methods that  *
 * are declared here in the file `340list.h`                                  *
 *                                                                            *
 * CHANGES TO THIS FILE WILL RESULT IN A LARGE GRADE PENALTY.                 *
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

#include <cstdlib> // for srand, rand
#include <cmath>   // for log10

#include "simple_linked_list.h"
#include "assign2-algos.h"

const int default_rand_N = 15;
const int default_rand_seed = 1;
const int default_rand_min = 0;
const int default_rand_max = 99;

template <class CONTAINER>
int test_container(std::string label, size_t N=40, int rngseed=1, int rngmin=1, int rngmax=100);



int main(int argc, char *argv[]) {

  // usage notes:
  //   argv[1] is number of random numbers, if present, otherwise default used
  //   argv[2] is random number seed, if present, otherwise default used
  //   argv[3] is random number minimum value, if present, otherwise default used
  //   argv[4] is random number maximum value, if present, otherwise default used
  
  // initialize these to their defaults
  int rand_N    = default_rand_N;
  int rand_seed = default_rand_seed; 
  int rand_min  = default_rand_min;
  int rand_max  = default_rand_max;

  // change the parameters provided, leave the ones that aren't alone
  if(argc > 4) {
    rand_max = atoi(argv[4]); }
  if(argc > 3) {
    rand_min = atoi(argv[3]); }
  if(argc > 2) {
    rand_seed = atoi(argv[2]); }
  if(argc > 1) { 
    rand_N = atoi(argv[1]); }

  // Run the same test with different containers
  test_container<std::vector<int>>       ("std::vector", rand_N, rand_seed, rand_min, rand_max);  
  test_container<std::list<int>>         ("std::list",   rand_N, rand_seed, rand_min, rand_max);  
  test_container<simple_linked_list<int>>("simple_linked_list",  rand_N, rand_seed, rand_min, rand_max);  

  // Need something to copy to test our iterator range constructor
  const std::string v = "Computers are good at following instructions, but not at reading your mind."; 
  
  std::cout << "  Further testing with the container you implemented:\n"; 

  simple_linked_list <char> l0; // empty
  simple_linked_list <char> l1(v.begin(), v.end()); // from list
						   //
  std::cout << "    l0 is default constructed, should show as empty:   " << (l0.empty() ? std::string("empty (good)") : std::string("NOT EMPTY (BAD)") ) << std::endl;
  std::cout << "    l1 is constructed from v, and should not be empty: " << (l1.empty() ? std::string("EMPTY (BAD)") : std::string("not empty (good)") ) << std::endl;

  if(!l1.empty()) {
    std::cout << "    Testing your front and back methods:\n";
    std::cout.flush(); 

    std::cout << "      l1.front() is: '" << l1.front() << "'\n";
    std::cout << "      l1.back() is:  '" << l1.back() << "'\n";
  }
  else {
    std::cout << "    ERROR: Skipping testing of front and back methods because the container is empty (It should not be.)\n";
  }
  std::cout << "    input:     ";
  print_range(std::cout, v.begin(), v.end(), "[", "|", "]\n", 1);
  std::cout << "    your list: ";
  print_range(std::cout, l1.begin(), l1.end(), "[", "|", "]\n", 1);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Runs test on the container type indicated by the template parameter        //
////////////////////////////////////////////////////////////////////////////////
template <class CONTAINER>
int test_container(std::string label, size_t N, int rngseed, int rngmin, int rngmax) {
  std::cout << "RUNNING TESTS FOR \"" << label << "\":\n";

  // find out how many characters largest number takes up
  int width = log10(rngmax)+1;

  // initialize pseudorandom number generator - same seed guarantees same sequence
  srand(rngseed); 

  // construct an instance of the container class we're testing
  CONTAINER container;

  // use push_back to add N random numbers to the end of the container, one at a time
  int r;
  for(size_t i = 0; i < N; ++i) {
    r = rand() % (rngmax-rngmin+1) + rngmin;
    container.push_back(r);
  }

  std::cout << "  added " << N << " elements, size()=" << container.size() << ", range_count=" << range_count(container.begin(), container.end()) << "\n";
  // print initial contents after populating with the random numbers
  std::cout << "  ";
  print_range(std::cout, container.begin(), container.end(), "[ ", ", ", " ]\n", 0); 

  std::cout << "  sum=" << range_sum(container.begin(), container.end()) << std::endl;
  std::cout << "  mean=" << range_avg(container.begin(), container.end()) << std::endl;

  // calculate and print the histogram data
  std::vector<int> bins(10); // need random access
  histogram(container.begin(), container.end(), bins, 10, 10); 

  std::cout << "  histogram counts: ";
  print_range(std::cout, bins.begin(), bins.end(), "/ ", " / ", " /\n", 3); 


  // pop elements off the back one at a time and output data 
  for(size_t i = 0; i<N-1 && !container.empty(); ++i) {
    container.pop_back();
    if(i < 4 || N-i-1 <=4) { std::cout << "  "; }
    if(i < 4) std::cout << " (after popping " << i+1 << ")";
    if(N-i-1 <= 4) std::cout << " (with " << (N-i-1) << " left to pop)"; 
    if(i < 4 || N-i-1 <=4) {
      std::cout << " size() is " << container.size();
      print_range(std::cout, container.begin(), container.end(), ": (", "|", ")\n", width); 
    }
  }

  std::cout << '\n';
  std::cout.flush(); // make sure everything is printed before continuing
  return 0;
}


