/*
This program tests the getValue function
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main()
  {
  int value;

  //get a value between 1 and 10
  value = getValue("Enter a number", 1, 10);

  //Is the returned value valid?
  //Yes
  if(value >= 1 and value <= 10)
    {
    cout << "Test 1: SUCCESS" << endl << endl;
    }
  //No
  else
    {
    cout << "Test 1: FAIL" << endl
         << "The function returned " << value << " which is not between 1 and 10. Make sure" << endl
         << "to use a loop and the passed in arguments to validate the input value." << endl << endl;
    }


  //get a value between 4 and 423
  value = getValue("Enter an integer", 4, 423);

  //Is the returned value valid?
  //Yes
  if(value >= 4 and value <= 423)
    {
    cout << "Test 2: SUCCESS" << endl << endl;
    }
  //No
  else
    {
    cout << "Test 2: FAIL" << endl
         << "The function returned " << value << " which is not between 4 and 423. Make sure" << endl
         << "to use a loop and the passed in arguments to validate the input value." << endl << endl;
    }


  //get a value between -55 and 55
  value = getValue("Enter a temperature", -55, 55);

  //Is the returned value valid?
  //Yes
  if(value >= -55 and value <= 55)
    {
    cout << "Test 3: SUCCESS" << endl << endl;
    }
  //No
  else
    {
    cout << "Test 3: FAIL" << endl
         << "The function returned " << value << " which is not between -55 and 55. Make sure" << endl
         << "to use a loop and the passed in arguments to validate the input value." << endl << endl;
    }


  return 0;
  }

