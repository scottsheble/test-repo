// #include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

std::vector<int> diamondsequence(std::vector<std::vector<int>> &m)
{
    int n = m.size();
    std::vector<int> sequence;

    int top = 0;
    int bottom = n - 1;
    int leftSide = 0;
    int rightSide = n - 1;

    if (n <= 2 || n % 2 == 0)
    {
        return sequence;
    }


    while (top <= bottom && leftSide <= rightSide)
    {

        for (int j = leftSide; j <= rightSide; j++)
        {
            sequence.push_back(m[top][j]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            sequence.push_back(m[i][rightSide]);
        }
        rightSide--;

        for (int j = rightSide; j >= leftSide; j--)
        {
            sequence.push_back(m[bottom][j]);
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            sequence.push_back(m[i][leftSide]);
        }
        leftSide++;
    }

    return sequence;
    
}

// vector<int> diamondsequence(vector<vector<int>> &m)
// {
//     vector<int> diamondsequence;
//     unsigned int n = m.size();

//     if (n % 2 == 0 || n != m[0].size())
//         return diamondsequence;

//     unsigned int i = 0;
//     unsigned int j = n / 2;
//     while (j < n)
//     {
//         diamondsequence.push_back(m[i][j]);
//         i++;
//         j++;
//     }
//     j -= 2;

//     while (i < n)
//     {
//         diamondsequence.push_back(m[i][j]);
//         i++;
//         j--;
//     }
//     i -= 2;

//     while (j >= 0)
//     {
//         diamondsequence.push_back(m[i][j]);
//         i--;
//         j--;
//     }
//     j += 2;

//     while (j < n / 2 && i >= 0)
//     {
//         diamondsequence.push_back(m[i][j]);
//         i--;
//         j++;
//     }

//     for (unsigned int i = 0; i < diamondsequence.size(); i++)
//     {
//         std::cout << diamondsequence[i] << " ";
//     }
//     std::cout << endl;

//     return diamondsequence;
// }
