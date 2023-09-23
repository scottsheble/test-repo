#include <iostream>
#include <iomanip>

using namespace std;

double initialinv = 0;
double annualinv = 0;
double year1 = 0;
double year2 = 0;
double year3 = 0;
double year4 = 0;

int main()
{

    cout << "How much is the initial investment amount? ";
    cin >> initialinv;
    cout << "What is the annual interest rate? ";
    cin >> annualinv;
    cout << endl;
    cout << endl;

    year1 = initialinv + (initialinv * annualinv / 100);
    year2 = year1 + (year1 * annualinv / 100);
    year3 = year2 + (year2 * annualinv / 100);
    year4 = year3 + (year3 * annualinv / 100);

    cout << "Investment Results";
    cout << endl;
    cout << endl;
    cout <<"Initial Investment"  << setprecision(2) << fixed << right << setw(15) << initialinv;
    cout << endl;
    cout << "Annual Interest Rate" << setprecision(1) << fixed << right << setw(13) <<  annualinv;
        cout << endl;
    cout << endl;
    cout << "Year 1 account value $" << setprecision(2) << fixed << year1 << fixed << right << "  --  increase of $" << setprecision(2) << fixed << (year1 - initialinv);
    cout << endl;
    cout << "Year 2 account value $" << year2 << "  --  increase of $" << setprecision(2) << fixed << (year2 - year1);
    cout << endl;
    cout << "Year 3 account value $" << year3 << "  --  increase of $" << setprecision(2) << fixed << (year3 - year2);
    cout << endl;
    cout << "Year 4 account value $" << year4 << "  --  increase of $" << setprecision(2) << fixed << (year4 - year3);
    cout << endl;




}