#include <iostream>
#include <iomanip>

using namespace std;

void dashes( int, int );
void oneLine( int );

int main()
{
dashes(3, 40);

cout << endl << endl << endl;

//dashes(40, 3);

//cout << endl << endl << endl;

return 0;
}

void dashes(int numLines, int numDashes)
{
int i;

for (i = 0; i < numLines; i++)
  oneLine(numDashes);
}



//display one line of num dashes on a new line

void oneLine(int num)
{
int i;

cout << "\n";

for (i = 0; i < num; i++)
  cout << "-";
}
