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
    // Default constructor
    PowerLifter() : wilksCoef(1.0), maxSquat(-1), maxBench(-1), maxDeadlift(-1) {
        strcpy(firstName, "No");
        strcpy(lastName, "Name");
    }

    // Accessor methods
    void setFirst(const char newFirst[]) {
        strcpy(firstName, newFirst);
    }

    void setLast(const char newLast[]) {
        strcpy(lastName, newLast);
    }

    void setCoef(float newCoef) {
        if (newCoef >= 0 && newCoef <= 2.0) {
            wilksCoef = newCoef;
        }
    }

    int getSquat() {
        return maxSquat;
    }

    void setSquat(int newSquat) {
        if (newSquat > -1) {
            maxSquat = newSquat;
        }
    }

    int getBench() {
        return maxBench;
    }

    void setBench(int newBench) {
        if (newBench > -1) {
            maxBench = newBench;
        }
    }

    int getDeadlift() {
        return maxDeadlift;
    }

    void setDeadlift(int newDeadlift) {
        if (newDeadlift > -1) {
            maxDeadlift = newDeadlift;
        }
    }

    int getTotal() {
        return maxSquat + maxBench + maxDeadlift;
    }

    int wilksScore() {
        return static_cast<int>(getTotal() * wilksCoef);
    }

    int compare(PowerLifter other) {
        if (wilksScore() < other.wilksScore()) {
            return -1;
        } else if (wilksScore() == other.wilksScore()) {
            return 0;
        } else {
            return 1;
        }
    }

    void display() {
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
};

void swap(PowerLifter &val1, PowerLifter &val2) {
    PowerLifter temp = val1;
    val1 = val2;
    val2 = temp;
}

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

int readFile(PowerLifter array[], const char fileName[]) {
    std::ifstream inFile(fileName);
    int count = 0;

    if (inFile.is_open()) {
        while (!inFile.eof() && count < MAX_LIFTERS) {
            char newFirst[15];
            char newLast[15];
            float newCoef;
            int newSquat;
            int newBench;
            int newDeadlift;

            inFile >> newFirst;
            inFile >> newLast;
            inFile >> newCoef;
            inFile >> newSquat;
            inFile >> newBench;
            inFile >> newDeadlift;

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