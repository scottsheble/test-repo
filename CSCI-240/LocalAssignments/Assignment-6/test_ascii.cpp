/*
This program is used to test the sumOfASCII function
*/

#include <iostream>
#include <iomanip>

using namespace std;

void displayHelp();

int main()
  {
  int result;
    
  //Test 1 - first 5 uppercase characters
  cout << "Test 1: first 5 uppercase characters (make sure to enter U when prompted)."
       << endl << endl;
  
  result = sumOfASCII(5);

  //Is the result from the function 335?
  //Yes, the function worked
  if( result == 335)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 335." << endl;

    displayHelp();
    }

  //Test 2 - first 5 lowercase characters
  cout << endl
       << "Test 2: first 5 lowercase characters (make sure to enter L when prompted)."
       << endl << endl;

  result = sumOfASCII(5);

  //Is the result from the function 495?
  //Yes, the function worked
  if( result == 495)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 495." << endl;

    displayHelp();
    }

  //Test 3 - all lowercase characters
  cout << endl
       << "Test 3: all lowercase characters (make sure to enter L when prompted)."
       << endl << endl;

  result = sumOfASCII(26);

  //Is the result from the function 2847?
  //Yes, the function worked
  if( result == 2847)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 2847." << endl;

    displayHelp();
    }

  //Test 4 - all uppercase characters
  cout << endl
       << "Test 4: all uppercase characters (make sure to enter U when prompted)."
       << endl << endl;

  result = sumOfASCII(26);

  //Is the result from the function 2015?
  //Yes, the function worked
  if( result == 2015)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 2015." << endl;

    displayHelp();
    }

  return 0;
  }


/*
displayHelp

This function displays information to help determine why incorrect output
might be produced.

Arguments:  None

Returns:  Nothing
*/
void displayHelp()
  {
  cout << "Check to make sure:"<< endl
       << "  - the loop is executing the correct number of times" << endl
       << "  - the variable holding the calculated sum is properly initialized" << endl
       << "  - the sum is being calculated correctly by adding ascii values" << endl
       << "  - the correct case was entered (U or L)" << endl << endl;
}
