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
#include <iostream>
#include <string>

using namespace std;

//prototypes
int Menu(); 
int getValue( string prompt, int lowerBound, int upperBound ); 
int sumOfSquares( int limit ); 
double averageOfCubes( int limit );
int sumOfASCII( int limit ); 
void NIUchant( int iterations );


int main() {
    int choice;

    do {
        choice = Menu(); // Display menu and get user's choice.

        if (choice == 1) {
            int limit = getValue("How many squares will we summate?", 2, 20);
            int result = sumOfSquares(limit);
            cout << "The sum of the first " << limit << " positive numbers squared is " << result << endl;
        } else if (choice == 2) {
            int limit = getValue("How many cubes will we average?", 2, 20);
            double result = averageOfCubes(limit);
            cout << "The average of the first " << limit << " positive numbers cubed is " << result << endl;
        } else if (choice == 3) {
            int limit = getValue("How many ASCII values will we summate?", 1, 26);
            char charChoice;
            cout << "Would you like to summate (L)owercase or (U)ppercase characters? ";
            cin >> charChoice;
            int result = 0;

            if (charChoice == 'L' || charChoice == 'l') {
                result = sumOfASCII(limit);
                cout << "The sum of the first " << limit << " ASCII character values is " << result << endl;
            } else if (charChoice == 'U' || charChoice == 'u') {
                result = sumOfASCII(limit);
                cout << "The sum of the first " << limit << " uppercase ASCII character values is " << result << endl;
            } else {
                cout << "Invalid choice. Please enter 'L' for lowercase or 'U' for uppercase characters." << endl;
            }
        } else if (choice == 4) {
            int iterations = getValue("How many words will be iterated from the NIU Chant?", 3, 50);
            NIUchant(iterations);
        } else if (choice == 5) {
            cout << "Ending program..." << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}

/**
 * @brief This function displays a menu and gets a choice from 
 * the user.
 * 
 * @return int 
 */
int Menu()
{
    int choice;
    bool viableChoice = false; //boolean for determining if user choice is viable.

    do {

        std::cout << "Objectives" << "\n\n";
        std::cout << "1) Calculate the sum of the first N squared numbers" << std::endl;
        std::cout << "2) Calculate the average of the first N cubed numbers" << std::endl;
        std::cout << "3) Calculate the sum of the ASCII value of the first N characters" << std::endl;
        std::cout << "4) Word iterations from the NIU school chant." << std::endl << std::endl;
        std::cout << "5) Quit" << "\n\n";
        std::cout << "Enter your choice: "; 
        std::cin >> choice; //user choice for menu option.
        std::cout << "\n\n";

        if (choice < 1 || choice > 5) 
        {
            std::cin.clear();
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        } else {
            viableChoice = true;
        }
    } while (!viableChoice);
        
    return choice; //returns user's choice.
}
    
/**
 * @brief Get the Value object. This function will get an 
 * integer value from the user that is within a specified 
 * range.
 * 
 * @param prompt 
 * @param lowerBound 
 * @param upperBound 
 * @return int 
 */
int getValue(string prompt, int lowerBound, int upperBound)
{
    int value;
    bool validValue = false; //check if value is valid.

    do {
        // displays prompt and range.
        std::cout << prompt << " (" << lowerBound << " - " << upperBound << "): ";
        std::cin >> value;

        // check for valid input.
        if (value < lowerBound || value > upperBound) 
        {
            std::cin.clear();
            std::cout << "Invalid value. Please enter a number within the specified range." << std::endl;
        } else {
            validValue = true;
        }
    } while (!validValue);

    return value;
}

/**
 * @brief This function will summate all the squares of 
 * positive integers between 1 and limit (inclusive), and 
 * return that sum.
 * 
 * @param limit 
 * @return int 
 */
int sumOfSquares(int limit)
{
    int sum = 0;

    for (int i = 1; i <= limit; i++) 
    {
        sum += i * i;
    }

    return sum;
}


/**
 * @brief This function will calculate the average of all the 
 * cubes of 'limit' number of integers, starting with 0, and 
 * return that value.
 * 
 * @param limit 
 * @return double 
 */
double averageOfCubes(int limit)
{
    double sum = 0.0;

    for (int i = 0; i < limit; i++) 
    {
        sum += (i * i * i);
    }

    return (sum / (limit)); //returns average of cubes. 
}

/**
 * @brief This function will calculate the sum of the ASCII 
 * values of the first N characters starting with 'a' or 'A', 
 * and return that sum.
 * 
 * @param limit 
 * @return int 
 */
int sumOfASCII(int limit)
{
    char startingChar; //starting character for static_cast loop.
    int sum = 0;

    // calculate sum of ASCII values by static_cast.
    for (char i = startingChar; i < startingChar + limit; i++) 
    {
        sum += static_cast<int>(i); //type conversion to int.
    }

    return sum;
}

/**
 * @brief This function will display an iterations number of 
 * words from the NIU school chant: Forward! Together, 
 * Forward! Make sure to include spaces after each word or 
 * token, as well as two (2) newline characters once the list 
 * of words has finished printing.
 * 
 * @param iterations 
 */
void NIUchant(int iterations)
{
    std::string chant = "Forward! Together, Forward!";
    int chantLength = chant.length();

    // display number of iterations specified.
    for (int i = 0; i < iterations; i++) 
    {
        int startIndex = i * chantLength;
        int endIndex = startIndex + chantLength;

        if (endIndex > chantLength) 
        {
            // wrap back to startIndex if end of chant.
            startIndex = startIndex % chantLength;
            endIndex = chantLength;
        }

        std::string word = chant.substr(startIndex, endIndex - startIndex);

        std::cout << word;

        // adding space after each word/token.
        if (i < iterations - 1) 
        {
            std::cout << " ";
        }
    }

    std::cout << std::endl << std::endl; // adding 2 newlines at end of chant.
}


















