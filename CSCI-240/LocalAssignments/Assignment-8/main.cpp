/********************************************************
    CSCI 240        Program 8       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 11/10/23

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
 
    Created by scott sheble on 11/08/23.
*********************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date {

public:
    Date();
    Date(int newDay, string newMonth, int newYear);
    
    void set_date(int newDay, string newMonth, int newYear);
    string get_day_name();
    string get_day();
    string get_month();
    int get_year();
    string get_date();

private:
    int day, year;
    string month;

    int getMaxDays();
    int getDayIndex();
    string getSuffix();
    bool isLeapYear();
    int getMonthIndex(string monthName);
    string getDayName(int dayIndex);
};

// Array of valid month names
const string validMonths[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Array of maximum days for each month
const int maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    // Set the seed value for the random number generator
    srand(17);
    cout << endl;
    // Test 1: Constructors and get_date method
    Date date1, date2, date3(10, "December", 1815);
    cout << "Test 1: Constructors and get_date method\n\n";
    cout << "  The first date is " << date1.get_date() << endl << endl;
    cout << "  The second date is " << date2.get_date() << endl << endl;
    cout << "  The third date is " << date3.get_date() << endl << endl;

    // Test 2: set_date method
    date1.set_date(9, "December", 1906);
    cout << "\nTest 2: set_date method\n\n";
    cout << "  Grace Hopper's birthday is " << date1.get_date() << endl << endl;

    // Test 3a: set_date method with invalid values
    date2.set_date(29, "February", 2023);
    cout << "\nTest 3a: set_date method with invalid values\n\n";
    cout << "  This should print as Feb. 1st: " << date2.get_date() << endl << endl;

    // Test 3b: set_date method that tests leap year recognition
    date2.set_date(29, "February", 2020);
    cout << "\nTest 3b: set_date method that tests leap year recognition\n\n";
    cout << "  Leap Year! " << date2.get_date() << endl << endl;

    // Test 4: set_date method with a made-up month
    date3.set_date(14, "Jupiter", 1011);
    cout << "\nTest 4: set_date method with a made-up month\n\n";
    cout << "  This should default to January: " << date3.get_date() << endl << endl;

    // Test 5a: testing whether '12' comes back as '12th' and not '12nd'
    date1.set_date(12, "March", 1999);
    cout << "\nTest 5a: testing whether '12' comes back as '12th' and not '12nd'\n\n";
    cout << "  First date == " << date1.get_day() << endl << endl;

    // Test 5b: testing whether '23' comes back as '23rd' and not '23th'
    date1.set_date(23, "March", 1999);
    cout << "\nTest 5b: testing whether '23' comes back as '23rd' and not '23th'\n\n";
    cout << "  First date == " << date1.get_day() << endl << endl;

    // Test 6: testing for mapping the 26th day of the month to a Friday
    date3.set_date(26, "February", 1982);
    cout << "\nTest 6: testing for mapping the 26th day of the month to a Friday\n\n";
    cout << "  There's a 1 in 7 chance this is the actual day Brian Shaw was born... "; 
    cout << date3.get_day_name() << endl << endl;

    return 0;
}

/**
 * @brief Construct a new Date:: Date object
 * 
 */
Date::Date() {
    // Generate a random year between 1000 and 2024
    year = rand() % (2024 - 1000 + 1) + 1000;

    // Generate a random month index between 0 and 11
    int monthIndex = rand() % 12;
    month = validMonths[monthIndex];

    // Generate a random day based on the maximum days for the selected month and year
    day = rand() % maxDaysInMonth[monthIndex] + 1;
}

// Alternate constructor
/**
 * @brief Construct a new Date:: Date object
 * 
 * @param newDay 
 * @param newMonth 
 * @param newYear 
 */
Date::Date(int newDay, string newMonth, int newYear) {
    set_date(newDay, newMonth, newYear);
}

/**
 * @brief Method to set the date
 * 
 * @param newDay 
 * @param newMonth 
 * @param newYear 
 */
void Date::set_date(int newDay, string newMonth, int newYear) {
    bool validMonth = false; // Validate and Loop through each valid month name
    for (const string &validMonthName : validMonths) { 
        if (newMonth == validMonthName) {
            validMonth = true;
            break;
        }
    }
    month = validMonth ? newMonth : "January";

    // Validate and set the year
    year = (newYear >= 1000 && newYear <= 2024) ? newYear : 1999;

    // Validate and set the day
    int maxDays = getMaxDays();
    day = (newDay >= 1 && newDay <= maxDays) ? newDay : 1;
}

/**
 * @brief Accessor method to get the name of the day
 * 
 * @return string 
 */
string Date::get_day_name() {
    int dayIndex = (day % 7) - 1; // Subtracting 1 to match the array index
    if (dayIndex < 0) {
        dayIndex = 6; // Wrap around for Sunday
    }
    return getDayName(dayIndex);
}

/**
 * @brief Accessor method to get the formatted day
 * 
 * @return string 
 */
string Date::get_day() {
    return to_string(day) + getSuffix();
}

/**
 * @brief Accessor method to get the month
 * 
 * @return string 
 */
string Date::get_month() {
    return month;
}

/**
 * @brief Accessor method to get the year
 * 
 * @return int 
 */
int Date::get_year() {
    return year;
}

/**
 * @brief Accessor method to get the complete and formatted representation of the date
 * 
 * @return string 
 */
string Date::get_date() {
    return get_day_name() + " " + month + " " + get_day() + ", " + to_string(year);
}

int Date::getMaxDays() {
    int monthIndex = getMonthIndex(month);
    int maxDays = maxDaysInMonth[monthIndex];

    // Adjust for leap year
    if (monthIndex == 1 && isLeapYear()) {
        maxDays++;
    }

    return maxDays;
}

/**
 * @brief Helper method to get the day index
 * 
 * @return int 
 */
int Date::getDayIndex() {
    int a = (14 - getMonthIndex(month)) / 12;
    int y = year - a;
    int m = getMonthIndex(month) + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

/**
 * @brief Helper method to get the suffix for the day (e.g., st, nd, rd, th)
 * 
 * @return string 
 */
string Date::getSuffix() {
    if (day >= 11 && day <= 13) {
        return "th";
    }
    switch (day % 10) {
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

/**
 * @brief Helper method to check if the year is a leap year
 * 
 * @return true 
 * @return false 
 */
bool Date::isLeapYear() {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/**
 * @brief Helper method to get the index of the month
 * 
 * @param monthName 
 * @return int 
 */
int Date::getMonthIndex(string monthName) {
    for (int i = 0; i < 12; ++i) {
        if (monthName == validMonths[i]) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Function to get the name of the day for a given day index
 * 
 * @param dayIndex 
 * @return string 
 */
string Date::getDayName(int dayIndex) {
    string daysOfWeek[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    return daysOfWeek[dayIndex % 7];
};
