#include<iostream>
#include"Course.h"
#include"Student.h"

using namespace std;

Course::Course(char* p,int cred){coursename=p;credies=cred;studentlist=NULL;studentnum=0;studentlimit=30;}
int Course::Getcredies(){return credies;}
void Course::Setcredies(int a){credies=a;}
float Course::Averagegrade(){
	int i;i=0;
	Node* p;p=studentlist;
	float sum,result;sum=result=0;
	if(!p){
		cout<<"error"<<endl;
		return 0;}
	for(i=0;i<studentnum;i++)
		sum+=p->grade;
	result=sum/studentnum;
	return result;
}
float Course::Getstudentgrade(Student& s){
	int i;
	Node* p;p=studentlist;
	for(i=0;i<studentnum;i++){
		if(strcmp(s.Getname(),p->Studentname)==0)
			return p->grade;
		p=p->next;
	}
	cout<<"can't find student"<<endl;
	return 0;
}

void Course::Addstudent(Student& s){
	Node* p=new Node;
	p->Studentname=s.Getname();
	p->grade=0;
	p->next=studentlist;
	studentlist=p;
}

void Course::Setgrade(Student& s,float a){
	int i;
	Node* p;p=studentlist;
	for(i=0;i<studentnum;i++){
		if(strcmp(s.Getname(),p->Studentname)==0){
			p->grade=a;
		cout<<"scessfully"<<endl;
		exit(0);
		}
	}
}

Course::~Course(){
	int i;
	Node* p;
	for(i=0;i<studentnum;i++){
		p=studentlist;
		studentlist=studentlist->next;
		delete p;
	}
}

