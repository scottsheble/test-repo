#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string decimal_to_roman(int dec)
{
    string result;
    
    if(dec >= 1000)
    {
        int t = dec/1000;
    
        //for(t; t != 0; t--)
        while(t!=0)
        {
            result.append("M") ;
            
            dec -= 1000;
            t--;
        }
    }
    
    if(dec >= 100)
    {
        int t = dec/100;
    
        if(t == 9)
        {
            result.append("CM");
            dec -=900;
        }
        else if(t == 5)
        {
            result.append("D");
            dec-=500;
        }
        else if(t > 5)
        {
            result.append("D");
            dec-=500;
            
            //for(t; t != 5; t--)
            while(t!=5)
            {
                result.append("C");
                dec-=100;
                t--;
            }
        }
        else if(t == 4)
        {
            result.append("CD");
            dec-=400;
        }
        else
        {
            //for(t; t!=0; t--)
            while(t!=0)
            {
                result.append("C");
                dec-=100;
                t--;
            }
                
        }
    }
    
    if(dec >= 10)
    {
        int t = dec/10;
    
        if(t == 9)
        {
            result.append("XC");
            dec -=90;
        }
        else if(t == 5)
        {
            result.append("L");
            dec-=50;
        }
        else if(t > 5)
        {
            result.append("L");
            dec-=50;
            
            //for(t; t != 5; t--)
            while(t!=5)
            {
                result.append("X");
                dec-=10;
                t--;
            }
                    
        }
        else if(t == 4)
        {
            result.append("XL");
            dec-=40;
        }
        else
        {
            //for(t; t!=0; t--)
            while(t!=0)
            {
                result.append("X");
                dec-=10;
                t--;
            }
                
        }
    }

    if(dec >= 1)
    {
        int t = dec;
    
        if(t == 9)
        {
            result.append("IX");
            dec -=9;
        }
        else if(t == 5)
        {
            result.append("V");
            dec-=5;
        }
        else if(t > 5)
        {
            result.append("V");
            dec-=5;
            
            //for(t; t != 5; t--)
            while(t!=5)
            {
                result.append("I");
                dec-=1;
                t--;
            }
                    
        }
        else if(t == 4)
        {
            result.append("IV");
            dec-=4;
        }
        else
        {
            //for(t; t!=0; t--)
            while(t!=0)
            {
                t--;
                result.append("I");
                dec-=1;
            }
                
        }
    }

    
    return result;
        
}
