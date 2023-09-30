/**********************************************************************************************
 * NIU CSCI 340 Section YOUR_SECTION                                                          *
 * Recitation 1                                                                               *
 * Scott Sheble - Z1963374 - scottsheble
 * Group 5 Members: Scott Sheble, Maria, Sean                                             *
 *                                                                                            *
 *   I certify that everything I am submitting is either provided by the professor for use in *
 * the assignment, or work done by me personally. I understand that if I am caught submitting *
 * the work of others (including StackOverflow or ChatGPT) as my own is an act of Academic    *
 * Misconduct and will be punished as such.                                                   *
 *                                                                                            *
 **********************************************************************************************/

#include <iostream>
#include <string>

int main()
{
    char m = 'M'; //1000
    char d = 'D'; //500
    char c = 'C'; //100
    char l = 'L'; //50
    char x = 'X'; //10
    char v = 'V'; //5
    char i = 'I'; //1
    int inputNumber = 0;
    char romanNumConversion = 0;
    int remainder = 0;
    std::string s = "";
    std::cout << "Number to be converted: ";
    std::cin >> inputNumber;
    std::cout << std::endl;
    if (inputNumber >= 1000)
        for (int j = 0; inputNumber >= 1000; j++) //1000 M
        {
            inputNumber = inputNumber - 1000;
            s += m;
            j++;
        }
    if ((inputNumber >= 500) && (inputNumber < 600)) //500 D
            inputNumber = inputNumber - 500;
            s += d;
    
    if ((inputNumber >= 100) && (inputNumber < 499)) //100 C
        for (int j = 0; inputNumber >= 100; j++)
        {
            inputNumber = inputNumber - 100;
            s += c;
            j++;
        }
    if ((inputNumber > 100) && (inputNumber < 499)) //50 L
        for (int j = 0; inputNumber >= 100; j++)
        {
            inputNumber = inputNumber - 100;
            s += c;
            j++;
        }


    std::cout << "Roman Numeral Equiv: " << s;
    std::cout << std::endl;
    return 0;
}
