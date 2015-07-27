#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void Order(vector<int> &data){         
int count = data.size() ;
int tag =false ; // 设置是否需要继续冒泡的标志位
for ( int i =0 ; i < count ; i++)
{
for ( int j =0 ; j < count - i -1 ; j++)
{
if ( data[j] > data[j+1])
{
tag =true ;
int temp = data[j] ;
data[j] = data[j+1] ;
data[j+1] = temp ;
}
}
if ( !tag )
break ;
}
}

void main( void )
{
vector<int>data;
ifstream in("c:\\data.txt");
if ( !in)
{
cout<<"file error!";
system("pause");
exit(1);
}
int temp;
while (!in.eof())
{
in>>temp;
data.push_back(temp);
}
in.close(); //关闭输入文件流
Order(data);
ofstream out("c:\\result.txt");
if ( !out)
{
cout<<"file error!";
system("pause");
exit(1);
}
for (int i=0;i < data.size();i++)
out<<data[i]<<"";
system("pause");
out.close(); //关闭输出文件流
system("pause");

}