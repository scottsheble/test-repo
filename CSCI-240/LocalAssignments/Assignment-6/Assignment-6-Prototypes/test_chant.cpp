/*
This program tests the NIUchant function
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main()
  {
  //Test 1: display 1 iteration of the chant
  cout << "Test 1: 1 iteration of the chant" << endl;
  NIUchant(1);
  cout << "The display should be:" << endl
       << "Forward! " << endl << endl;


  //Test 2: display 8 iterations of the chant
  cout << endl << "Test 2: 8 iterations of the chant" << endl;
  NIUchant(8);
  cout << "The display should be:" << endl
       << "Forward! Together, Forward! Forward! Together, Forward! Forward! Together, " << endl << endl;


  //Test 3: display 11 iterations of the chant
  cout << endl << "Test 3: 11 iterations of the chant" << endl;
  NIUchant(11);
  cout << "The display should be:" << endl
       << "Forward! Together, Forward! Forward! Together, Forward! Forward!"
       << " Together, Forward! Forward! Together, " << endl << endl;

  //Test 4: display 22 iterations of the chant
  cout << endl << "Test 4: 22 iterations of the chant" << endl;
  NIUchant(22);
  cout << "The display should be:" << endl
       << "Forward! Together, Forward! Forward! Together, Forward! Forward!"
       << " Together, Forward! Forward! Together, Forward! Forward! Together,"
       << " Forward! Forward! Together, Forward! Forward! Together, Forward!"
       << " Forward! " << endl << endl;

  return 0;
  }



