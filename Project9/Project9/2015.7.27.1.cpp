#include<iostream>


void main() 
{ 
union{ /*����һ������*/ 
int i; 
struct{ /*�������ж���һ���ṹ*/ 
char first; 
char second; 
}half; 
}number; 
number.i=0x4241; /*���ϳ�Ա��ֵ*/ 
printf("%c%c\n", number.half.first, number.half.second); 
number.half.first='a'; /*�����нṹ��Ա��ֵ*/ 
number.half.second='b'; 
printf("%x\n",number.i); 
system("pause") ;
}