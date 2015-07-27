#include<iostream>
using namespace std;
struct node { char val; node* next;};
bool check( node* head); //return false : 无环；true: 有环一种O（n）的办法就是（搞两个指针，一个每次递增一步，一个每次递增两步，如果有环的话两者必然重合，反之亦然）：
bool check( node* head)  //参数改为const会报错下面第三行报错；
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


