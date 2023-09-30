//do while loop from the notes

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int aSpeed;
int speedSum = 0;
int speedCount = 0;

string choice;

do
  {
  //Get a speed and process it
  cout << "\nEnter a speed: ";
  cin >> aSpeed;

  speedCount++;
  speedSum += aSpeed;

  //get choice from user
  cout << "\nAnother? (y/n) ";
  cin >> choice;
  }
while (choice == "y");

//calculate and display the average
cout << "\nAverage is " << (double) speedSum / speedCount;

return 0;
}


