/********************************************************
    CSCI 240        Program 2       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 9/15/2023

    Purpose: This program calculates a powerlifter's total
    lifts and formats the output into a report.

    Created by scott sheble on 8/28/23.
*********************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int maxSquat = 0;
int maxBench = 0;
int maxDeadlift = 0;
int powerliftingTotal = 0;
const int LEFT_COLUMN_SPACES = 20;
const int RIGHT_COLUMN_SPACES = 8;
const float WILKS_COEFFICIENT = 0.5976;
float wilksScore = 0;


int main()
{
    
    std::cout << "What is your max squat? ";
    std::cin >> maxSquat;
    std::cout << "What is your max bench press? ";
    std::cin >> maxBench;
    std::cout << "What is your max deadlift? ";
    std::cin >> maxDeadlift;
    powerliftingTotal = (maxSquat + maxBench + maxDeadlift);
    wilksScore = powerliftingTotal * WILKS_COEFFICIENT;
    std::cout << endl;
    
    /**
     *  Allocating number of spaces for output reports left & right columns
     *  and creating format for console output.
     *  ...
     */
    
    std::cout << left << setw(LEFT_COLUMN_SPACES) << "Max Squat: " << right << setw(RIGHT_COLUMN_SPACES)  << maxSquat << std::endl;
    std::cout << left << setw(LEFT_COLUMN_SPACES) << "Max Bench Press: " << right << setw(RIGHT_COLUMN_SPACES)  << maxBench << std::endl;
    std::cout << left << setw(LEFT_COLUMN_SPACES) << "Max Deadlift: " << right << setw(RIGHT_COLUMN_SPACES)  << maxDeadlift << std::endl;
    std::cout << endl;
    std::cout << left << setw(LEFT_COLUMN_SPACES) << "Powerlifting Total: " << right << setw(RIGHT_COLUMN_SPACES)  << powerliftingTotal << std::endl;
    std::cout << left << setw(LEFT_COLUMN_SPACES) << "Wilks Score: " << right << setw(RIGHT_COLUMN_SPACES) << fixed << setprecision(3) << wilksScore << std::endl;
    std::cout << endl;
    return 0;
}
