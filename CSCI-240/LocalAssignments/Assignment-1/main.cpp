/********************************************************
    CSCI 240        Program 1       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 9/08/2023

    Purpose: This program calculates and displays the
    profit per value of harvested crops as done in
    farming simulation video games.

    Created by scott sheble on 8/28/23.
*********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int seedCost = 0;
int matureTime = 0;
double expectedResale = 0;
double profitPerDay = 0;

int main()
{
    cout << "How much does this seed cost to buy? ";
    cin >> seedCost;
    cout << "How long does this crop take to mature? ";
    cin >> matureTime;
    cout << "What is the expected resale value of the mature crop? ";
    cin >> expectedResale;
    profitPerDay = (expectedResale - seedCost) / matureTime;
    cout << endl;
    cout << "The projected profit per day value of this crop is: " << profitPerDay << endl;
    cout << endl;
    
    return 0;
}

