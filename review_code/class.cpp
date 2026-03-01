#include<iostream>
using namespace std;
class A
{
public:
	//explicit A(int a=0)
	A(int a = 0)
	{
		_a1 = a;

	}
	A(const A& aa)
	{
		_a1 = aa._a1;
	}

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{
	}

		void print()
	{
		cout << _a1 << " /" << _a2 << endl;
	}
	private:
		int _a1;
		int _a2;
};
class stack
{
public:
	void push(const A& aa)
	{
		//
	}
private:
	A _arr[10];
	int _top;
};
int main()
{
	//A aa1(1);//内置类型赋值通常不产生临时对象，类类型赋值会
	//aa1.print();
	////类型转换
	//A aa2 = 2;//先用2构造一个临时对象，再拷贝构造给aa2
	//aa2.print();//拷贝构造函数被编译器优化掉
	//A& raa1 = aa2;
	//const A& raa2 = 2;
	//raa1.print();

	stack st;
	A aa3(3);
	st.push(aa3);

	st.push(3);

	//c++11
	A aa5 = {1,1};
	const A& raa6 = {2,2};
	st.push(aa5);
	st.push({3,3});
	return 0;
}

