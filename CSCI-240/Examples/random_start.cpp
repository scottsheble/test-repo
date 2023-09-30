/*
Amy B

random numbers
*/

#include <iostream>
#include <iomanip>

#include <cstdlib>   //for random numbers

using namespace std;

int main()
  {
  int random_num;
  
  //setup the random number generator
  srand( 7 );
  
  //generate a random number
  random_num = rand();
  
  cout << "1st random number is " << random_num << endl;
  
  
  
  return 0;
  }

