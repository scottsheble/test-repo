//while loop from the lecture notes
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int aTemp;
int tempSum = 0;
int tempCount = 0;

//priming read - get aTemp from the user
cout << "\nEnter a temperature (-999 to quit): ";
cin >> aTemp;

while (aTemp > -999)
  {
  //process aTemp
  tempCount++;
  tempSum += aTemp;

  //secondary read - get next aTemp from user
  cout << "\nEnter next temperature (-999 to quit): ";
  cin >> aTemp;
  }

cout << "\nAverage is " << (double)tempSum/tempCount;


return 0;
}

