#include <iostream.h>
#include <fstream.h>
#include <time.h>
#include "stdafx.h"
struct Node{
	unsigned char ch;
	int *code;
	int len;
	int weight;
	Node *l;
	Node *r;
	Node *Next;
};
//////////////////      ����������
Node* Insert(Node *Link,Node *temp)
{
	Node *p;
	p=Link;
	if (temp->weight>=Link->weight)
	{
		temp->Next=Link;
		return temp;
	}
	while (p->Next!=NULL)
	{
		if (temp->weight>=p->Next->weight)
		{
			temp->Next=p->Next;
			p->Next=temp;
			return Link;
		}
		p=p->Next;
	}
	p->Next=temp;
	return Link;
}
///////////////////// ���뺯��
void Code(Node *HT)
{
	if (HT->l!=NULL)
	{
		HT->l->len=HT->len+1;
		HT->l->code=new int[HT->l->len];
		for (int i=0;i<HT->len;i++)
			HT->l->code[i]=HT->code[i];
		HT->l->code[HT->len]=0;
		Code(HT->l);
	}
	if (HT->r!=NULL)
	{
		HT->r->len=HT->len+1;
		HT->r->code=new int[HT->r->len];
		for (int i=0;i<HT->len;i++)
			HT->r->code[i]=HT->code[i];
		HT->r->code[HT->len]=1;
		Code(HT->r);
	}
}
///////////////////////  ��8λ����ת����char�ַ�
char Tochar(int *buff)
{
	int n,i,weight;
	n=0;
	weight=1;
	for (i=7;i>=0;i--)
	{
		n+=buff[i]*weight;
		weight*=2;
	}
	return (char)n;
}
/////////////////////// ��char�ַ�ת����8λ����
void Toint(int *buff,unsigned char ch)
{
	int n=(int)ch;
	for (int i=7;i>=0;i--)
	{
		buff[i]=n%2;
		n/=2;
	}
}
//////////////////////��8λ�������
void print(int *buff)
{
	for (int i=0;i<8;i++) 
		cout<<buff[i];
}

	
int main() ///////////////////    ������
{
	////////////////////// ����ĸƵ�ʼ�¼�� int rate[256]
	int rate[256],i,j;
	unsigned char ch;
	clock_t start,end;
	for (i=0;i<256;i++)
		rate[i]=0;
	ifstream fin;
	i=0;
	fin.open("cacm.all",ios::binary);
	ch=fin.get();
	while (!fin.eof())
	//while (ch != EOF)
	{
		rate[ch]++;
		//fin.read(&ch,1);
		//cout<<ch<<endl;
		ch=fin.get();
	}
	//cout<<ch<<endl;
	fin.close();
	//for (i=0;i<256;i++) cout<<(char)i<<"    "<<rate[i]<<endl;
	//////////////////////  ����ĸƵ�ʲ�Ϊ0�Ĵ�� Node Nrate[256];���㲻Ϊ0��������Ϊnum;
	Node Nrate[256];
	int num,ptr;
	ptr=0;
	num=0;
	for (i=0;i<256;i++)
	{
		if (rate[i]!=0)
		{
			Nrate[ptr].ch=i;
			Nrate[ptr].weight=rate[i];
			num++;
			Nrate[ptr].l=NULL;
			Nrate[ptr].r=NULL;
			Nrate[ptr].Next=NULL;
			ptr++;
		}
	}
	////////////////////    ��Nrate[num]������Ƶ�ʴӴ�С����
	for (i=0;i<num-1;i++)
	{
		for (j=i+1;j<num;j++)
		{
			if (Nrate[i].weight<Nrate[j].weight)
			{
				char chtemp;
				int wtemp;
				chtemp=Nrate[i].ch;
				wtemp=Nrate[i].weight;
				Nrate[i]=Nrate[j];
				Nrate[j].ch=chtemp;
				Nrate[j].weight=wtemp;
			}
		}
	}
	///////////////////////////����Nrate[num]��������Link
	Node *Link;
	Link=&Nrate[0];
	for (i=0;i<num-1;i++)
		Nrate[i].Next=&Nrate[i+1];
    ////////////////////////// ��������Link�����շ�����HT
	int treeNum=num;
	Node *p,*one,*two,*tempNode;
	while (treeNum>2)
	{
		p=Link;
		for (i=0;i<treeNum-3;i++)
			p=p->Next;
		one=p->Next;
		two=p->Next->Next;
		tempNode=new Node;
		tempNode->weight=one->weight+two->weight;
		tempNode->l=one;
		tempNode->r=two;
		tempNode->Next=NULL;
		p->Next=NULL;
		Link=Insert(Link,tempNode);
		treeNum--;
	}
	Node *HT;
	HT=new Node;
	HT->l=Link;
	HT->r=Link->Next;
	HT->Next=NULL;
	//////////////////////////////�Ժշ��������б���
	HT->len=1;
	HT->code=new int[1];
	HT->code[0]=0;
	Code(HT);
    ////////////////////////////��������
	for (i=0;i<num;i++)
	{
		cout<<(int)Nrate[i].ch<<"     "<<Nrate[i].ch<<"     "<<Nrate[i].weight<<"     ";
		for (j=0;j<Nrate[i].len;j++)
		{
			cout<<Nrate[i].code[j];
		}
		cout<<endl;
	}
	
	///////////////////////     ���ļ�����ѹ��
	start = clock();//��ʼ����ѹ��ʱ��
	int buff[8];   // �������
	for (i=0;i<8;i++) 
		buff[i]=0;
	int bptr;      // ����ָ��
	bptr=7;
	char chOut;
	fin.open("cacm.all",ios::binary);
	ofstream fou;
	fou.open("ya.zz",ios::binary);
	
		ch=fin.get();   //����һ���ַ�
	while (!fin.eof())
	{     
		//fin.read(&ch,1);
		for (i=0;i<num;i++)
		{
			if (ch==Nrate[i].ch)   //�ҳ������ַ�����Ӧ�ı���
			{
				for (j=0;j<Nrate[i].len;j++)
				{					
					bptr=(bptr+1)%8;
					buff[bptr]=Nrate[i].code[j];
					if (bptr==7)
					{
						chOut=Tochar(buff);
						fou.write(&chOut,1);
						//print(buff);
		                //cout<<endl;
						
					}
				}
			}
		}
		ch=fin.get();
	}
	if(bptr < 7)
	{
		while(bptr < 7)
		{
			bptr++;
			buff[bptr] = 1;
			
		}
		//print(buff);
		//cout<<"endl"<<endl;
		chOut=Tochar(buff);
		fou.write(&chOut,1);
	}


	fin.close();
	fou.close();
	
	/////////////////////////////��ѹ�ļ�
	p=HT;
	int head=1;
	fin.open("ya.zz",ios::binary);
	//fin.open("ya.zz",ios::in);
	fou.open("recover.all",ios::binary);
	
	while (!fin.eof())
	{
		
		ch=fin.get();
		if(fin.eof())
		{break;}
		Toint(buff,ch);
		//cout<<endl;
		//print(buff);
		//cout<<endl;
		for (i=0;i<8;i++)
		{
			if (head==1)
			{
				if(buff[i] == 1)
					break;
				else{
					head=0;
					continue;
				}
			}
			if (buff[i]==0)
				p=p->l;
			else 
				p=p->r;
			if (p->l==NULL&&p->r==NULL)
			{
				fou.write(&p->ch,1);
				//cout<<p->ch;
				p=HT;
				head=1;
			}
		}
	}
		end=clock();

	cout<<(double)(end-start) / CLOCKS_PER_SEC <<endl;
	return 0;
}

