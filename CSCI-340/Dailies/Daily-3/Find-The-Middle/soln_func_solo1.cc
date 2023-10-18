#include <vector>
#include <iostream>
#include <iomanip>


int findmiddle(std::vector<std::vector<int>> &vecs, int &p) {
    int S = 0;
    for (const auto &vec : vecs) {
        S += vec.size();
    }
    if (S == 0) {
        return 0;
    }
    unsigned int middle = S / 2;
    unsigned int count = 0;
    for (const auto &vec : vecs) {
        if (count + vec.size() > middle) {
            p = vec[middle - count];
            break;
        }
        count += vec.size();
    }
    return S % 2 == 1 ? 1 : 0;
    
}