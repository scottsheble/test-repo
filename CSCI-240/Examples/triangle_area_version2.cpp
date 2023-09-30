/*********************************************************
Write a COMPLETE C++ program that will calculate and
display the area of a triangle.

The user should be prompted for the base and height of the
triangle.

Use the following formula to calculate the area of a triangle:

Triangle area = 1/2 * base * height



The results (**AFTER** the prompts for base and
height) should be similar to:

*************************
Area Calculator

Base:      XXXXX.XX
Height:    YYYY.YYY

Area:      ZZZ.ZZ
*************************


*********************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

#define LABEL_LENGTH 25

int main()
  {
  //step 1: create variables
  float base_val, height_val, triangle_area;
  
  //step 2: get values from the user (base, height of triangle)
  cout << "What is the length of the base of the triangle? ";
  cin >> base_val;
  
  cout << "What is the height of the triangle? ";
  cin >> height_val;
  
  //step 3: calculate area of triangle
  triangle_area = 1/2.0 * base_val * height_val;
                 //0.5
  
  //step 4: display table of results 

  cout << setprecision(4) << fixed << showpos;
  
  cout << endl << endl
       << "***************" << endl
	   << "Area Calculator" << endl << endl
	   << left << setw(LABEL_LENGTH) << "Base:" << right << setw(7) << base_val << endl
	   << left << setw(LABEL_LENGTH) << "Height:" << right << setw(7) << height_val << endl << endl
	   << left << setw(LABEL_LENGTH) << "Area:" << noshowpos << right << setw(7) << triangle_area << endl
       << "***************" << endl << endl;
	     
  
  return 0;
  }

