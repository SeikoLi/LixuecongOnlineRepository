#include<iostream>
#include"Course.h"
#include"Student.h"

using namespace std;

int main(){
	Course math("math");
	Student Zhangsan("Zhangsan");
	Zhangsan.Addcourse(math);
	math.Setgrade(Zhangsan,3.1);
	Student Lisi("Lisi");
	Lisi.Addcourse(math);
	math.Setgrade(Lisi,4.5);
	cout<<math.Averagegrade()<<endl;
	cout<<Zhangsan.Getgrade(math)<<endl;
	system("pause");
	return 0;
}
