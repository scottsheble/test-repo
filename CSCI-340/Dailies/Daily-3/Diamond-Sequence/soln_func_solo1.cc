// #include <bits/stdc++.h>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;


vector<int> diamondsequence(vector<vector<int>> &m)
{
    vector<int> diamondsequence;
    unsigned int n = m.size();

    if (n % 2 == 0 || n != m[0].size())
        return diamondsequence;


    unsigned int i = 0;
    unsigned int j = n / 2;
    while (j < n)
    {
        diamondsequence.push_back(m[i][j]);
        i++;
        j++;
    }
    j -= 2;

    while (i < n)
    {
        diamondsequence.push_back(m[i][j]);
        i++;
        j--;
    }
    i -= 2;

    while (j >= 0)
    {
        diamondsequence.push_back(m[i][j]);
        i--;
        j--;
    }
    j += 2;

    while (j < n / 2 && i >= 0)
    {
        diamondsequence.push_back(m[i][j]);
        i--;
        j++;
    }

    for (unsigned int i = 0; i < diamondsequence.size(); i++)
    {
        std::cout << diamondsequence[i] << " ";
    }
    std::cout << endl;

    return diamondsequence;
}
