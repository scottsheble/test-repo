#include <map>
#include <iostream>
using namespace std;

void print_map(const map<string, int>& myMap)
{
    for(auto mapIt = myMap.begin(); mapIt != myMap.end(); ++mapIt)
    {
        cout << mapIt->first << " : " << mapIt->second << endl;
    }
}
    
int main()
{
    map<string, int> ages;ages["John"] =38;ages["Jane"] = 3;ages["Amy"] = 4;print_map(ages);ages["John"] ++;print_map(ages);return 0;
}
