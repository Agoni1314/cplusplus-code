//#include<iostream>
//using namespace std;
//class B;
//class A
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class B;
//class C;
//class A
//{
//public:
//	friend void func(const A& aa, const B& bb, const C& cc);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	friend void func(const A& aa, const B& bb, const C& cc);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//class C
//{
//public:
//	friend void func(const A& aa, const B& bb, const C& cc);
//private:
//	int _c1 = 5;
//	int _c2 = 6;
//};
//void func(const A&aa,const B&bb,const C&cc)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//	cout << cc._c1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	C cc;
//	func(aa, bb,cc);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout <<a. _k << endl; 
//			cout << a._h << endl;
//		}
//	private:
//		int _b1=1;
//	};
//};
//int A::_k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//	A aa;
//	b.foo(aa);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	class B
//	{
//	public:
//		void func(const A& aa)
//		{
//			cout << aa._a << endl;
//			cout << aa._b << endl;
//		}
//	private:
//		int _c = 3;
//		int _d = 4;
//	};
//private:
//	static int _a;
//	int _b=2;
//	
//};
////int A::B::_c = 100;非静态数据成员不能定义在类外
//int A::_a = 1;
//int main()
//{
//	
//	A::B b;
//	A aa;
//	b.func(aa);
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};
int main()
{
	A aa1;//有名对象
	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
	//A aa1();
	A();//匿名对象,生命周期一行
	A(1);//匿名对象
	A aa2(2);
	//有名对象调用
	Solution st;
	cout << st.Sum_Solution(10) << endl;
	//匿名
	cout << Solution().Sum_Solution(10) << endl;
	return 0;
}

