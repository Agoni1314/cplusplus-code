#include<iostream>
#include<vector>
#include<list>
using namespace std;

//class Person
//{
//public:
//	void identity()
//	{
//		cout << "void identity()" << _name << endl;
//	}
//protected:
//	string _name = "张三";
//	string _address; 
//	string _tel;
//	private:
//	int _age = 18; 
//};
//
//class Student : public Person
//{
//public:
//	void study()
//	{
//		
//	}
//protected:
//	int _stuid; 
//};
//class Teacher : public Person
//{
//public:
//	void teaching()
//	{
//		
//	}
//protected:
//	string title; 
//};
//
//int main()
//{
//	Student s;
//	Teacher t;
//	s.identity();
//	t.identity();
//	
//	return 0;
//}

////#define container std::vector
//#define container std::list
//namespace box
//{
//	/*template<class T>//这里写了一个box::vector会导致编译器先匹配非库中的vector，除非在应用vector加上std::
//	class vector
//	{};*/
//	
//	template<class T>
//	//class stack : public std::vector<T>//这里传list就是list，vector就是vector，就写死了，可以定义宏
//	class stack : public container<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			container<T>::push_back(x);
//			//push_back(x);和按需实例化有关
//		}
//		void pop()
//		{
//			container<T>::pop_back();
//		}
//		const T& top()
//		{
//			return container<T>::back();
//		}
//		bool empty()
//		{
//			return container<T>::empty();
//		}
//	};
//}
//int main()
//{
//	box::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; 
//	string _sex; 
//	int _age; 
//};
//class Student : public Person
//{
//public:
//	int _No; 
//	
//};
//int main()
//{
//	Student sobj;
//	// 1.派生类对象可以赋值给基类的指针/引用
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// 生类对象可以赋值给基类的对象是通过调用后面会讲解的基类的拷贝构造完成的
//	Person pobj = sobj;
//	//2.基类对象不能赋值给派生类对象，这里会编译报错
//	// sobj = pobj;
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "xiaoming";
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout <<  _name << endl;
//		cout << Person::_num << endl;
//		cout <<  _num << endl;
//	}
//protected:
//	int _num = 999; 
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//};


//A和B类中的两个func构成什么关系（）
//A.重载 B.隐藏 C.没关系
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.fun(10);
//	//b.fun();
//	return 0;
//};
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.A::fun();
//	//b.fun();
//	return 0;
//};


class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person & p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person & p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; 
};
class Student : public Person
{
public:
	//默认生成的构造函数的行为
	//1.内置类型不确定
	//2.自定义类型默认
	//3.继承父类成员看成一个整体对象，调父类的默认
	Student(const char* name, int num, const char* address)
		:Person(name)//显示调用
		,_num(num)
		,_address(address)
	{
		_ptr = new int(666);
	}
	
	//拷贝构造默认生成的就可以了
	Student(const Student& x)
	
		:_num(x._num)
		,_address(x._address)
		,Person(x)//初始化列表的初始化顺序和声明有关
		{
		  //深拷贝
		  // _ptr = new int(666);
			//浅拷贝
			_ptr = x._ptr;
		}

	//赋值重载默认生成的就可以了
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			//父类和子类的operator=构成隐藏，需要指定
			Person::operator=(s);
			_num = s._num;
			_address = s._address;
		}
		return *this;
	}

	//析构默认生成的就可以了
	//子类的析构和父类的析构构成隐藏
	~Student()
	{
		Person::~Person();
	}
	
protected:
	int _num=1; //学号
	string _address="dujiangyan";
	int* _ptr;
};
int main()
{
	Student s("xiaoming",12,"chengdu");
	Student s2(s);
	Student s3("lisi", 12, "meiguo");
	s = s3;
	return 0;
}
