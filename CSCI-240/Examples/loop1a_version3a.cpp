//for loop from the lecture notes
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
int i;
int numTimes;
int numDisplay;

cout << "How many numbers? ";
cin >> numTimes;

//initialize the number of values displayed on the screen
numDisplay = 0;

for (i = 0; i < numTimes ; i++ )
  {
  cout << setw(4) << i;
  
  //display 4 values per line
  //increment the number of values displayed
  numDisplay++;
  
  //have 4 values been displayed?

  if(numDisplay == 4)
    {
    //display a newline
    cout << endl;
    
    //reset the number to display back to 0
    numDisplay = 0;
	}//end curly brace if statement
  }//end curly brace for loop
 
cout << endl << "... the pgm continues..." << endl;


return 0;
}


