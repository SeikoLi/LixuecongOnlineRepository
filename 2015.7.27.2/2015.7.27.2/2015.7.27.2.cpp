#include<iostream>
using namespace std;

class String
{
public:
	String(const char *str = NULL) {  
		if (str == NULL){  
        m_data = new char[1];  
        *m_data='\0';  
    }else{  
        int len=strlen(str);  
        m_data = new char[len+1];  
        strcpy(m_data,str);      
    }  }
		// 通用构造函数
	String(const String &another){ char* m_data = new char[sizeof(another) + 1];strcpy(m_data,another.m_data);}// 拷贝构造函数//这里讲strcpy换成while循环不能通过编译
	~String(){delete [] m_data; }// 析构函数
	String& operator = (const String &another){
    if (this == &another)  
        return *this;  
  
    delete [] m_data;  
  
    int len = strlen(another.m_data);  
    m_data = new char[len+1];  
    strcpy(m_data,another.m_data);  
  
    return *this;  
}   // 赋值函数
	void disp(){cout<<m_data<<endl;}
private:
    char* m_data; // 用于保存字符串
};

int main(){
	String s1,s2("i am s2");
	s1.disp();
	s2.disp();
	s1=s2;
	s1.disp();
	system("pause");
}
	

