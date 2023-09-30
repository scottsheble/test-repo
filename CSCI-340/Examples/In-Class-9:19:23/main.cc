#include <iostream>
#include <set>

using namespace std;

int main() 
{
    set <int> s;
    for(int i = 1; i <= 9; i++)
    {
        s.insert(i);
    }
        
    s.erase(5);
    auto it = s.begin();
    ++it;
    it = s.erase(it);
    s.erase(it, s.find(7)); //erase a sequence!
    for (it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    return 0; 

}


// Output: 1 7 8 9