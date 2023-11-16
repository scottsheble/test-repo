/*
Exam 2 Review Problem 2

Assume that an array named array has been declared to hold
6 floats and has been completely filled with floats.

Write a loop to display all the values in the array.

Write a loop to display all the values in the array in reverse order.

Write a loop to add up every other value in the array, starting
from subscript 1. Display the sum.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
float array[6] = {12.2, 25.9, 7.4, 11.1, 85.3, 32.0};

//Write a loop to display all the values in the array.

//display in reverse order
int sub1;
for( sub1 = 5; sub1 >= 0; sub1 = sub1 - 1 )
  {
  cout << array[sub1] << endl;
  }


//Write a loop to add every other value in the array, starting
//from subscript 1. Display the sum.
int sub2;
float sum = 0.0;
for( sub2 = 1; sub2 < 6; sub2 += 2)
  {
  sum += array[sub2];
  }

cout << sum;

return 0;
}











