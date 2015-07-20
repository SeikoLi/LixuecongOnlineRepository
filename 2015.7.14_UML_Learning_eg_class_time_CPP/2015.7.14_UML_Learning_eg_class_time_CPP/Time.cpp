#include<iostream>
#include"Time.h"

using namespace std;

Time::Time(int s,int m,int h){
	sec=s;
	min=m;
	hour=h;
}

void Time::Settime(int s,int m,int h){
	sec=s;
	min=m;
	hour=h;
}

void Time::disp(){
	cout<<hour<<":"<<min<<":"<<sec<<endl;
}

int main(){
	int s,m,h;
	cout<<"plaese input second,minute,hour"<<endl;
	cin>>s>>m>>h;
	Time time;
	time.Settime(s,m,h);
	time.disp();
	system("pause");
	return 0;
}


