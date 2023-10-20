#include <iostream>
#include <iomanip>

using namespace std;

void lines( int );


int main()
{
lines( 40 );

cout << endl << endl << endl;

//lines(5);

//cout << endl << endl << endl;

return 0;
}



void lines(int n)
{
int i;  //NOTE: use of a local variable

cout << "\n";

for (i = 1; i <= n; i++)
  cout << "-";


cout << "\n";

for (i = 1; i <= n; i++)
  cout << "-";
}





