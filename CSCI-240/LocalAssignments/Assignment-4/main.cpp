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
#include <ctime>
using namespace std;

const int SET1_SIZE = 52;
const int SET2_MAXSIZE = 80;
const int SET3_MAXSIZE = 100;
const double MIN_RAND_DOUBLE_VALUE = 0;
const double MAX_RAND_DOUBLE_VALUE = 200;
const int VALUES_PER_LINE = 6;


int main()
{
    std::cout << std::endl;
    srand(17);

    //Set 1 for loop generating random numbers and using variable j to check
    //for a line break.

    std::cout << "Set 1 has exactly " << SET1_SIZE << " values" << std::endl;

    for (int i = 0, j = 1; i < 52; i++, j++) {
        int num = rand();
        std::cout << setw(12) << num;
        if (j == VALUES_PER_LINE) {
            j = 0;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Set 2 while loop generating random numbers up until its set size and
    //using variables elementCounter and lineCounter to increment each
    //element until the sets size, and check for line breaks.


    int set2_size = rand() % SET2_MAXSIZE + 1;
    std::cout << "Set 2 has exactly " << set2_size << " values" << std::endl;

    int elementCounter = 0;
    int lineCounter = 1;
    while (elementCounter < set2_size) {
        int num = rand();
        cout << std::setw(12) << num;
        if (lineCounter == VALUES_PER_LINE) {
            lineCounter = 0;
            std::cout << std::endl;
        }
        elementCounter++;
        lineCounter++;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    //Set 3 generating random variables in a do while loop, using variables 
    //double_count to generate a random double variable, and doubleLineCount
    //to check for a line break.


    int set3_size = rand() % SET3_MAXSIZE + 1;
    std::cout << "Set 3 has exactly " << set3_size << " values" << std::endl;

    int double_count = 0;
    int doubleLineCounter = 1;
    do {
        double double_num = MIN_RAND_DOUBLE_VALUE + (rand() / (RAND_MAX / (MAX_RAND_DOUBLE_VALUE - MIN_RAND_DOUBLE_VALUE)));
        std::cout << fixed << setprecision(4) << std::setw(12) << double_num;

        if (doubleLineCounter == VALUES_PER_LINE) {
            doubleLineCounter = 0;
            std::cout << std::endl;
        }
        doubleLineCounter++;
        double_count++;

    } while (double_count < set3_size);

    std::cout << std::endl;

    return 0;
}
