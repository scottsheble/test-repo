/********************************************************
    CSCI 240        Program 3       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 10/20/23

    Purpose: For this assignment, the focus will be on 
    writing and calling functions. The functions will be 
    used to write a program that completes a series of 
    computation exercises. A menu of different options 
    will be shown to a user at the beginning of the 
    program (and again after each function's objective 
    has been concluded). The user will select an option 
    and the program will then prompt for additional 
    information that is specific to that option. 
    This process will continue until the user decides 
    to quit.

    Created by scott sheble on 10/01/23.
*********************************************************/
using namespace std;

//prototypes
int Menu(); 
int getValue( string prompt, int lowerBound, int upperBound ); 
int sumOfSquares( int limit ); 
double averageOfCubes( int limit );
int sumOfASCII( int limit ); 
void NIUchant( int iterations );



int main()
{
    std::cout << "Objectives" << std::endl << std::endl;
    std::cout << "1) Calculate the sum of the first N squared numbers" << std::endl;
    std::cout << "2) Calculate the average of the first N cubed numbers" << std::endl;
    std::cout << "3) Calculate the sum of the ASCII value of the first N characters" << std::endl;
    std::cout << "4) Word iterations from the NIU school chant." << std::endl << std::endl;
    std::cout << "5) Quit" << std::endl;
    std::cout << "Enter your choice:" << std::endl;




return 0;
}



/**
 * @brief This function displays a menu and gets a choice from the user.
 * 
 * @return int 
 */
int Menu()
{
    return 0;
}

/**
 * @brief Get the Value object. This function will get an integer value from the user that is within a specified range.
 * 
 * @param prompt 
 * @param lowerBound 
 * @param upperBound 
 * @return int 
 */
int getValue(string prompt, int lowerBound, int upperBound)
{
    return 0;
}

/**
 * @brief This function will summate all the squares of positive integers between 1 and limit (inclusive), and return that sum.
 * 
 * @param limit 
 * @return int 
 */
int sumOfSquares(int limit)
{
    return 0;
}

/**
 * @brief This function will calculate the average of all the cubes of 'limit' number of integers, starting with 0, and return that value.
 * 
 * @param limit 
 * @return double 
 */
double averageOfCubes(int limit)
{
    return 0.0;
}

/**
 * @brief This function will calculate the sum of the ASCII values of the first N characters starting with 'a' or 'A', and return that sum.
 * 
 * @param limit 
 * @return int 
 */
int sumOfASCII(int limit)
{
    return 0;
}

/**
 * @brief This function will display an iterations number of words from the NIU school chant: Forward! Together, Forward! Make sure to include spaces after each word or token, as well as two (2) newline characters once the list of words has finished printing.
 * 
 * @param iterations 
 */
void NIUchant(int iterations)
{

}


















