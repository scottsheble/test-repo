/*
This program tests the averageOfCubes function
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main()
  {
  double result;
    
  //set up display - 3 digits after the decimal point
  cout << fixed << setprecision(3);

  //Test 1: what is the average of cubes with the limit 4
  cout << "Test 1: averageOfCubes with a limit of 4" << endl;

  result = averageOfCubes(4);
  
  //Is the result 9.0?
  //Yes
  if( result == 9.0 )
    {
    cout << "SUCCESS" << endl;
	}
  //No, the function did not work
  else
    {
    cout << "The function returned " << result << ". It should have returned 9.000." << endl << endl
         << "Check to make sure:" << endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the average is being calculated correctly" << endl
         << "  - the variable holding the sum is properly initialized" << endl << endl;
	}


  //Test 2: what is the average of cubes with the limit 14
  cout << endl << "Test 2: averageOfCubes with a limit of 14" << endl;

  result = averageOfCubes(14);
  
  //Is the result 591.5?
  //Yes
  if( result == 591.5 )
    {
    cout << "SUCCESS" << endl;
	}
  //No, the function did not work
  else
    {
    cout << "The function returned " << result << ". It should have returned 591.500." << endl << endl
         << "Check to make sure:" << endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the average is being calculated correctly" << endl
         << "  - the variable holding the sum is properly initialized" << endl << endl;
	}


  //Test 3: what is the average of cubes with the limit 31
  cout << endl << "Test 3: averageOfCubes with a limit of 31" << endl;

  result = averageOfCubes(31);
  
  //Is the result 6975.0?
  //Yes
  if( result == 6975.0 )
    {
    cout << "SUCCESS" << endl;
	}
  //No, the function did not work
  else
    {
    cout << "The function returned " << result << ". It should have returned 6975.000." << endl << endl
         << "Check to make sure:" << endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the average is being calculated correctly" << endl
         << "  - the variable holding the sum is properly initialized" << endl << endl;
	}
    
  return 0;
  }


