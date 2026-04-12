#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	string _name;
};
class Student :virtual public Person
{
protected:
	int _num; //学号
};
class Teacher : virtual public Person
{
protected:
	int _id;
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};
int main()
{
	// 编译报错：error C2385: 对“_name”的访问不明确
	Assistant a;
	a._name = "peter";
	// 需要显示指定访问哪个基类的成员可以解决二义性问题，但是数据冗余问题无法解决
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
	return 0;
}

