/********************************************************
    CSCI 240        Program 10       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 12/08/23

    Purpose: For this assignment, implement a class 
    representing a 3D vector which will make extensive 
    use of overloading class methods. This means there 
    will be multiple versions of methods defined that 
    each take different arguments. This assignment 
    rewards one for being "smart but also lazy" when 
    it comes to implementing each of these methods, 
    as they can readily use previously defined methods 
    to reduce the amount of code necessary to write to 
    complete the next one.
 
    Created by scott sheble on 12/01/23.
*********************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX_LIFTERS = 30;
const int FIELD_WIDTH = 18;
const int NUMERIC_FIELD_WIDTH = 10;
const int COEF_FIELD_WIDTH = 10;

class PowerLifter {
private:
    char firstName[15];
    char lastName[15];
    float wilksCoef;
    int maxSquat;
    int maxBench;
    int maxDeadlift;

public:
    PowerLifter();
    void setFirst(const char newFirst[]);
    void setLast(const char newLast[]);
    void setCoef(float newCoef);
    int getSquat();
    void setSquat(int newSquat);
    int getBench();
    void setBench(int newBench);
    int getDeadlift();
    void setDeadlift(int newDeadlift);
    int getTotal();
    int wilksScore();
    int compare(PowerLifter other);
    void display();
};

void sortBy(PowerLifter array[], int size, const char type[]);
void swap(PowerLifter &val1, PowerLifter &val2);
int readFile(PowerLifter array[], const char fileName[]);
void printPowerLifters(PowerLifter array[], int size, const char title[]);


int main() {
    PowerLifter lifters[MAX_LIFTERS];
    int numLifters = readFile(lifters, "lifters.txt");

    std::cout << "File processing has been complete. We have " << numLifters << " powerlifters recorded." << std::endl;

    printPowerLifters(lifters, numLifters, "Default List of Powerlifters");

    sortBy(lifters, numLifters, "Total");
    printPowerLifters(lifters, numLifters, "Powerlifters Ranked by Total");

    sortBy(lifters, numLifters, "Wilks");
    printPowerLifters(lifters, numLifters, "Powerlifters Ranked by Wilks");

    sortBy(lifters, numLifters, "Squat");
    printPowerLifters(lifters, numLifters, "Powerlifters Ranked by Squat");

    sortBy(lifters, numLifters, "Bench");
    printPowerLifters(lifters, numLifters, "Powerlifters Ranked by Bench");

    sortBy(lifters, numLifters, "Deadlift");
    printPowerLifters(lifters, numLifters, "Powerlifters Ranked by Deadlift");

    return 0;
}


// Implementation of PowerLifter member functions

/**
 * @brief Construct a new Power Lifter:: Power Lifter object. The default constructor (i.e. 
 * one that takes no arguments) should create a "No Name" powerlifter with a Wilks Coefficient 
 * of 1.0, and -1 for all their max lifts.
 * 
 */
PowerLifter::PowerLifter() : wilksCoef(1.0), maxSquat(-1), maxBench(-1), maxDeadlift(-1) {
    strcpy(firstName, "No");
    strcpy(lastName, "Name");
}

/**
 * @brief These methods will simply copy the argument value to the corresponding data member.
 * The only constraint to implement is to ensure the coefficient data member is only changed 
 * when the passed in argument value is not a negative value and not a value greater than 2.0.
 * 
 * @param newFirst 
 */
void PowerLifter::setFirst(const char newFirst[]) {
    strcpy(firstName, newFirst);
}

/**
 * @brief These methods will simply copy the argument value to the corresponding data member.
 * The only constraint to implement is to ensure the coefficient data member is only changed 
 * when the passed in argument value is not a negative value and not a value greater than 2.0.
 * 
 * @param newFirst 
 */
void PowerLifter::setLast(const char newLast[]) {
    strcpy(lastName, newLast);
}

/**
 * @brief These methods will simply copy the argument value to the corresponding data member.
 * The only constraint to implement is to ensure the coefficient data member is only changed 
 * when the passed in argument value is not a negative value and not a value greater than 2.0.
 * 
 * @param newFirst 
 */
void PowerLifter::setCoef(float newCoef) {
    if (newCoef >= 0 && newCoef <= 2.0) {
        wilksCoef = newCoef;
    }
}

/**
 * @brief This method will simply return the data member representing the max squat value for 
 * the powerlifter.
 * 
 * @return int 
 */
int PowerLifter::getSquat() {
    return maxSquat;
}

/**
 * @brief This method will update the data member representing the max squat value for the 
 * powerlifter. It takes one argument: an integer that holds the potential new max squat 
 * value. It returns nothing. The data member representing the max squat value should only be 
 * updated if the passed in value is greater than -1.
 * 
 * @param newSquat 
 */
void PowerLifter::setSquat(int newSquat) {
    if (newSquat > -1) {
        maxSquat = newSquat;
    }
}

/**
 * @brief These methods follow the same concepts as the getSquat and setSquat methods but work 
 * with the data members that represent the max bench value and max deadlift value, respectively.
 * 
 * @return int 
 */
int PowerLifter::getBench() {
    return maxBench;
}

/**
 * @brief These methods follow the same concepts as the getSquat and setSquat methods but work 
 * with the data members that represent the max bench value and max deadlift value, respectively.
 * 
 * @return int 
 */
void PowerLifter::setBench(int newBench) {
    if (newBench > -1) {
        maxBench = newBench;
    }
}

/**
 * @brief These methods follow the same concepts as the getSquat and setSquat methods but work 
 * with the data members that represent the max bench value and max deadlift value, respectively.
 * 
 * @return int 
 */
int PowerLifter::getDeadlift() {
    return maxDeadlift;
}

/**
 * @brief These methods follow the same concepts as the getSquat and setSquat methods but work 
 * with the data members that represent the max bench value and max deadlift value, respectively.
 * 
 * @return int 
 */
void PowerLifter::setDeadlift(int newDeadlift) {
    if (newDeadlift > -1) {
        maxDeadlift = newDeadlift;
    }
}

/**
 * @brief This method simply returns the sum of the three integer data members. That is: the 
 * squat, bench, and deadlift.
 * 
 * @return int 
 */
int PowerLifter::getTotal() {
    return maxSquat + maxBench + maxDeadlift;
}

/**
 * @brief This method will return the integer typecast of their Wilks Score, which by default 
 * will be a float value. A powerlifter's Wilks Score is calculated by multiplying their 
 * powerlifting total (i.e. the value returned by the method described above) by their Wilks 
 * Coefficient. For example, a powerlifter with a total equal to 2000 lbs and a Wilks 
 * Coefficient equal to 0.6 would have a Wilks Score of: Wilks Score = (2000 * 0.6) 
 * Wilks Score = 1200
 * 
 * @return int 
 */
int PowerLifter::wilksScore() {
    return static_cast<int>(getTotal() * wilksCoef);
}

/**
 * @brief This method will compare the Wilks Score of the PowerLift object that invoked this 
 * method against the PowerLifter object being passed as an argument. If the Wilks Score of 
 * the PowerLifter that invoked the method is less than the Wilks Score of the PowerLifter 
 * passed as an argument, return a value of -1. If the Wilks Scores are the same, return a 
 * value of 0. If the Wilks Score of the PowerLifter that invoked the method is greater than 
 * the Wilks Score of the PowerLifter passed as an argument, return a value of 1.
 * 
 * @param other 
 * @return int 
 */
int PowerLifter::compare(PowerLifter other) {
    if (wilksScore() < other.wilksScore()) {
        return -1;
    } else if (wilksScore() == other.wilksScore()) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * @brief This method will display a formatted PowerLifter object. It takes no arguments and 
 * returns nothing. The two name data members should be displayed in fields that are 18 
 * characters. The numeric data members, the PowerLifter's total, and the PowerLifter's Wilks 
 * Score should be displayed in fields that are 10 characters. All values should be right 
 * justified. The PowerLifter's Wilks coefficient should be displayed with exactly 4 digits 
 * after the decimal point.
 * 
 */
void PowerLifter::display() {
    std::cout << std::setw(FIELD_WIDTH) << firstName
                << std::setw(FIELD_WIDTH) << lastName
                << std::setw(COEF_FIELD_WIDTH) << std::fixed << std::setprecision(4) << wilksCoef
                << std::setw(NUMERIC_FIELD_WIDTH) << maxSquat
                << std::setw(NUMERIC_FIELD_WIDTH) << maxBench
                << std::setw(NUMERIC_FIELD_WIDTH) << maxDeadlift
                << std::setw(NUMERIC_FIELD_WIDTH) << getTotal()
                << std::setw(NUMERIC_FIELD_WIDTH) << wilksScore()
                << std::endl;
}



// Implementation of standalone functions



/**
 * @brief This function uses the Selection Sort algorithm to sort an array of PowerLifter 
 * objects in DESCENDING order. It takes three arguments: an array of PowerLifter objects to 
 * be sorted, an integer that holds how many PowerLifter objects are defined within the array, 
 * and an array of constant characters that represents which data member will be used for 
 * sorting. The primary modification that needs to be made to the provided Selection Sort 
 * algorithm discussed in class are if-statements that choose which data members will be 
 * compared, depending on the value of the third argument. They will include the string 
 * literals: Squat Bench Deadlift Total Wilks
 * For this assignment, we will assume no other value besides these five will be passed as an 
 * argument to this function.
 * 
 * @param array 
 * @param size 
 * @param type 
 */
void sortBy(PowerLifter array[], int size, const char type[]) {
    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(type, "Squat") == 0 && array[j].getSquat() > array[maxIndex].getSquat()) {
                maxIndex = j;
            } else if (strcmp(type, "Bench") == 0 && array[j].getBench() > array[maxIndex].getBench()) {
                maxIndex = j;
            } else if (strcmp(type, "Deadlift") == 0 && array[j].getDeadlift() > array[maxIndex].getDeadlift()) {
                maxIndex = j;
            } else if (strcmp(type, "Total") == 0 && array[j].getTotal() > array[maxIndex].getTotal()) {
                maxIndex = j;
            } else if (strcmp(type, "Wilks") == 0 && array[j].wilksScore() > array[maxIndex].wilksScore()) {
                maxIndex = j;
            }
        }
        swap(array[i], array[maxIndex]);
    }
}

/**
 * @brief This "helper" function is intended to facilitate the swapping process frequently 
 * done within the previous sortBy function. It takes two arguments: two references to 
 * PowerLifter objects. It returns nothing.
 * 
 * @param val1 
 * @param val2 
 */
void swap(PowerLifter &val1, PowerLifter &val2) {
    PowerLifter temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * @brief This function builds an array of PowerLifter objects from data in an input file. It 
 * takes two arguments: an array of PowerLifter objects to be filled with information and an 
 * array of constant characters that holds the name of the input file. It returns an integer: 
 * the number of PowerLifter objects that were put into the array The function should follow 
 * the basic logic that was used in the build function from program 7. The main differences 
 * are: the second argument will be used in the open() statement rather than using a string 
 * literal with the name of the file. Since the value is in a variable, no double quotes are 
 * needed. along with the subscript notation that was used in Program 7, dot notation must be 
 * used to call the PowerLifter methods that are needed to set the values
 * 
 * @param array 
 * @param fileName 
 * @return int 
 */

int readFile(PowerLifter array[], const char fileName[]) {
    std::ifstream inFile(fileName);
    int count = 0;

    if (inFile.is_open()) {
        char newFirst[15];
        char newLast[15];
        float newCoef;
        int newSquat;
        int newBench;
        int newDeadlift;

        while (count < MAX_LIFTERS && (inFile >> newFirst >> newLast >> newCoef >> newSquat >> newBench >> newDeadlift)) {
            // Set the values using the PowerLifter methods
            array[count].setFirst(newFirst);
            array[count].setLast(newLast);
            array[count].setCoef(newCoef);
            array[count].setSquat(newSquat);
            array[count].setBench(newBench);
            array[count].setDeadlift(newDeadlift);

            count++;
        }
        inFile.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }

    return count;
}

/**
 * @brief This function will print an array of PowerLifter objects in a formatted report. It 
 * takes three arguments: an array of PowerLift objects to be displayed, an integer 
 * representing how many PowerLifter objects to display, and an array of constant characters 
 * that contains the report title. It returns nothing. Remember that a PowerLifter object has 
 * a display() method that can be used to display the relevent values in the object. 
 * The sample output uses 37 spaces before printing the title. The two columns associated with 
 * the first and last names use 18 spaces while each of the columns containing numbers — both 
 * real and integer — use 10 spaces. These last two values are strongly recommended to encode 
 * as symbolic constants.
 * 
 * @param array 
 * @param size 
 * @param title 
 */
void printPowerLifters(PowerLifter array[], int size, const char title[]) {
    std::cout << std::endl << std::string(37, ' ') << title << std::endl;

    std::cout << std::setw(FIELD_WIDTH) << "First Name"
            << std::setw(FIELD_WIDTH) << "Last Name"
            << std::setw(COEF_FIELD_WIDTH) << "Wilks"
            << std::setw(NUMERIC_FIELD_WIDTH) << "Squat"
            << std::setw(NUMERIC_FIELD_WIDTH) << "Bench"
            << std::setw(NUMERIC_FIELD_WIDTH) << "DL"
            << std::setw(NUMERIC_FIELD_WIDTH) << "Total"
            << std::setw(NUMERIC_FIELD_WIDTH) << "W. Score"
            << std::endl;

    std::cout << std::setfill('-') << std::setw(FIELD_WIDTH + FIELD_WIDTH + COEF_FIELD_WIDTH +
                                                NUMERIC_FIELD_WIDTH * 5 + COEF_FIELD_WIDTH) << "" << std::setfill(' ')
            << std::endl;

    for (int i = 0; i < size; ++i) {
        array[i].display();
    }
}

