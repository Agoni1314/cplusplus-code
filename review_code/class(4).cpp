#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a1(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}
	void print()
	{
		cout << "A::print" << _a1 << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	A& operator++()
	{
		++_a1;
		return *this;
	}
private:
	int _a1 = 1; 
};
void f1(A aa)
{
}
//A f2()
//{
//	A aa=3;//构造
//	return aa;//传值传参返回会产生临时对象,这里的临时对象会调用析构，但被编译器优化掉
//}
//A f2()
//{
//	A aa = 3;
//	++aa;
//	return aa;
//}
A f2()
{
	A aa = 3;
	return aa;
}
int main()
{
	/*A aa = 1;
	const A& aa2 = 1;*/
	/*A aa1;
	f1(aa1);*/
	/*A aa1(1);
	f1(aa1);//有名
	cout << endl;
	f1(A(1));//匿名
	cout << endl;
	f1(1);
	cout << endl;*/
	/*f2().print();
	cout << endl;*/
	/*A ret = f2();
	ret.print();
	cout << endl;*/
	A ret;
	ret = f2();
	ret.print();
	cout << endl;
	return 0;
}