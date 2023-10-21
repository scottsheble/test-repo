/*
This program tests the Menu function
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main()
  {
  int response = Menu();

  //Is the value returned from Menu invalid?
  //Yes
  if(response < 1 or response > 5)
    {
    cout << "FAIL" << endl
         << "The function should not return a value less than 1 or" << endl
         << "greater than 5." << endl << endl
		 << "Check to make sure:" << endl
		 << "   - that you have a loop that will validate the value" << endl
         << "   - that the condition on the loop uses the correct compound condition" << endl;
    }
  //No
  else
    {
    cout << "SUCCESS" << endl;
    }

  return 0;
  }


