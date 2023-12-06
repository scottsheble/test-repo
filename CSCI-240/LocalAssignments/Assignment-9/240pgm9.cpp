/************

Make sure to fill this in with your name, etc...

************/

#include <iostream>
#include <string>

using namespace std;

#define LINE_BREAK cout << endl; for (int i = 0; i < 75; i++) cout << "-"; cout << endl;

class Vector
  {
  };


int main()
  {
  //Test the both constructors and the to_string method
  Vector alpha;

  cout << "Test #1: Testing default constructor and to_string(): alpha == " << alpha.to_string() << endl;

  int slacker[3] = {1, 2, 3};

  Vector beta(slacker);

  cout << "\nTest #2: Testing alternate constructor: beta == " << beta.to_string() << endl;

  LINE_BREAK


  //Test the add method
  cout << "\nTest #3: Testing add functionality." << endl;
  cout << alpha.to_string() << " + " << beta.to_string() << " == " << alpha.add(beta).to_string() << endl;

  slacker[0] = 14;
  slacker[1] = 2;
  slacker[2] = -9;


  //Test the set and subtract methods
  cout << "\nTest #4: Testing set and subtract functionality." << endl;
  alpha.set(slacker);
  cout << alpha.to_string() << " - " << beta.to_string() << " == " << alpha.subtract(beta).to_string() << endl;

  LINE_BREAK


  //Test the multiply methods
  cout << "\nTest #5: Testing scalar multiplication." << endl;
  cout << alpha.to_string() << " * 4 == " << alpha.multiply(4).to_string() << endl;

  cout << "\nTest #6a: Testing cross-product multiplication with a Vector argument." << endl;
  cout << alpha.to_string() << " X " << beta.to_string() << " == " << alpha.multiply(beta).to_string() << endl;

  for (int i = 0; i < 3; i++)
    slacker[i] = (i + 1);

  cout << "\nTest #6b: Testing cross-product multiplication with an integer-array argument." << endl;
  cout << alpha.to_string() << " X <1, 2, 3> == " << alpha.multiply(slacker).to_string() << endl;

  for (int i = 0; i < 3; i++)
    slacker[i] = (i * i);

  alpha.set(slacker);

  LINE_BREAK


  //Test the isEqual method
  cout << "\nTest #7a: Testing for equality (failure)." << endl;
  cout << "Is " << alpha.to_string() << " equal to " << beta.to_string() << "?" << endl;
  if (alpha.isEqual(beta))
    cout << "Yes (this is wrong)." << endl;
  else
    cout << "No (this is correct)." << endl;

  for (int i = 0; i < 3; i++)
    slacker[i] = (i + 1);

  alpha.set(slacker);

  cout << "\nTest #7b: Testing for equality (success)." << endl;
  cout << "Is " << alpha.to_string() << " equal to " << beta.to_string() << "?" << endl;
  if (alpha.isEqual(beta))
    cout << "Yes (this is correct)." << endl;
  else
    cout << "No (this is wrong)." << endl;

  LINE_BREAK


  //Test the isSimilar methods
  cout << "\nTest #8a: Testing for similarity (equal vectors)." << endl;
  cout << "Is " << alpha.to_string() << " similar to " << beta.to_string() << "?" << endl;

  if (alpha.isSimilar(beta))
    cout << "Yes (this is correct)." << endl;
  else
    cout << "No (this is wrong)." << endl;

  for (int i = 0; i < 3; i++)
    slacker[i] = (i + 1) * 6;

  beta.set(slacker);

  cout << "\nTest #8b: Testing for similarity (scalar vectors)." << endl;
  cout << "Is " << alpha.to_string() << " similar to " << beta.to_string() << "?" << endl;

  if (alpha.isSimilar(beta))
    cout << "Yes (this is correct)." << endl;
  else
    cout << "No (this is wrong)." << endl;

  cout << "\nTest #8c: Testing for similarity (scalar vectors)." << endl;
  cout << "Is " << beta.to_string() << " similar to " << alpha.to_string() << "?" << endl;

  if (beta.isSimilar(alpha))
    cout << "Yes (this is correct)." << endl;
  else
    cout << "No (this is wrong)." << endl;

  for (int i = 0; i < 3; i++)
    slacker[i] = (i * i * i) + (10 - i);

  beta.set(slacker);

  cout << "\nTest #8d: Testing for similarity (failure)." << endl;
  cout << "Is " << alpha.to_string() << " similar to " << beta.to_string() << "?" << endl;

  if (alpha.isSimilar(beta))
    cout << "Yes (this is wrong)." << endl;
  else
    cout << "No (this is correct)." << endl;

  return 0;
  }

//Implement and Document the Vector class methods below this line
