#include <iostream>
#include <iomanip>

using namespace std;

void pageHeader(int);


int main()
{
pageHeader(1);

cout << endl << endl;

//pageHeader(42);

//cout << endl << endl;

return 0;
}


void pageHeader(int pagenum)
{
cout << "\f\tInventory Control System\t\tpage "  
     << pagenum;

cout << "\nDescription\t\tQuantity\t\tPrice\n\n";
}

