/******************************************************************************
PiggyBank class example

The class description can be found on Blackboard under

   Content/In Class Examples/PiggyBank Class

Amy B
******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//class definition for PiggyBank class
class PiggyBank
{
public:
  PiggyBank();
  
  void printBank();
  void printBankValue();
  
  void emptyBank();
  
  void addCoins( int, int );
  void addNickels(int);
  void addQuarters(int);

private:
  int num_nickels, num_quarters;
  
  //symbolic constants
  static const double NICKEL;
  static const double QUARTER;
  
//suggestion for program 8
//  static const string MONTH_NAMES[12];
  
  double calcPiggyBankValue();
};

//put values into the symbolic constants
const double PiggyBank::NICKEL = 0.05;
const double PiggyBank::QUARTER = 0.25;

//suggestion for program 8
//const string Date::MONTH_NAMES[12] = {"January", "February" };

int main()
{
//create an object explicitly
PiggyBank bank1 = PiggyBank();

//create an object implicitly
PiggyBank bank2;

//Display the two objects
cout << "bank1" << endl;

bank1.printBank();
bank1.printBankValue();

cout << endl << "bank2" << endl;

bank2.printBank();
bank2.printBankValue();

//Test the add methods
//Add 6 nickels and 8 quarters to the explicitly created object
bank1.addCoins(6, 8);
cout << endl << "bank1" << endl;
bank1.printBank();
bank1.printBankValue();

//Add 4 nickels and -9 quarters to the implicitly created object
bank2.addCoins(4, -9);
cout << endl << "bank2" << endl;
bank2.printBank();
bank2.printBankValue();

//Add 42 quarters to the implicitly created object
bank2.addQuarters(42);
bank2.printBank();
bank2.printBankValue();

//empty the implictly created object
bank2.emptyBank();
bank2.printBank();
bank2.printBankValue();



return 0;
}//end of int main()


//constructor
PiggyBank::PiggyBank()
{
num_nickels = 0;
num_quarters = 0;
}

//print method
void PiggyBank::printBank()
{
cout << "Nickels: " << num_nickels << "     Quarters: "
     << num_quarters << endl;
}

//addCoins
void PiggyBank::addCoins( int more_nickels, int more_quarters )
{
addNickels( more_nickels );
addQuarters( more_quarters );
}

void PiggyBank::addNickels( int extra_nickels )
{
if( extra_nickels < 0 )  //bad
  {
  cout << "Number of nickels cannot be negative" << endl;
  }
else  //good
  {
  num_nickels += extra_nickels;
  }
}

void PiggyBank::addQuarters( int extra_quarters )
{
if( extra_quarters < 0)
  {
  cout << "Number of quarters cannot be negative" << endl;
  }
else
  {
  num_quarters += extra_quarters;
  }
}

void PiggyBank::printBankValue()
{
cout << fixed << setprecision(2);

cout << "$" << calcPiggyBankValue() << endl;
}

//private method
double PiggyBank::calcPiggyBankValue()
{
return num_nickels * NICKEL + num_quarters * QUARTER;
}

//empty method
void PiggyBank::emptyBank()
{
num_nickels = 0;
num_quarters = 0;
}




