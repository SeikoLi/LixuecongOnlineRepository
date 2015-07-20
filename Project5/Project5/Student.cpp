#include<iostream>
#include"Student.h"
#include"Course.h"
using namespace std;

Student::Student(char* p){name=p;course_num=0;}
void Student::Setname(char* p){
	name=p;}
char* Student::Getname(){return name;}
void Student::Addcourse(Course& c){
	if (course_num>5)
		cout<<"you can't take course anymore"<<endl;
	else{
	course_list[course_num-1]=&c;
	course_num++;
	c.Addstudent(*this);
	}
}

float Student::Getgrade(Course& c){
	return c.Getstudentgrade(*this);}

float Student::Averagegrade(){
	int i;
	float sum,result;
	sum=result=0;
	for(i=0;i<course_num;i++)
		sum+=course_list[i]->Getstudentgrade(*this);
	result=sum/i;
	return result;
}
Student::~Student(){
	int i;
	for(i=0;i<5;i++)
		course_list[i-1]=NULL;
}



	





	