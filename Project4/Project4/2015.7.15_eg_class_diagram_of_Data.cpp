#include<iostream>

using namespace std;

class Data{
private:
	int day;
	int month;
	int year;
public:
	Data(int d=0,int m=0,int y=0){day=d;month=m;year=y;}
	void disp();
	void new_day();
	void set_day(int,int,int);
	int checkDate(Data date);
	
};

int Data::checkDate(Data date)
{
 int flag=date.year %400==0 ||(date.year %4==0 && date.year %100!=0);
 if(date.year<=0 || date.month<=0 || date.day <=0)
  return 0;
 if(((date.month==1 || date.month==3 || date.month==5 ||date.month==7 ||date.month==8 ||date.month==10 ||date.month==12)&&date.day<=31)
    ||((date.month==4 ||date.month==6 ||date.month==9 ||date.month==11) && date.day<=30)
    ||(flag==1 && date.month==2 && date.day<=29)
    ||(flag==0 && date.month==2 && date.day<=28))
    return 1;
 else
  return 0;
}

void Data::set_day(int d,int m,int y){
	Data a(d,m,y);
	if(checkDate(a)){
	day=d;
	month=m;
	year=y;}
	else
	{
		cout<<"error input"<<endl;
	}
}
void Data::new_day(){
	int flag=year %400==0 ||(year %4==0 && year %100!=0);
	if(((month==1 || month==3 || month==5 ||month==7 ||month==8 ||month==10 ||month==12)&&day==31)
		||((month==4 ||month==6 ||month==9 ||month==11) && day==30)
		||(flag==1 && month==2 && day==29)
		||(flag==0 && month==2 && day==29))
	{
		day=1;
		month++;}
	else
		day++;

	if(month==13)
	{month=1;
	year++;}
}

void Data::disp(){
	cout<<day<<"/"<<month<<"/"<<year<<endl;
}


	
int main(){
	cout<<"please input day,month,year"<<endl;
	int d,m,y;
	cin>>d>>m>>y;
	Data data;
	data.set_day(d,m,y);
	data.disp();
	data.new_day();
	data.disp();
	system("pause");
	return 0;
}
