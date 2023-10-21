/*
This program tests the Menu function
*/

#include <iostream>
#include <iomanip>

using namespace std;

int Menu()
{
    int choice;
    bool viableChoice = false; //boolean for determining if user choice is viable.

    do {

        std::cout << "Objectives" << std::endl << std::endl;
        std::cout << "1) Calculate the sum of the first N squared numbers" << std::endl;
        std::cout << "2) Calculate the average of the first N cubed numbers" << std::endl;
        std::cout << "3) Calculate the sum of the ASCII value of the first N characters" << std::endl;
        std::cout << "4) Word iterations from the NIU school chant." << std::endl << std::endl;
        std::cout << "5) Quit" << std::endl;
        std::cout << "Enter your choice:" << std::endl;

        std::cin >> choice; //user choice for menu option.

        if (choice < 1 || choice > 5) 
        {
            std::cin.clear();
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        } else {
            viableChoice = true;
        }
    } while (!viableChoice);
        
    return choice; //returns user's choice.
}

int main()
  {
  int response = Menu();

  //Is the value returned from Menu invalid?
  //Yes
  if(response < 1 or response > 5)
    {
    cout << "FAIL" << endl
         << "The function should not return a value less than 1 or" << endl
         << "greater than 5." << endl << endl
		 << "Check to make sure:" << endl
		 << "   - that you have a loop that will validate the value" << endl
         << "   - that the condition on the loop uses the correct compound condition" << endl;
    }
  //No
  else
    {
    cout << "SUCCESS" << endl;
    }

  return 0;
  }


