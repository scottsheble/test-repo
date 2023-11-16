/*
Exam 2 Review Problem 3

Declare an array to hold 150 double values. Initialize the array
so the first value is 2.40, the second is 2.41, the third is 3.40,
and the remaining values are 0. Do this in two different ways.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
//Way 1 (part of declaration statement)
double array1[150] = { 2.40, 2.41, 3.4 };

//Way 2 ( as several executable statements)
double array2[150];

array2[0] = 2.4;
array2[1] = 2.41;
array2[2] = 3.4;

for(int sub = 3; sub < 150; sub++)
 {
 array2[sub] = 0.0; 
 }

return 0;
}






