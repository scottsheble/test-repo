/*
Modify the function that gets an integer from the user (yet again) so that it
takes an additional argument: an integer.

The new integer will contain an upperbound value.

The new version of the function should only get values that are greater
than or equal to the lowerbound value AND less than or equal to the
upperbound value.
*/
#include <iostream>
#include <iomanip>

using namespace std;

//prototype
int getInt4( string, int, int );


int main()
{
//temps: -50 ... 50
int temperature;

temperature = getInt4( "Enter a temperature", -50, 50 );
cout << "The temperature is " << temperature << endl;

//age: 1 ... 100 
int age;
age = getInt4( "How old are you", 1, 100 );

cout << "Your age is " << age << endl;


return 0;
} 


/*
Modify the function that gets an integer from the user (yet again) so that it
takes an additional argument: an integer.

The new integer will contain an upperbound value.

The new version of the function should only get values that are greater
than or equal to the lowerbound value AND less than or equal to the
upperbound value.
*/
int getInt4( string prompt, int lower_bound, int upper_bound )
{
//declare variable
int user_value;

//get a value
cout << prompt << " (" << lower_bound << " - " << upper_bound
     << "): ";
cin >> user_value;

//check the value (loop)
//find invalid numbers - not between two boundaries
while( user_value < lower_bound or user_value > upper_bound )
  {
  cout << "You messed up! Try again: ";
  cin >> user_value;
  }

//return the value
return user_value;
return user_value - 5;	
}



