#include <iomanip>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


bool valid_sudoku(vector<vector<int>> &s)
{
    for (int i = 0; i < 9; ++i)
    {
        unordered_set<int> rowSet;
        for (int j = 0; j < 9; ++j)
        {
            if (s[i][j] != '.' && rowSet.count(s[i][j]))
                return false;
            if (s[i][j] != '.')
                rowSet.insert(s[i][j]);
        }
    }

    for (int j = 0; j < 9; ++j)
    {
        unordered_set<int> colSet;
        for (int i = 0; i < 9; ++i)
        {
            if (s[i][j] != '.' && colSet.count(s[i][j]))
                return false;
            if (s[i][j] != '.')
                colSet.insert(s[i][j]);
        }
    }

    for (int block = 0; block < 9; ++block)
    {
        unordered_set<int> subgridSet;
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; ++i)
        {
            for (int j = block % 3 * 3; j < block % 3 * 3 + 3; ++j)
            {
                if (s[i][j] != '.' && subgridSet.count(s[i][j]))
                    return false;
                if (s[i][j] != '.')
                    subgridSet.insert(s[i][j]);
            }
        }
    }

    return true;
}

// bool valid_sudoku(vector<vector<int>> &s)
// {

//     int n = 10;
//     vector<vector<int>> row(n, vector<int>(n, 0));

//     vector<vector<int>> col(n, vector<int>(n, 0));

//     vector<vector<vector<int>>> square(3, vector<vector<int>>(3, vector<int>(n, 0)));

//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (s[i][j] == 0)
//             {
//                 continue;
//             }
//             int num = s[i][j];

//             row[i][num]++;
//             col[j][num]++;
//             square[i / 3][j / 3][num]++;

//             if (row[i][num] > 1)
//             {
//                 return false;
//             }
//             if (col[i][j] > 1)
//             {
//                 return false;
//             }
//             if (square[i / 3][j / 3][num] > 1)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
