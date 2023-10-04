
#include <iostream>
#include <iomanip>
#include <vector>

int findmiddle(std::vector<std::vector<int>>& vecs, int& p) {
    int S = 0;
    for (const std::vector<int>& vec : vecs) {
        S += vec.size();
    }
    if (S % 2 == 0) {
        return 0;  
    }


    int middle = S / 2;
    int currentLength = 0;

    for (const std::vector<int>& vec : vecs) {
        int vecSize = vec.size();
        if (currentLength + vecSize > middle) {
            p = vec[middle - currentLength];
            return 1;
        }
        currentLength += vecSize;
    }

    return 0; 
}


