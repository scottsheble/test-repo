#include <iostream>
#include <iomanip>

using namespace std;

int cube_half( int );


int main()
{

int num, ans;

num = 4;
ans = cube_half(num);

cout << ans << "\t" << num;

cout << endl << endl;

//ans = cube_half( 10 );

//cout << ans << endl << endl;


//ans = cube_half( 27 );

//cout << ans << endl;

return 0;
}


int cube_half( int x )
{
x = x / 2;

return x * x * x;
}















