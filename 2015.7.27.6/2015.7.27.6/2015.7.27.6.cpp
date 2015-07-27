#include<iostream>
using namespace std;

const int MINNUMBER =-32767 ;
int find_sec_max( int data[] , int count)
{
int maxnumber = data[0] ;
int sec_max = MINNUMBER ;
for ( int i =1 ; i < count ; i++)
{
if ( data[i] > maxnumber )
{
sec_max = maxnumber ;
maxnumber = data[i] ;
}
else
{
if ( data[i] > sec_max )
sec_max = data[i] ;
}
}
return sec_max ;
}

int main(){
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<find_sec_max(a,n)<<endl;
	system("pause");
	return 0;
}

