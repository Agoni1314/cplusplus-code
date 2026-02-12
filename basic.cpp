#include<iostream>
using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//	int d = 20;
//	b = d;
//	cout << &a << endl << &b << endl << &c << endl << &d<<endl ;
//	cout << a << endl << b << endl << c << endl << d;
//	return 0;
//}

//频繁调用的短小函数可以使用内敛函数
//inline void func(int a, int b = 10)
//{
//	cout << a <<endl<< b << endl;
//}
//int main()
//{
//	//放大权限
//	const int a = 10;
//	//int& b = a;
//	const int& b = a;
//	//权限可以缩小，但不能放大,缩小的是引用的权限
//	int c = 20;
//	const int& d = c;
//	//给常量取别名要加const
//	const int& rc = 10;
//	//不是权限放大
//	int ra = a;
//	//d给int的时候会产生隐式转换，而隐式转换会产生临时对象(还有表达式相加)，把d的整数部分拿出来放在临对，ri引用临对
//	double e = 12.34;
//	int i = e;
//	const int& ri = e;
//	func(100);
//	return 0;
//}

//void func(int a)
//{
//	cout << "111" << endl;
//}
//void func(int* p)
//{
//	cout << "pointer p" << endl;
//}
//int main()
//{
//	func(100);
//	func(NULL);
//	//cpp
//	/*void* p1 = NULL;
//	int* p2 = (int*)p1;*/
//	//c
//	/*void* p1 = NULL;
//	int* p2 = p1;*/
//	func(nullptr);
//	
//	cout << "你好" << endl;
//	return 0;
//}

struct stack
{
	//class默认类是私有的，struct默认类是公有的
	void TPpop()
	{
		return ;
	}
public:
	void TTop()
	{
		return ;
	}
	void TPush()
	{
		return;
	}
private:
	int data;
	int* size;
	int* capacity;
};
int main()
{
	stack st;
	st.TPush();
	st.TPush();
	return 0;
}