#include<iostream>
using namespace std;
class A
{
public:
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A(int a1 = 0, int a2 = 0)" << endl;
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

	~A()
	{
		//delete _ptr;
		cout << "~A()" << endl;
	}
	 
	void Print()
	{
		cout << "A::Print->" << _a1 << endl;
	}

	A& operator++()
	{
		_a1 += 100;

		return *this;
	}
private:
	int _a1 = 1;
	int _a2 = 1;
};

//int main()
//{
//	A* p1 = new A(1);
//	delete p1;
//
//	int* p1 = new int;
//	free(p1);
//	delete p1;
//
//
//	return 0;
//}

class B
{
public:
private:
	int _b1 = 1;
	int _b2 = 2;
};
int main()
{
	//int* p1 = new int[10];
	////delete p1;
	//free(p1);
	
	B* p2 = new B[10];//B没有析构函数，因为B没有资源，编译器就优化了
	

	A* p3 = new A[10];//崩溃 
	delete p2;
	delete p3;
	return 0;
}


