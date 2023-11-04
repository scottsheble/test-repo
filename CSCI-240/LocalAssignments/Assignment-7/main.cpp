/********************************************************
    CSCI 240        Program 7       Fall 2023

    Programmer: Scott Sheble

    Section: 1

    Date Due: 10/27/23

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

    Created by scott sheble on 10/27/23.
*********************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_CROPS = 30;
const int COLUMN_WIDTH = 16;

// Function prototypes
int build(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[]);
void print(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[], int num_of_crops);
void sort(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[], int num_of_crops);
double calculateProfit(int seedCost, int sellValue, int harvestTime);

int main() {
    // Arrays to store crop data
    string season[MAX_CROPS];
    string name[MAX_CROPS];
    int seed_cost[MAX_CROPS];
    int sell_value[MAX_CROPS];
    int harvest_time[MAX_CROPS];

    // Read crop data from a file into arrays
    int num_of_crops = build(season, name, seed_cost, sell_value, harvest_time);

    // Display the initial "Gold Profit Per Day Report for All Crops"
    cout << "Gold Profit Per Day Report for All Crops" << endl;
    print(season, name, seed_cost, sell_value, harvest_time, num_of_crops);

    // Sort the crops based on profit per day
    sort(season, name, seed_cost, sell_value, harvest_time, num_of_crops);

    // Display the sorted "Gold Profit Per Day Report for All Crops"
    cout << "Gold Profit Per Day Report for All Crops (sorted)" << endl;
    print(season, name, seed_cost, sell_value, harvest_time, num_of_crops);

    // Let the user choose a season and enter investment details
    int daysLeft, tilledLand;
    string userSeason;

    // Display a menu for season selection
    cout << "\nSeasons\n1) Spring\n2) Summer\n3) Fall\n";
    cout << "Enter your choice (1 - 3): ";
    int seasonChoice;
    cin >> seasonChoice;

    // Map user's choice to a season
    switch (seasonChoice) {
        case 1:
            userSeason = "Spring";
            break;
        case 2:
            userSeason = "Summer";
            break;
        case 3:
            userSeason = "Fall";
            break;
        default:
            cout << "Invalid season choice." << endl;
            return 1;
    }

    // Get user's investment and other details
    cout << "How much gold are you investing? (0 - 100000): ";
    int userInvestment;
    cin >> userInvestment;

    cout << "How many days are left in this season for crops to mature? (1 - 27): ";
    cin >> daysLeft;

    cout << "How much tilled farmland is available to use? (0 - 128): ";
    cin >> tilledLand;

    int totalProfit = 0;
    int remainingInvestment = userInvestment;

    // Calculate profit based on user's investment and the chosen season
    for (int i = 0; i < num_of_crops; i++) {
        if (season[i] == userSeason && harvest_time[i] <= daysLeft) {
            int seedsToBuy = min(tilledLand, remainingInvestment / seed_cost[i]);
            remainingInvestment -= seedsToBuy * seed_cost[i];
            daysLeft -= harvest_time[i];
            tilledLand -= seedsToBuy;
            double cropProfit = calculateProfit(seed_cost[i], sell_value[i], harvest_time[i]);
            totalProfit += seedsToBuy * cropProfit;

            // Display purchase details for the user
            cout << "Purchase " << seedsToBuy << " " << name[i] << " seeds, ";
            cout << "at the cost of " << seedsToBuy * seed_cost[i] << " gold, ";
            cout << "which will yield " << fixed << setprecision(2) << cropProfit * seedsToBuy << " gold in profit after ";
            cout << harvest_time[i] << " days." << endl;
        }
    }

    // Display the total profit
    cout << "Total profit: " << fixed << totalProfit << " gold." << endl;

    return 0;
}

/**
 * @brief This function will fill the five arrays with the values predefined within the
 * crops.txt input file described above. It returns an integer that is the number of crops
 * read from the input file. Note about the return value: this value is important because
 * it will be smaller than the maximum capacity of the arrays passed. The function should
 * start by declaring any variables that are needed. At a minimum, there should be a string
 * variable to capture incoming string values, an integer to hold the incoming integer
 * values, a second integer variable used to index each of the five arrays, and an input
 * file stream.
 *
 * @param season
 * @param name
 * @param seed_cost
 * @param sell_value
 * @param harvest_time
 * @return int
 */
int build(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[]) {
    // Function to read crop data from a file
    ifstream infile;
    infile.open("crops.txt");

    if (infile.fail()) {
        cout << "crops.txt input file did not open" << endl;
        exit(-1);
    }

    int index = 0;

    while (infile) {
        infile >> season[index];
        infile >> name[index];
        infile >> seed_cost[index];
        infile >> sell_value[index];
        infile >> harvest_time[index];
        index++;
    }

    infile.close();

    return index - 1;
}

/**
 * @brief This function will display the information for all of the crops. It takes as its
 * arguments the array of strings that holds the seasons, the array of strings that holds
 * the crop names, the array of integers that holds the cost of this crop's seed, the array
 * of integers that holds the resale value of the matured crop, the array of integers that
 * holds the number of days required for the crop to mature, and an integer that holds the
 * number of crops that were defined from the input file.
 *
 * @param season
 * @param name
 * @param seed_cost
 * @param sell_value
 * @param harvest_time
 * @param num_of_crops
 */
void print(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[], int num_of_crops) {
    // Function to print the crop data
    cout << setw(90) << "Gold Profit Per Day Report for All Crops" << endl;
    cout << setw(COLUMN_WIDTH) << "Season";
    cout << setw(COLUMN_WIDTH) << "Crop Name";
    cout << setw(COLUMN_WIDTH) << "Seed Cost";
    cout << setw(COLUMN_WIDTH) << "Sell Value";
    cout << setw(COLUMN_WIDTH) << "Harvest Time";
    cout << setw(COLUMN_WIDTH) << "Gold Profit/Day" << endl;
    cout << string(COLUMN_WIDTH * 6, '-') << endl;

    for (int i = 0; i < num_of_crops; i++) {
        double profitPerDay = calculateProfit(seed_cost[i], sell_value[i], harvest_time[i]);
        cout << setw(COLUMN_WIDTH) << season[i];
        cout << setw(COLUMN_WIDTH) << name[i];
        cout << setw(COLUMN_WIDTH) << seed_cost[i];
        cout << setw(COLUMN_WIDTH) << sell_value[i];
        cout << setw(COLUMN_WIDTH) << harvest_time[i];
        cout << fixed << setprecision(2) << setw(COLUMN_WIDTH) << profitPerDay << endl;
    }
    cout << string(COLUMN_WIDTH * 6, '-') << endl;
}

/**
 * @brief This function will sort the arrays in DESCENDING order based on the gold profit
 * per day of each crop. Use the selection sort algorithm presented in lecture. The
 * arguments list here is exactly the same as with void print described above.
 *
 * @param season
 * @param name
 * @param seed_cost
 * @param sell_value
 * @param harvest_time
 * @param num_of_crops
 */
void sort(string season[], string name[], int seed_cost[], int sell_value[], int harvest_time[], int num_of_crops) {
    // Function to sort crops based on profit per day
    for (int i = 0; i < num_of_crops - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < num_of_crops; j++) {
            if (calculateProfit(seed_cost[j], sell_value[j], harvest_time[j]) >
                calculateProfit(seed_cost[maxIndex], sell_value[maxIndex], harvest_time[maxIndex])) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            // Swap the elements to sort the array
            swap(season[i], season[maxIndex]);
            swap(name[i], name[maxIndex]);
            swap(seed_cost[i], seed_cost[maxIndex]);
            swap(sell_value[i], sell_value[maxIndex]);
            swap(harvest_time[i], harvest_time[maxIndex]);
        }
    }
}

/**
 * @brief Function to calculate profit per day.
 *
 * @param seedCost
 * @param sellValue
 * @param harvestTime
 * @return double
 */
double calculateProfit(int seedCost, int sellValue, int harvestTime) {
    // Calculate profit as (sellValue - seedCost) / harvestTime
    double profit = static_cast<double>(sellValue - seedCost) / harvestTime;
    return profit;
}