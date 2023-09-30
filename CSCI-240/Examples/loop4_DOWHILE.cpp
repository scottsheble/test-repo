/*
Loop 4:
Write a loop to add up the numbers between 5 and 42, inclusive.
Display the resulting sum.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
//do while version
int value3;
int sum3;

sum3 = 0;
value3 = 5;

do
  {
  sum3 = sum3 + value3;
  
  value3 += 1;
  }
while( value3 <= 42);

cout << "the do while sum is " << sum3 << endl;




return 0;
}


