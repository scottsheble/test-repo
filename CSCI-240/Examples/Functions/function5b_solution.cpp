/*
Modify the function that gets an integer from the user so that it
takes a single argument: a string.

The string will contain a prompt that should be displayed to the
user. It tells the user what type of information should be entered.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int getInt2( string );

int main()
{
//test score
int test_score;

test_score = getInt2( "Enter a test score: " );

cout << "The test score is " << test_score << endl;

//age
int age;

age = getInt2( "How old are you? " );

cout << "You are " << age << " years old" << endl;


return 0;
}


/*
Modify the function that gets an integer from the user so that it
takes a single argument: a string.

The string will contain a prompt that should be displayed to the
user. It tells the user what type of information should be entered.
*/

int getInt2( string prompt )
{
int user_val;

cout << prompt;
cin >> user_val;

return user_val;
}





