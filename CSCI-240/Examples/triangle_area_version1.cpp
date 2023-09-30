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
  cout << endl << endl
       << "***************" << endl
	   << "Area Calculator" << endl << endl
	   << "Base:      " << base_val << endl
	   << "Height:    " << height_val << endl << endl
	   << "Area:      " << triangle_area << endl
       << "***************" << endl << endl;
	     
  
  return 0;
  }
  
  
  
  
   ((double)sum/count)
  
  
  
  
  
  
  
  

