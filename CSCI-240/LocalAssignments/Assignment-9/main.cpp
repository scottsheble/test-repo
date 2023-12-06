/********************************************************
    CSCI 240        Program 8       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 12/01/23

    Purpose: For this assignment, implement a class 
    representing a 3D vector which will make extensive 
    use of overloading class methods. This means there 
    will be multiple versions of methods defined that 
    each take different arguments. This assignment 
    rewards one for being "smart but also lazy" when 
    it comes to implementing each of these methods, 
    as they can readily use previously defined methods 
    to reduce the amount of code necessary to write to 
    complete the next one.
 
    Created by scott sheble on 11/08/23.
*********************************************************/

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

#define LINE_BREAK cout << endl; for (int i = 0; i < 75; i++) cout << "-"; cout << endl;

class Vector
  {
    private:
    int values[3];

public:
    Vector();
    Vector(int _values[]);
    void set(int _values[]);
    Vector add(int _values[]);
    Vector add(Vector _other);
    Vector multiply(int scalar);
    Vector multiply(int _values[]);
    Vector multiply(Vector _other);
    Vector subtract(int _values[]);
    Vector subtract(Vector _other);
    bool isEqual(int _values[]);
    bool isEqual(Vector _other);
    bool isSimilar(int _values[]);
    bool isSimilar(Vector _other);
    std::string to_string();
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

/**
 * @brief Construct a new Vector:: Vector object. The default constructor should initialize 
 * the values of the private array of integers to all be equal to zero.
 * 
 */
Vector::Vector() {
    values[0] = values[1] = values[2] = 0;
}

/**
 * @brief Construct a new Vector:: Vector object. This alternate constructor will allow for 
 * the three values of the private array of integers to be initialized from values found in 
 * an array of integers passed as an argument. For this assignment, we may assume this 
 * argument always has exactly three values to be found.
 * 
 * @param _values 
 */
Vector::Vector(int _values[]) {
    set(_values);
}

/**
 * @brief This accessor method will unconditionally copy the values from the array of 
 * integers passed as an argument to the private array of integers belonging to this object. 
 * Note: It is strongly recommended that you simply invoke this method within the alternate 
 * constructor described above, to avoid repeating the same code in two locations.
 * 
 * @param _values 
 */
void Vector::set(int _values[]) {
    for (int i = 0; i < 3; ++i) {
        values[i] = _values[i];
    }
}

/**
 * @brief This method will return a Vector object that contains the sum of the corresponding 
 * values from this Vector's private array of integer values and the array of integers 
 * passed as an argument.
 * 
 * @param _values 
 * @return Vector 
 */
Vector Vector::add(int _values[]) {
    Vector result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = values[i] + _values[i];
    }
    return result;
}

/**
 * @brief This method will do exactly the same as the above method, except the argument is 
 * another Vector object. Note: It is strongly recommended to only formally implement one of 
 * these two methods and to utilize the alternate constructor to "typecast" an array of 
 * integers as a Vector object and then call the overloaded version. Again, we want to avoid 
 * redundantly repeating code whenever possible.
 * 
 * @param _other 
 * @return Vector 
 */
Vector Vector::add(Vector _other) {
    int otherValues[3] = {_other.values[0], _other.values[1], _other.values[2]};
    return add(otherValues);
}

/**
 * @brief This method will return a Vector object containing the same values as the Vector 
 * object the invoked this method and multiplied by the integer passed as an argument. So 
 * <1, 2, 3> * 3 = <3, 6, 9>.
 * 
 * @param scalar 
 * @return Vector 
 */
Vector Vector::multiply(int scalar) {
    Vector result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = values[i] * scalar;
    }
    return result;
}

/**
 * @brief This method will return a Vector object containing the Cross Product of the Vector 
 * object that invoked this method and the "vector" argument passed as an array of integers
 * To calculate the coefficients of this cross product Vector object, use the following 
 * formula, where a and b are two vectors each with three coefficient values:
 * 
 * @param _values 
 * @return Vector 
 */
Vector Vector::multiply(int _values[]) {
    Vector result;
    result.values[0] = (values[1] * _values[2]) - (values[2] * _values[1]);
    result.values[1] = (values[2] * _values[0]) - (values[0] * _values[2]);
    result.values[2] = (values[0] * _values[1]) - (values[1] * _values[0]);
    return result;
}

/**
 * @brief This method will do exactly the same as the above method, except the argument is 
 * another Vector object.
 * 
 * @param _other 
 * @return Vector 
 */
Vector Vector::multiply(Vector _other) {
    int otherValues[3] = {_other.values[0], _other.values[1], _other.values[2]};
    return multiply(otherValues);
}

/**
 * @brief This method will return a Vector object that contains the difference of the 
 * corresponding values from this Vector's private array of integer values and the array of 
 * integers passed as an argument.
 * 
 * @param _values 
 * @return Vector 
 */
Vector Vector::subtract(int _values[]) {
    Vector result;
    for (int i = 0; i < 3; ++i) {
        result.values[i] = values[i] - _values[i];
    }
    return result;
}

/**
 * @brief This method will do exactly the same as the above method, except the argument is 
 * another Vector object.
 * 
 * @param _other 
 * @return Vector 
 */
Vector Vector::subtract(Vector _other) {
    int otherValues[3] = {_other.values[0], _other.values[1], _other.values[2]};
    return subtract(otherValues);
}

/**
 * @brief This method will return a true or false value depending on whether the values of 
 * this Vector object's array of integers match exactly to those found in the array of 
 * integers being passed as an argument.
 * 
 * @param _values 
 * @return true 
 * @return false 
 */
bool Vector::isEqual(int _values[]) {
    for (int i = 0; i < 3; ++i) {
        if (values[i] != _values[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief This method will do exactly the same as the above method, except the argument is 
 * another Vector object.
 * 
 * @param _other 
 * @return true 
 * @return false 
 */
bool Vector::isEqual(Vector _other) {
    int otherValues[3] = {_other.values[0], _other.values[1], _other.values[2]};
    return isEqual(otherValues);
}

/**
 * @brief This method will return a true or false value depending on whether the direction 
 * of this Vector object is the same as the one represented by the "vector" passed as an 
 * argument. Similarity ignores the magnitude of each vector and instead only considers 
 * whether they are pointing in the same direction.
 * 
 * @param _values 
 * @return true 
 * @return false 
 */
bool Vector::isSimilar(int _values[]) {
    for (int i = 0; i < 3; ++i) {
        if (values[i] == 0 && _values[i] != 0) {
            return false;
        } else if (values[i] != 0 && _values[i] == 0) {
            return false;
        } else if (values[i] % _values[i] != 0 && _values[i] % values[i] != 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief This method will do exactly the same as the above method, except the argument is 
 * another Vector object.
 * 
 * @param _other 
 * @return true 
 * @return false 
 */
bool Vector::isSimilar(Vector _other) {
    int otherValues[3] = {_other.values[0], _other.values[1], _other.values[2]};
    return isSimilar(otherValues);
}

/**
 * @brief This method will return a string value representing this Vector object's 
 * mathematical vector.
 * 
 * @return std::string 
 */
std::string Vector::to_string() {
    std::ostringstream oss;
    oss << '<' << values[0] << ", " << values[1] << ", " << values[2] << '>';
    return oss.str();
}
