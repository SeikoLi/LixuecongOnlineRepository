
struct Node{
	char* Studentname;
	float grade;
	Node* next;
};
class Student;
class Course{
	int credies;
	int studentlimit;
	int studentnum;
	char* coursename;
	Node* studentlist;
public:
	Course(char*,int=0);
	~Course();
	int Getcredies();
	void Setcredies(int	);
	float Averagegrade();
	float Getstudentgrade(Student&);
	void Addstudent(Student&);
	void Setgrade(Student&,float);
};




