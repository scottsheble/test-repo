// Letter Grade daily - main

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int score;
  char letter_grade = 'X';

  // Get the score from the user
  cout << "What is the test score? ";
  cin >> score;

  // Determine the letter grade (write your code after this line)
  if (score >= 92){
    //std::cout << std::endl;
    letter_grade = 'A';
    //std::cout << "\nThe score " << score << " earns the grade" << letter_grade;
  }
  if (score <= 91 && score >= 84 ){
    //std::cout << std::endl;
    letter_grade = 'B';
    //std::cout << "\nThe score " << score << " earns the grade" << letter_grade;
  }
    if (score <= 83 && score >= 76 ){
    //std::cout << std::endl;
    letter_grade = 'C';
    //std::cout << "\nThe score " << score << " earns the grade" << letter_grade;
  }
    if (score <= 75 && score >= 68  ){
    //std::cout << std::endl;
    letter_grade = 'D';
    //std::cout << "\nThe score " << score << " earns the grade" << letter_grade;
  }
      if (score <= 67 && score >= 0  ){
    //std::cout << std::endl;
    letter_grade = 'F';
    //std::cout << "\nThe score " << score << " earns the grade" << letter_grade;
  }

  // Display the score and letter grade
  cout << endl
       << "The score " << score << " earns the grade " << letter_grade << endl;

  return 0;
}
