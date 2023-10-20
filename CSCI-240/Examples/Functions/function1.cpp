#include <iostream>
#include <iomanip>

using namespace std;

int cube( int );  //function prototype


int main()
{
int num, ans;

num = 2;

ans = cube(num);
cout << ans << endl;		// 8

//ans = cube(ans);
//cout << ans << endl;		// 512

//ans = cube(3);
//cout << ans << endl;		// 27

//cout << cube(ans/3) << endl;        // 729


return 0;
}//end of main



int cube( int x )    //See Note 1  -- function header
{
int result;

result = x * x * x;
  
return result;          // See Note 2
}

