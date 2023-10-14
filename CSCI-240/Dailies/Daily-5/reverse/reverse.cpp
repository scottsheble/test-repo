// CSCI 240 daily - Reverse Number

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int N;

std::cout << "N value (must be positive)? ";

do
{
  
  std::cin >> N;

  if (N <= 0)
  {
    std::cout << "Error: the N-value must be positive. Try again: ";
  }
} while (N <= 0);


  int originalN = N;
 // int reversedN = 0;

  // while (N > 0)
  // {
  //   reversedN = (N % 10);
  //   N /= 10;
  // }

  std::cout << "\nOriginal: " << originalN << std::endl;

  cout << "Reversed: ";
	while(N > 0) {

		int rem = N % 10;
		
		N = N / 10;
		
		cout << rem;
	}

	cout << endl;


  return 0;
}
