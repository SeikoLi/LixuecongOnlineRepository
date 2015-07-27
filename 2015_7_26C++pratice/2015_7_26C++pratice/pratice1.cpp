

#include<iostream>
using namespace std;

int fun(int x){
	int countx=0;
	while(x){
		countx++;
		x=x&(x-1);
	}
	return countx;
}

int main(){
	int x;
	cin>>x;
	cout<<fun(x)<<endl;
}




