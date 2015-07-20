class Course;
class Student{
	int course_num;
	char* name;
	Course* course_list[5];
public:
	Student(char*);
	~Student();
	void Setname(char*);
	char* Getname();
	void Addcourse(Course&);
	float Getgrade(Course&);
	float Averagegrade();
	
};





