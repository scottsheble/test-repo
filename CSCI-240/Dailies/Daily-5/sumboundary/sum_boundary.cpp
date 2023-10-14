/*
Sum Values Between Boundary Daily
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int lower, upper;

  std::cout << "What is the lower bound? ";
  std::cin >> lower;

  std::cout << "What is the upper bound? ";
  std::cin >> upper;

  if (lower > upper)
  {
    int temp = lower;
    lower = upper;
    upper = temp;

    std::cout << "\n*** boundary values have been swapped ***\n";
  }

  int result = 0;
  for (int i = lower; i <= upper; i++)
  {
    result += i;
  }

  std::cout << "\nThe sum of the values between " << lower << " and " << upper << " is " << result << "\n";

  return 0;
}
