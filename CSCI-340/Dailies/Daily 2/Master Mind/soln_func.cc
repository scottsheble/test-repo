#include <iostream>
#include <string>

using namespace std;

int mm_score(string, string, int&, int&);

int mm_score(string k, string g, int &b, int &w)
{
    b = 0;
    w = 0;

    if (k.size() > 0 && g.size() > 0 && k.size() != g.size())
    {
        return 0;
    }

    else 
    {
        int value1;
        int value2;

        for (unsigned int i = 0; i < k.size(); i++)
        {

        
            value1 = 0;
            value2 = 0;

            if (g[i] == k[i])
            { 
                b++;
                value1++; 
                value2++;
            }

            for (unsigned int j = 0; j < g.size(); j++)
            {
                if (g[i] == k[j] && value1 == 0 && value2 == 0)
                {
                    w++;
                    value1++;
                    value2++;
                }
            }
        
        }
    }
    return 1;
}
