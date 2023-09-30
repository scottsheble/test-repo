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
//declare variables
int sum;
int value;

//initialize variables
sum = 0;

//for loop - execute from 5 through 42, one value at a time
for(value = 5; value <= 42; value += 1)
  {
  //calculate the sum by adding value to the total
  sum = sum + value;   //sum += value;
  }

//display the calculated sum
cout << "The sum is " << sum << endl;

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


