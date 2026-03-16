#include<iostream>
#include<string>
//class string
//{
//public:
//private:
// char _buff[16];
//	char* _str;
//	size_t _size;
//	size_t _capacity;
//};
using namespace std;
//void test1()
//{
//	string s1;
//	cout << s1 << endl;
//	string s2("hello world");
//	cout << s2 << endl;
//	s2[2] = '2';
//	cout << s2 << endl;
//	for (size_t i = 0;i < s2.size();i++)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	//string::iterator it = s2.begin();
//	auto it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	for (auto sc:s2)
//	{
//		sc += 2;
//		cout << sc << " ";
//	}
//	cout << endl;
//	cout << s2 << endl;
//	for (auto& sc : s2)//要加引用才能改变字符串
//	{
//		sc += 2;
//		cout << sc << " ";
//	}
//	cout << endl;
//	cout << s2 << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}


int func1()
{
	return 10;
}
//void func2(auto a)auto不能做参数
//{
//}
auto func2()
{
	return func1();
}
auto func3()
{
	return func2();
}
void test2()
{
	int arr[] = { 1,2,3,4,5,6 };
	for (auto sc : arr)
	{
		sc += 2;
		cout << sc << "   ";
	}
	cout << endl;
	for (auto sc : arr)
	{
		cout << sc << "   ";
	}
	cout << endl;
}
void test3()
{
	const string s1("hello world");
	//s1[0] = 'w';在前面加const就变成了常量，不能修改
	//static string s1("hello world");//加static就在静态库里面，即使函数运行结束了，s1 里的内容也会被保留。下次你再进这个函数，它还是上次离开时的样子，以如果你的字符串很大，用 static 可以省去频繁创建和销毁的开销
	for (auto sc : s1)
	{
		cout << sc << " ";
	}
	cout << endl;
	/*auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;*/
}
void test4()
{
	const string s1("hello world");
	//auto rit = s1.rbegin();
	string ::const_reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	string ::const_iterator cit = s1.cbegin();
	while (cit != s1.cend())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}
void test5()
{
	/*string s1("hello worldqwer");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	string s2("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");*/
	s1.push_back('abc');//只会插入最后一个字符
	cout << s1 << endl;
	s1.append("yyyyyyyyyy");//可插入多个字符
	cout << s1 << endl;
	s1.insert(0, "qqqq");
	cout << s1 << endl;
	char ch = 'xxxt';//还是只能是最后一个字符
	s1.insert(s1.size(), 2, ch);
	cout << s1 << endl;
}
void test6()
{
	string s1("hello world");
	s1.erase(0, 2);
	cout << s1 << endl;
	s1.erase(s1.begin());
	cout << s1 << endl;
	s1.erase(--s1.end());//end()指向的是最后一个字符的后一个位置
	cout << s1 << endl;
	string s2("hello world hello world hello world");
	int pos = s2.find(" ");
	while (pos != string::npos)
	{
		s2.replace(pos, 1, "*%");
		pos = s2.find(" ", pos + 2);
	}
	cout << s2 << endl;
	cout << endl;
}
void test7()
{
	string s1("hello world");
	cout<<s1.size()<<endl;
	cout<<s1.capacity()<<endl;
	cout << endl;

	s1.reserve(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.reserve(5);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.reserve(60);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;

	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << endl;
}
int main()
{
	/*float a = 10.0f;
	auto b = a;
	cout << typeid(b).name() << endl;*/
	/*int a = 10;
	auto d = func3();
	cout << typeid(d).name() << endl;*/
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}