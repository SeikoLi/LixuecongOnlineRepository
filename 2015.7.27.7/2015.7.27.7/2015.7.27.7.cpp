#include<iostream>
using namespace std;
struct node { char val; node* next;};
bool check( node* head); //return false : �޻���true: �л�һ��O��n���İ취���ǣ�������ָ�룬һ��ÿ�ε���һ����һ��ÿ�ε�������������л��Ļ����߱�Ȼ�غϣ���֮��Ȼ����
bool check( node* head)  //������Ϊconst�ᱨ����������б���
{
if(head==NULL) return false;
node *low=head, *fast=head->next;
while(fast!=NULL && fast->next!=NULL)
{
low=low->next;
fast=fast->next->next;
if(low==fast) return true;
}
return false;
}


