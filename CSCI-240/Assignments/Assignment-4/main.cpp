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
const double MIN_RAND_VALUE = 0.0;
const double MAX_RAND_VALUE = 200.0;
const int VALUES_PER_LINE = 6;


int main()
{
    srand(17);

    std::cout << "Set 1 has exactly " << SET1_SIZE << " values" << std::endl;
    for (int i = 0, j = 1; i < 52; i++, j++) {
        int num = rand();
        //std::cout << 1 + rand() % 100 << " ";
        std::cout << setw(12) << num;
        if (j == VALUES_PER_LINE) {
            j = 0;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "Set 2 has exactly " << SET2_MAXSIZE << " values" << std::endl;
    int elementCounter = 0;
    int lineCounter = 1;
    while (elementCounter < SET2_MAXSIZE) {
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

    int set3_size = rand() % SET3_MAXSIZE + 1;
    std::cout << "Set 3 has exactly " << set3_size << " values" << std::endl;
    int double_count = 0;
    do {
        double double_num = MIN_RAND_VALUE + (rand() / (RAND_MAX / (MAX_RAND_VALUE - MIN_RAND_VALUE)));
        std::cout << fixed << setprecision(4) << std::setw(12) << double_num;

        if ((double_count + 1) % VALUES_PER_LINE == 0 || double_count == set3_size -1){
            std::cout << std::endl;
        }
        double_count++;
    } while (double_count < set3_size);

    return 0;
}
