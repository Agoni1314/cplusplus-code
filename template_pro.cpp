#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace std;

//#define N 5//这样定义的话两个栈都是5
//class stack
//{
//private:
//	int arr[N];
//	int top;
//};
//int main()
//{
//	stack s1;
//	stack s2;
//	return 0;
//}

//template<class T,size_t N=10>
//template<size_t N=10>
//template<size_t N,bool flag=false >//布尔值也是整形
template<size_t N>
class stack
{

private:
	int _arr[N];
	int _top;
};
//int main()
//{
//	/*stack st1;//c++20以后才支持这样写
//	stack st2;*/
//	/*stack<> st1;
//	stack<> st2;*/
//	stack<5> st3;
//	stack<10> st4;
//	return 0;
//}

//template<double N >//c++20以后才支持非整形
//class stack
//{
//
//private:
//	int _arr[N];
//	int _top;
//};
//int main()
//{
//	stack<5> st3;
//	stack<10> st4;
//	return 0;
//}

int main()
{
	array<int, 10>a1;
	//会检查越界
	a1[9] = 3;

	//堆
	vector<int> v(10, 2);
	cout << sizeof(v) << endl;
	cout << sizeof(a1) << endl;
	return 0;
}