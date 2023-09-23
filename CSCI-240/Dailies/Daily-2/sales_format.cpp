/********************************************************
    CSCI 240        Daily 2       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 9/15/2023

    Purpose: Daily 2

    Created by scott sheble on 9/08/23.
*********************************************************/

#include <iostream>
#include <iomanip>


int count = 0;
double price = 0;
double cost = 0;
static int rightColumnSpaces = 5;

int main()
{
    
    std::cout << "What is the price for a single item? ";
    std::cin >> price;
    std::cout << "How many items were purchased? ";
    std::cin >> count;
    cost = (price * count);
    std::cout << std::endl;
    std::cout << std::right << std::setw(rightColumnSpaces) << count << " items at $" << std::setprecision(2) << std::fixed << price << " each will cost $" << std::setprecision(2) << std::fixed << cost << std::endl;
    
    return 0;
}
