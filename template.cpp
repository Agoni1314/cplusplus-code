#include<iostream>
#include<string>
using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//模板类型
//template<class T>
//void Swap(T& x, T& y)
//{
	/*T tmp = x;
	x = y;
	y = tmp;*/
//}
//template<class T1, class T2>
////template<class T1,typename T2>
//void func(const T1& x, const T2& y)
//{
//
//}
//
//int main()
//{
	/*int i = 0, j = 2;
	double m = 1.1, n = 2.2;*/
//	Swap(i, j);
//	Swap(m, n);
//	//Swap(i, n);
//
//	swap(i, j);
//	swap(m, n);
//
//	func(i, m);
//	func(i, j);
//	return 0;
//}

//函数模板生成对应的函数->模板实例化
//template<class T1>
//T1 func(const T1& x, const T1& y)
//{
//	return x + y;
//}
//int main()
//{
//	int i = 1, j = 2;
//	double m = 1.1, n = 2.2;
//	//推导实例化
//	cout<<func(i, (int)m)<<endl;
//	cout << func((double)i, m) << endl;
//	//显示实例化
//	cout << func<int>(i, m) << endl;
//	cout << func<double>(i, m) << endl;
//	return 0;
//}

//template<class T1>
//T1 func(const T1& x, const T1& y)
//{
//	return x + y;
//}
//int func(const int& x, const int& y)
//{
//	return (x + y)*10;
//}
//int main()
//{
//	int a = 1, b = 2;
//	cout << func(a, b) << endl;
//	return 0;
//}

//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t n= 4)
//		:_array(new T[n])
//		, _capacity(n)
//		, _size(0)
//		
//	{ }
//	~Stack()
//	{
//		delete[]_array;
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//	
//	void Push(const T& data);
//
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	if (_size == _capacity)
//	{
//		T* tmp = new T[_capacity * 2];
//		memcpy(tmp, _array, sizeof(T) * _size);
//		delete[]_array;
//		_array = tmp;
//		_capacity *= 2;
//	}
//	_array[_size++] = data;
//}
//int main()
//{
//	//类模板都是显示实例化
//	Stack<int>st1;
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//
//	Stack<double>st2;
//	st2.Push(1.1);
//	st2.Push(2.2);
//	st2.Push(3.3);
//	Stack<double>* pst = new Stack<double>;
//	delete pst;
//	return 0;
//}

int main()
{
	string s1;
	string s2("12345");
	string s3(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	/*cin >> s1;
	cout << s1 << endl;*/
	string s4(s2, 2, 3);
	cout << s4 << endl;
	string s5(s2, 2, 10);
	cout << s5 << endl;
	string s6("hello world", 5);
	cout << s6 << endl;
	string s7(10, '6');
	cout << s7 << endl;
	s6[0] = 'x';
	cout << s6 << endl;
	return 0;
}