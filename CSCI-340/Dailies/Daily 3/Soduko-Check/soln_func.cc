#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

bool valid_sudoku(vector<vector<int>> &s)
{

    int n = 10;
    vector<vector<int>> row(n, vector<int>(n, 0));

    vector<vector<int>> col(n, vector<int>(n, 0));

    vector<vector<vector<int>>> square(3, vector<vector<int>>(3, vector<int>(n, 0)));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s[i][j] == 0)
            {
                continue;
            }
            int num = s[i][j];

            row[i][num]++;
            col[j][num]++;
            square[i / 3][j / 3][num]++;

            if (row[i][num] > 1)
            {
                return false; 
            }
            if (col[i][j] > 1)
            {
                return false; 
            }
            if (square[i / 3][j / 3][num] > 1)
            {
                return false; 
            }
        }
    }
    return true;
}
