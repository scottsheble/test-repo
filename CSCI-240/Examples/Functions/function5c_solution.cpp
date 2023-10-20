/*
Modify the function that gets an integer from the user (again) so that it
takes an additional argument: an integer.

The integer will contain a lowerbound value.

The new version of the function should only get values that are greater
than or equal to the lowerbound value.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int getInt3( string, int );

int main()
{
//test score - lower bound of 0
int test_score;

test_score = getInt3( "Enter a test score", 0 );

cout << "The test score is " << test_score << endl;

//age - lower bound of 15
int age;

age = getInt3( "What is your age", 15);
cout << "you are " << age << " years old" << endl;


return 0;
}


/*
Modify the function that gets an integer from the user (again) so that it
takes an additional argument: an integer.

The integer will contain a lowerbound value.

The new version of the function should only get values that are greater
than or equal to the lowerbound value.
*/

int getInt3( string prompt, int lower_bound )
{
int user_val;

cout << prompt << " (must be greater than " << lower_bound
     << "): ";

cin >> user_val;

//loop - make sure the value fits the requirement
//     - invalid value - user must re-enter

while( user_val < lower_bound )
  {
  cout << "You messed up! Try again: ";
  cin >> user_val;
  }

//only good values are returned
return user_val;
}








