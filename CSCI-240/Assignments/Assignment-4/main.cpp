/********************************************************
    CSCI 240        Program 3       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 9/29/2023

    Purpose: This program demonstrates generating three 
    sets of random numbers.

    Created by scott sheble on 9/28/23.
*********************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>




using namespace std;

const double TAX_BRACKET1 = (0.1);
const double TAX_BRACKET2 = (0.12);
const double TAX_BRACKET3 = (0.22);
const double TAX_BRACKET4 = (0.24); 

const double BRACKET_LIMIT1 = (11000);
const double BRACKET_LIMIT2 = (44725);
const double BRACKET_LIMIT3 = (95375);
const double BRACKET_LIMIT4 = (95375);

double grossIncome = (0); 
double incomeTax = 0;
double incomeAboveBracket = 0;

int main()
{
    std::cout << "What is your gross income? ";
    std::cin >> grossIncome;
    if (grossIncome <= BRACKET_LIMIT1) // check against bracket limit 1
    {
        incomeTax = (TAX_BRACKET1 * grossIncome);
    }
    else if (grossIncome > BRACKET_LIMIT1 && grossIncome <= BRACKET_LIMIT2) // check against bracket limit 2 and bracket limit 1
    {
        incomeAboveBracket = grossIncome - BRACKET_LIMIT1; // finds how much income is taxable above the bracket
        incomeTax = (0.1 * 11000) + (0.12 * incomeAboveBracket); 
    }
    else if (grossIncome > BRACKET_LIMIT2 && grossIncome <= BRACKET_LIMIT3) // check against bracket limit 2 and bracket limit 3
    {
        incomeAboveBracket = grossIncome - BRACKET_LIMIT2; // finds how much income is taxable above the bracket
        incomeTax = (0.1 * 11000) + (0.12 * 33725) + (0.22 * incomeAboveBracket);
    }
    else if (grossIncome > BRACKET_LIMIT4) // check against bracket limit 4
    {
        incomeAboveBracket = grossIncome - BRACKET_LIMIT4; // finds how much income is taxable above the bracket
        incomeTax = (0.1 * 11000) + (0.12 * 33725) + (0.22 * 50650) + (0.24 * incomeAboveBracket);
    }
        
    std::cout << std::endl;
    std::cout << "Gross Income:          $ " << fixed << setprecision(2) << right << setw(5) << fixed << grossIncome << std::endl;
    std::cout << "Income Tax:            $ " << fixed << setprecision(2) << right << setw(5) << fixed << incomeTax << std::endl;
    std::cout << std::endl;
    return 0;
}
