// 240 Count Factorial Digits Daily

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int N;

  cout << "N value (must be greater than or equal to 0)? ";
  cin >> N;

  if (N < 0 || N > 12)
  {
    cout << "\nInvalid Input: " << N << endl;
  }
  else
  {
    int factorial = 1;

    for (int i = 1; i <= N; i++)
    {
      factorial *= i;
    }

    int digits = 0;
    int temp = factorial;
    while (temp != 0)
    {
      temp /= 10;
      digits++;
    }

    std::cout << std::endl;

    cout << N << "! is equal to " << factorial << ". There are " << digits << " digits." << endl;
  }

  return 0;
}
