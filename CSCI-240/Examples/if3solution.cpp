/*
if Problem 3
Write a chunk of code that will test if the value in an integer
variable called num is odd or even. If the value is odd, display
"ODD" and add 1 to the odd_cnt variable. Otherwise, display "EVEN"
and add 1 to the even_cnt variable.

Display the counters.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int num;
int odd_cnt, even_cnt;

//set the counters to 0
odd_cnt = 0;
even_cnt = 0;

//get a number from the user
cout << "Enter an integer: ";
cin >> num;

//if number is odd, display "odd" message and add 1 to odd counter
//otherwise, display "even" message and add 1 to even counter

if( num % 2 == 1 )    //num % 2 != 0
  {
  cout << num << " is an ODD value" << endl;

  odd_cnt = odd_cnt + 1;
  }
else
  {
  cout << num << " is an EVEN value" << endl;
  
  even_cnt = even_cnt + 1;
  }

//display both counters
cout << endl 
     << "Even: " << even_cnt << endl
     << "Odd:  " << odd_cnt << endl;

return 0;
}


