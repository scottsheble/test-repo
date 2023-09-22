#include <iostream>
    #include <vector>
    using namespace std;
    int main ()
    {
        vector<int> a (3, 0);
        vector<int> b (5, 0);
        b = a;
        a = vector<int>();
        cout << "Size of a: " << int(a.size()) << ';';
        cout << "Size of b: " << int(b.size()) << '\n';
        return 0;
}