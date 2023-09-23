//Is Multiple main

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int num1, num2;
    //get two integer numbers
    cout << "What is the first number? ";
    cin >> num1;
    
    cout << "What is the second number? ";
    cin >> num2;

    if (num1 <= 0){
    cout << endl;
    cout << "*** Invalid input: one or both values is not positive";
    }

    if (num2 < 0){
    cout << endl;
    cout << "*** Invalid input: one or both values is not positive";
    } else if (num1 != 0 && num1 % num2 == 0){
        cout << endl;
        cout << num1 << " is a multiple of " << num2;

    } else if ((num1 % num2 != 0)) {
        cout << endl;
        cout << num1 << " is NOT a multiple of " << num2;
    }  


    cout << endl;
    return 0;

} // end main() 

