/*
Amy B

random numbers
*/

#include <iostream>
#include <iomanip>

#include <cstdlib>   //for random numbers
#include <ctime>  //to use time(0)

using namespace std;

int main()
  {
  int random_num;
  
  //setup the random number generator
  srand( time(0) );
  
  //generate a random number
  random_num = rand();
  
  cout << "1st random number is " << random_num << endl;
  
  //generate a second random number
  random_num = rand();
  
  cout << "2nd random number is " << random_num << endl;
  
  //loop to generate 5 random numbers
  for(int cnt = 1; cnt <= 5; cnt = cnt + 1 )
    {
    random_num = rand();
    cout << "The random number: " << random_num << endl;
	}
  
  
  
  
  
  return 0;
  }

