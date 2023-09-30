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
//while loop solution
int sum2;
int value2;

//initialize the sum of values and the starting value
sum2 = 0;

value2 = 5;  //priming "read"

while( value2 <= 42 )
  {
  sum2 = sum2 + value2;
  
  value2 += 1;   //secondary "read"
  }

cout << "The while sum is " << sum2 << endl;





return 0;
}


