/*
if Problem 2
Write a chunk of code that will test if the value in an integer
variable called num is a multiple of 11. If it is a multiple, display
"Multiple of 11". Otherwise, display "NOT a multiple of 11".
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int num;

//get a number from the user
cout << "Enter an integer: ";
cin >> num;

//if num is multiple of 11, display "multiple" message
//otherwise, display "not multiple" message

if( num % 11 == 0 )
  {
  cout << num << " is a multiple of 11" << endl;
  }
else
  {
  cout << num << " is NOT a multiple of 11" << endl;
  }   

cout << "After the decision statement" << endl;

return 0;
}


