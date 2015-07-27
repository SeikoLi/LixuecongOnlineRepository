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
		// ͨ�ù��캯��
	String(const String &another){ char* m_data = new char[sizeof(another) + 1];strcpy(m_data,another.m_data);}// �������캯��//���ｲstrcpy����whileѭ������ͨ������
	~String(){delete [] m_data; }// ��������
	String& operator = (const String &another){
    if (this == &another)  
        return *this;  
  
    delete [] m_data;  
  
    int len = strlen(another.m_data);  
    m_data = new char[len+1];  
    strcpy(m_data,another.m_data);  
  
    return *this;  
}   // ��ֵ����
	void disp(){cout<<m_data<<endl;}
private:
    char* m_data; // ���ڱ����ַ���
};

int main(){
	String s1,s2("i am s2");
	s1.disp();
	s2.disp();
	s1=s2;
	s1.disp();
	system("pause");
}
	

