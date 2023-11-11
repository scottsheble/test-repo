/*
Amy B
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Acct
{
//The class variables
private:
  string acctNum;
  string acctName;
  char acctType;
  double acctBal;

//The class methods
public:
  Acct( string, string, char, double );      //the "constructor"

  void printAcct();       //display the account information
  
  void set_acctName( string );
};



int main()
{
//explicit use of constructor
Acct account = Acct( "123456", "Byrnes, Amy", 'C', 1000.00 );

//display the account object

account.printAcct();


//Create two more Acct objects

Acct account1 = Acct( "987654", "Amonte, Tony", 'S', 5000000.00);

Acct account2 = Acct( "321098", "Belfour, Ed", 'C', 6000000.25);



account1.printAcct();    //prints account information for Amonte, Tony

account2.printAcct();    //prints account information for Belfour, Ed


//create an object by implicitly using constructor

Acct account3("85421", "Mouse, Minnie",  'S', 100.01);

account3.printAcct();

//account3.acctName = "Mouse, Mickey";
account3.set_acctName( "Mouse, Mickey" );

account3.printAcct();


return 0;
}



/***************************************************************
Constructor

Use: Creates an object using passed in values

Arguments: newAcctNum: a string with the account number for the object
           newAcctName: a string with the name of the account holder
           newAcctType: a character with the type of account being created
           newAcctBal: a double with the potentail balance of the account

***************************************************************/

Acct::Acct( string newAcctNum, string newAcctName, char newAcctType, double newAcctBal )
{
//assign the passed in account number, name, and type to the corresponding data members

acctNum = newAcctNum;
acctName = newAcctName;
acctType = newAcctType;
acctBal = newAcctBal;
}


/***************************************************************
void printAcct

Use: Displays an object

Arguments: none

Returns: none
***************************************************************/

void Acct::printAcct()
{
//display the account number and name
cout << "Account Number: " << acctNum
     << "       Account Name: " << acctName << endl;

//display the account type based on the character
if( acctType == 'C' )
  {
  cout << "Account Type:   Checking";
  }
else
  {
  cout << "Account Type:   Savings";
  }

//display the balance of the account
cout << "     Account Balance: " << acctBal << endl << endl;
}


void Acct::set_acctName( string newAcctName )
{
acctName = newAcctName;
}


