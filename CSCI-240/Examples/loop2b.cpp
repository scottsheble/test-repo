//second while loop from the notes

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int aSpeed;
int speedSum = 0;
int speedCount = 0;

//priming read - gets the 1st value into choice
string choice = "y";

while (choice == "y")
  {
  //Get a speed and process it
  cout << "\nEnter a speed: ";
  cin >> aSpeed;

  speedCount++;
  speedSum += aSpeed;

  //secondary read - get next choice from user
  cout << "\nAnother? (y/n) ";
  cin >> choice;
  }

//calculate and display the average
cout << "\nAverage is " << (double) speedSum / speedCount;

return 0;
}

