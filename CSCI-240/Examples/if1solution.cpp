/*
if Problem 1
Write a chunk of code that will test if the value in a character
variable called code is equal to 'G'. If code does contain 'G', display
"Grape Ape". Otherwise, do nothing.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
char code;

//get a character from the user
cout << "Enter a single character: ";
cin >> code;

//if code is G, display Grape Ape
if( code == 'G' )
  {
  cout << "Grape Ape" << endl;
  }

cout << "After the decision statement" << endl;

return 0;
}


