#include<iostream>

using namespace std;

struct Node{
	int a;
	Node* next;
};

class Stack{
private:
	Node* head;
public:
	Stack(){head=NULL;}
	~Stack();
	void put(int );
	int get();
};

void Stack::put(int item)
{
  Node* p = new Node;
  p->a = item;
  p->next = head;
  head = p;
}

int Stack::get(){
	if(!head){
		cout<<"there is nothing in the Stack"<<endl;
		return 0;
	}
	int result;
	result=head->a;
	Node* t=head;
	head=head->next;
	delete t;
	return result;
}

Stack::~Stack(){
	while(head){
		Node* t;
		t=head;
		head=head->next;
		delete t;
		t=NULL;
	}
}
	


int main(){
	Stack stack;
	stack.put(10);
	stack.put(12);
	stack.put(14);

	cout<<stack.get()<<endl;
	cout<<stack.get()<<endl;
	cout<<stack.get()<<endl;
	cout<<stack.get()<<endl;
	system("pause");
	return 1;

}