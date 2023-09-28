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

int num;
int countElements = 0;
const int SET1_SIZE = 52;
const int SET2_MAXSIZE = 80;
const int SET3_MAXSIZE = 100;
const double MIN_RAND_VALUE = 0.0;
const double MAX_RAND_VALUE = 200.0;
const int VALUES_PER_LINE = 6;


int main()
{
    srand(17);

    for (int i = 0, j = 1; i < 52; i++, j++) {
        countElements++;
        std::cout << 1 + rand() % 100 << " ";
        if (j == 6) {
            j = 0;
            std::cout << std::endl;
        }
        

    }
    std::cout << "\n\nSet 1 has " << countElements << " values";

    while (int i = 0, j = 1; i < 52; i++, j++)


    return 0;
}
