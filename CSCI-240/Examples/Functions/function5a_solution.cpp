/*
Design and test a function that will get an integer from the user.

The initial version of the function should take no arguments.

It should return an integer: the value entered by the user
*/
#include <iostream>
#include <iomanip>

using namespace std;

//prototype
int getInt1();

int main()
{
//get a test score
int test_score;

test_score = getInt1();

cout << "The test score is " << test_score << endl;

//get an age
int age;

age = getInt1();

cout << "You are " << age << " years old" << endl;


return 0;
}

//function header and code
int getInt1()
{
int user_val;

cout << "Enter a number (no decimal point): ";
cin >> user_val;

return user_val;
}







