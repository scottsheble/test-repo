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

int main()
{
    //srand(17);
    //srand(time(0));
    //num = rand();
    //num = rand();
    //srand(17);
    srand(17);

    for (int i = 0; i <=52; i++) {
        std::cout << 1 + rand() % 100 << " ";
        if ((i % 6 == 0) && i != 0){
            std::cout << std::endl;
        }


    }




    return 0;
}
