#include<iostream>
#include<string>
using namespace std;
int fn1()
{
printf( "next.\n" );
return 0;
}
int fn2()
{
printf( "executed " );
return 0;
}
int fn3()
{
printf( "is " );
return 0;
}
int fn4()
{
printf( "This " );
return 0;
}
void main( void )
{
 string str("zhanglin");
_onexit( fn1 );
_onexit( fn2 );
_onexit( fn3 );
_onexit( fn4 );
printf( "This is executed first.\n" );
system("pause");
}
