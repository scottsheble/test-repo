/*
Exam 2 Review Problem 1

A function named calcAverage takes two arguments: a double
that holds a sum, and an integer that holds a count. It
returns a double: the calculated average.

a) What is the function prototype?

b) What is a possible function header?

C) Write a calling statement for the calcAverage function
using the following declarations:

double average, total;
int numValues;
*/


#include <iostream>
#include <iomanip>

using namespace std;
/*A function named calcAverage takes two arguments: a double
that holds a sum, and an integer that holds a count. It
returns a double: the calculated average. */

//a) What is the function prototype?
double calcAverage( double, int );

int main()
{
/*A function named calcAverage takes two arguments: a double
that holds a sum, and an integer that holds a count. It
returns a double: the calculated average. */

//c) Write a calling statement for the calcAverage function
//   using the following declarations:
double average, total;
int numValues;

average = calcAverage( total, numValues );

//calculate the average from a sum of 250 and count of 4

average = calcAverage (250, 4);



return 0;
}

/*A function named calcAverage takes two arguments: a double
that holds a sum, and an integer that holds a count. It
returns a double: the calculated average. */

//b) What is a possible function header?
double calcAverage( double sum, int count )
{
}

