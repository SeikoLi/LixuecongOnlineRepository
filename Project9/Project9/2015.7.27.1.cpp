#include<iostream>


void main() 
{ 
union{ /*定义一个联合*/ 
int i; 
struct{ /*在联合中定义一个结构*/ 
char first; 
char second; 
}half; 
}number; 
number.i=0x4241; /*联合成员赋值*/ 
printf("%c%c\n", number.half.first, number.half.second); 
number.half.first='a'; /*联合中结构成员赋值*/ 
number.half.second='b'; 
printf("%x\n",number.i); 
system("pause") ;
}