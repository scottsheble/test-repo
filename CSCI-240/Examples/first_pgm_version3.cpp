//single line comment

         /*

multi-line comment

name, section of 240, due date, brief assign. description
*/
//write a program to add two quiz scores

#include <iostream>
#include <iomanip>

using namespace std;

int main()
  {
  //create variables that are needed for the program
  int quiz1, quiz2, quiz_sum;
  
  //get the two quiz scores
  //quiz1 = 5;
  cout << "What is the quiz 1 score? ";
  cin >> quiz1;
  
  quiz2 = 2;
  
  //add the quiz scores and save the sum
  quiz_sum = quiz1 + quiz2;
  
  //display the calculated sum
  cout << "The sum of the quiz scores is " << quiz_sum << ".";  

  return 0;
  }



