#include<iostream>
using namespace std;
struct Node
{
int data ;
Node *next ;
};
typedef struct Node Node ;
void disp(Node *p){
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
Node * ReverseList(Node *head) //Á´±íÄæÐò
{
if ( head == NULL || head->next == NULL )
return head;
Node *p1 = head ;
Node *p2 = p1->next ;
Node *p3 = p2->next ;
p1->next = NULL ;
while ( p3 != NULL )
{
p2->next = p1 ;
p1 = p2 ;
p2 = p3 ;
p3 = p3->next ;
}
p2->next = p1 ;
head = p2 ;
return head ;
}

int main(){
	int n;
	cin>>n;
	Node *head,*p;
	head=new Node;
	p=head;
	for(int i=1;i<n;i++){
		cin>>p->data;
		p->next=new Node;
		p=p->next;
	}
	cin>>p->data;
	p->next=NULL;
	disp(head);
	disp(ReverseList(head));
	system("pause");
}




