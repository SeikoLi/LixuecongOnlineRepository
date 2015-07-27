#include<stdio.h>
#include<assert.h> 
#include<iostream>
using namespace std;
int strlen_s( const char*str ) // 输入参数const
{
assert( str != NULL ); // 断言字符串地址非0
int len = 0;
while( (*str++) !='\0' ) 
{ 
len++; 
} 
return len;
}

int main(){
	char *p="Hello world";
	cout<<strlen_s(p)<<endl;
	system("pause");
}