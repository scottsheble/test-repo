/*
This program test the sumOfSquares function
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main()
  {
  int result;

  //What is the sum of the squares when the limit is 6?
  cout << "Test 1: sumOfSquares with limit of 6" << endl;

  //calculate the sum of the squares of the first 6 integers
  result = sumOfSquares(6);

  //Is the result 91?
  //Yes, the function worked
  if( result == 91)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function failed
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 91." << endl << endl
         << "Check to make sure:"<< endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the variable holding the calculated sum is properly initialized" << endl
         << "  - the sum is being calculated correctly by adding squares" << endl << endl;
    }

  //What is the sum of the squares when the limit is 13?
  cout << "Test 2: sumOfSquares with limit of 13" << endl;

  //calculate the sum of the squares of the first 13 integers
  result = sumOfSquares(13);

  //Is the result 819?
  //Yes, the function worked
  if( result == 819)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function failed
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 819." << endl << endl
         << "Check to make sure:"<< endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the variable holding the calculated sum is properly initialized" << endl
         << "  - the sum is being calculated correctly by adding squares" << endl << endl;
    }


  //What is the sum of the squares when the limit is 1?
  cout << "Test 3: sumOfSquares with limit of 1" << endl;

  //calculate the sum of the squares of the first integer
  result = sumOfSquares(1);

  //Is the result 1?
  //Yes, the function worked
  if( result == 1)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function failed
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 1." << endl << endl
         << "Check to make sure:"<< endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the variable holding the calculated sum is properly initialized" << endl
         << "  - the sum is being calculated correctly by adding squares" << endl << endl;
    }


  //What is the sum of the squares when the limit is 22?
  cout << "Test 4: sumOfSquares with limit of 22" << endl;

  //calculate the sum of the squares of the first 22 integers
  result = sumOfSquares(22);

  //Is the result 3795?
  //Yes, the function worked
  if( result == 3795)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function failed
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 3795." << endl << endl
         << "Check to make sure:"<< endl
         << "  - the loop is executing the correct number of times" << endl
         << "  - the variable holding the calculated sum is properly initialized" << endl
         << "  - the sum is being calculated correctly by adding squares" << endl << endl;
    }

  return 0;
  }

