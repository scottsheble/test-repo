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


return 0;
}


