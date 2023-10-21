/*
This program is used to test the sumOfASCII function
*/

#include <iostream>
#include <iomanip>

using namespace std;

void displayHelp();

int sumOfASCII(int limit)
{
    char startingChar; //starting character for static_cast loop.
    int sum = 0;

    char choice;
    std::cout << "Would you like to summate (L)owercase or (U)ppercase characters? ";
    std::cin >> choice;

    if (choice == 'L' || choice == 'l') 
    {
        startingChar = 'a';
    } else if (choice == 'U' || choice == 'u') 
    {
        startingChar = 'A';
    } else {
        std::cout << "Invalid choice. Please enter 'L' for lowercase or 'U' for uppercase characters." << std::endl;
        return 0;  // Return 0 to indicate an error
    }

    // calculate sum of ASCII values by static_cast.
    for (char i = startingChar; i < startingChar + limit; i++) 
    {
        sum += static_cast<int>(i); //type conversion to int.
    }

    return sum;
}

int main()
  {
  int result;
    
  //Test 1 - first 5 uppercase characters
  cout << "Test 1: first 5 uppercase characters (make sure to enter U when prompted)."
       << endl << endl;
  
  result = sumOfASCII(5);

  //Is the result from the function 335?
  //Yes, the function worked
  if( result == 335)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 335." << endl;

    displayHelp();
    }

  //Test 2 - first 5 lowercase characters
  cout << endl
       << "Test 2: first 5 lowercase characters (make sure to enter L when prompted)."
       << endl << endl;

  result = sumOfASCII(5);

  //Is the result from the function 495?
  //Yes, the function worked
  if( result == 495)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 495." << endl;

    displayHelp();
    }

  //Test 3 - all lowercase characters
  cout << endl
       << "Test 3: all lowercase characters (make sure to enter L when prompted)."
       << endl << endl;

  result = sumOfASCII(26);

  //Is the result from the function 2847?
  //Yes, the function worked
  if( result == 2847)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 2847." << endl;

    displayHelp();
    }

  //Test 4 - all uppercase characters
  cout << endl
       << "Test 4: all uppercase characters (make sure to enter U when prompted)."
       << endl << endl;

  result = sumOfASCII(26);

  //Is the result from the function 2015?
  //Yes, the function worked
  if( result == 2015)
    {
    cout << "SUCCESS" << endl << endl;
    }
  //No, the function returned the wrong value
  else
    {
    cout << "FAIL" << endl
         << "The function returned " << result << ". It should have returned 2015." << endl;

    displayHelp();
    }

  return 0;
  }


/*
displayHelp

This function displays information to help determine why incorrect output
might be produced.

Arguments:  None

Returns:  Nothing
*/
void displayHelp()
  {
  cout << "Check to make sure:"<< endl
       << "  - the loop is executing the correct number of times" << endl
       << "  - the variable holding the calculated sum is properly initialized" << endl
       << "  - the sum is being calculated correctly by adding ascii values" << endl
       << "  - the correct case was entered (U or L)" << endl << endl;
}
