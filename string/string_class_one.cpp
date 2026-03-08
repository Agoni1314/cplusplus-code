#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;
//class string   string大概底层
//{
//private:
//	char* _str;
//	size_t _size;
//	size_t capaccity;
//};
void test_string1()
{
	string s1;
	string s2("hello world!");
	s2[0] = 'x';
	cout << s1 << s2 << endl;
	//三种迭代方式
	// 1： 下标+[]
	for (size_t i = 0;i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	
	}
	cout << endl;
	//2：迭代器
	//string::iterator it = s2.begin();
	auto it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;//迭代器可以修改
		cout << *it << " ";
		++it;
	}
	cout << endl;

	/*map<string, string>dict;
	map<string, string>::iterator mit=dict.begin();
	auto mit = dict.begin();*/
	
	//list<int>lt = { 1,2,3,4,5,6,7,8 };//所有容器都相似
	//list<int>::iterator lit = lt.begin();
	//while (lit != lt.end())
	//{
	//	cout << *lit << endl;
	//	++lit;
	//}
	//cout << endl;
	
	//3：字符赋值，自动迭代，自动判断结束
	//for (auto sc : s2)//自动从s2取出字符
	//{
	//	sc -= 2;
	//	cout << sc <<" ";
	//}//底层就是迭代器
	cout <<endl;
	cout << s2 << " "; //但并没有改变string s2本身，底层变换成迭代器后会自动取s2的每一个子字符，相当于把*it拷贝给sc
	cout << endl;
	for (auto& sc : s2)//要想改变要加引用
	{
		sc -= 2;
		cout << sc << " ";
	}
	cout << s2 << " ";
}
//int main()
//{
//	test_string1();
//	return 0;
//}


//int func1()
//{
//	return 10;
//}
////void func2(auto a)auto不能做参数
////{
////}
//auto func2()
//{
//	return func1();
//}
//auto func3()
//{
//	return func2();
//}
//
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = func1();
//	// 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
//	//auto e;不能这样定义,也不能定义数组
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	//auto可以做返回值，但要谨慎
//	auto ret = func3();
//	cout << typeid(ret).name() << endl;
//	//范围for就适用于容器和数组
//	int array[] = { 1,2,3,4 };
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//	cout << endl;
//	for (auto e : array)
//	{
//		cout << e << " " << endl;
//	}
//	return 0;
//}

void test_string2()
{
	/*string s2("hello world");
	auto it = s2.begin();
	while (it != s2.end())
	{
		*it += 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		*rit += 2;
		cout << *rit << " ";
		++rit;
	}*/

	const string s3("hello world");
	string :: const_iterator cit = s3.begin();
	while (cit != s3.end())
	{
		//*cit += 2;
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//string::const_reverse_iterator rcit = s3.rbegin();
	auto rcit = s3.rbegin();
	while (rcit != s3.rend())
	{
		//*rit += 2;
		cout << *rcit << " ";
		++rcit;
	}
}
int main()
{
	test_string2();
	return 0;
}