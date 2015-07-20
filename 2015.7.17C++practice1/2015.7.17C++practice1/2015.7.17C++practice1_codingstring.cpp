#include<iostream> 
using namespace std;

int main(){
	int a=0,b=1,c,i=1;
	while(i<=20)
	{
		if(i==1){
			cout<<a<<endl;
			i++;}
		if(i==2){
			cout<<b<<endl;
			i++;}
		if(i>2){
			c=a+b;
			cout<<c<<endl;
			a=b;b=c;
			i++;
		}
	}


system("pause");
}