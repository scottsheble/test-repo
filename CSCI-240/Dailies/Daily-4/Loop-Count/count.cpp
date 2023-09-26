//240 Count daily int main()

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
  int N;
  
  cout << "N value (must be greater than or equal to 1)? ";
  cin >> N;
  while (N == 0 || N < 0){
    std::cout<< "Error: the N-value must be greater than or equal to 1. Try again: ";
    cin >> N;
  }
  if (N != 0 || N > 0){
  for (int i = 0; i < N; i++){
    std::cout << std::endl;
    std::cout << i+1;

  }
  }
      std::cout << std::endl;
    

  return 0;
} // end main() 

