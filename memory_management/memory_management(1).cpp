#include<iostream>
//int main()
//{
//	int* p1 = new int;
//	int* p2 = new int[10];
//	delete p1;
//	delete[]p2;
//	//申请对象+初始化
//	int* p3 = new int(0);
//	int* p4 = new int[10] {0};
//	int* p5 = new int[10] {1, 2};
//	delete p3;
//	delete[]p4;
//	delete[]p5;
//	return 0;
//}

//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//};
//void f1(A aa)
//{
//}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new A(1);
//	delete p1;//调用构造和析构后才销毁
//	delete p2;
//	return 0;
//}

//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int x)
//		:val(x)
//		,next(nullptr)
//	{ }
//};
//int main()
//{
//	ListNode* n1 = new ListNode(1);//new就自动调用构造函数，delete就自动调用析构函数
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//
//	return 0;
//}

//using namespace std;
//class A
//{
//public:
//	A(int a , int a2 = 0)
//		:_a1(a)
//		,_a2(a2)
//	{
//		cout << "int a1 , int a2 " << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//	int _a2=1;
//};
//int main()
//{
//	A* p1 = new A(1);
//	A* p2 = new A(2,2);
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{ aa1,aa2,aa3 };//有明
//	A* p4 = new A[3]{ A(1,1),A(2,2),A(3,3)};
//	A* p5 = new A[3]{ {1,1},{2,2},{3,3} };
//	return 0;
//}

//using namespace std;
//int main()
//{
//	try
//	{
//		void* p1 = new char[1024 * 1024 * 1024];
//		cout << p1 << endl;
//		void* p2 = new char[1024 * 1024 * 1024];
//		cout << p2 << endl;
//		void* p3 = new char[1024 * 1024 * 1024];
//		cout << p3 << endl;
//	}
//	catch(const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main()
//{
//	A* p1 = new A(1);
//	delete p1;
//
//	A* p2 = new A[5];
//	delete[] p2;
//
//	return 0;
//}

//int main()
//{
//	int* p1 = new int;内置类型不析构
//	free(p1);
//	//delete p1;
//
//	A* p2 = new A;
//	//free(p2);
//	delete p2;
//
//	return 0;
//}

class B
{
public:
	~B()
	{
		std::cout << "~B()" << std::endl;
	}
private:
	int _b1 = 2;
	int _b2 = 2;
};

int main()
{
	//int* p1 = new int[10]; // -> malloc
	//delete p1;             // -> free
	//free(p1);

	B* p2 = new B[10];
	delete p2;

	//A* p3 = new A[10];
	//delete[] p3;

	return 0;
}