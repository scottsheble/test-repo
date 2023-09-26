//Is Even Odd daily
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int num;

  //get a number from the user
  cout << "Enter an integer value: ";
  cin >> num;
  if (num % 2 == 0){
    std::cout << std::endl;
    std::cout << "The value " << num << " is EVEN.";
    std::cout << std::endl;
  } else {
    std::cout << std::endl;
    std::cout << "The value " << num << " is ODD.";
    std::cout << std::endl;
  }


  //if the integer value is even, display a formatted "EVEN" message.
  //Otherwise display a formatted "ODD" message.
  

 
  return 0;
}

