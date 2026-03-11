#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<list>
#include<map>
using namespace std;
//class string   string大概底层
//{
//private:
// char _buff[16];//当数据量小的时候存在这里面，只有vs有这个功能
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
	string :: const_iterator cit = s3.cbegin();
	while (cit != s3.cend())
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
void TestPushBack();
void test_string3()
{
	string s2("hello world");
	cout << s2.length() << endl;//length不具有通用性
	string s3("wwwwwwwwwwwwwwwwwww");
	//cout << s2.size() << endl;
	//cout << s2.max_size() << endl;
	TestPushBack();
}
void TestPushBack()
{
	string s;
	s.reserve(100);//提前开空间  ,减少频繁扩容
	size_t sz = s.capacity();
	cout << "capacity changed" << sz << "\n";
	cout <<"charge grow" << endl;
	for (size_t i = 0;i < 100;++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed" << sz << "\n";
		}
	}
}

void test_string4()
{
	string s2("hello world121314151617181920");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << endl;

	s2.reserve(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << endl;

	s2.reserve(5);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << endl;

	s2.reserve(50);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << endl;

	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	cout << endl;
}
void tets_string5()
{
	string s("hello world");
	s.push_back(' ');
	s.push_back('a');
	s.append("yyyyy");
	cout << s << endl;
	s+=' ';
	s += 'a';
	s += "yyyyy";
	cout << s << endl;
	s.insert(0, "bit");//在第一个位置插入
	cout << s << endl;
	s.insert(10, "bit");
	cout << s << endl;
	
	string k("hello wrold");
	char ch = 't';//就算有多个字符，也只插入最后一个
	k.insert(0, 2, ch);//第几个位置，插入几个
	cout << k << endl;
	k.insert(k.begin(), 2, ch);
	k.insert(k.size(), 2, ch);//在末尾
	cout << k << endl;
}
void tets_string6()
{
	string s("hello world");
	s.erase(2, 1);//第几个位置，删几个
	cout << s << endl;
	s.erase(s.begin());
	cout << s << endl;
	s.erase(--s.end());
	cout << s << endl;

	string ss("hello world");
	ss.erase(6);//超出最大字符个数就报错
	cout << ss << endl;

	/*string sss("hello world");
	sss.replace(5, 1, "@@");//第几个位置，长度
	cout << sss << endl;*/

	//把所有的空格替换成百分号
	string sc("hello world hello world hello world");
	int pos = sc.find(' ');
	while (pos != string::npos)
	{
		sc.replace(pos, 1, "%%");
		//pos = sc.find(' ');
		pos = sc.find(' ', pos + 2);//把第一个空格替换后从w往后走
	}
	cout << sc << endl;
	string tmp;
	//sc.reserve(sc.size());//也可以提前算好空间 
	for (auto ch : sc)
	{
		if (ch == ' ')
			tmp += "%%";
		else
			tmp +=ch;
	}
	cout << tmp << endl;
	sc.swap(tmp);
	cout << sc << endl;
}
void tets_string7()
{
	string s("test.cpp");
	size_t pos = s.find('.');
	string sub = s.substr(pos);
	cout << sub << endl;
}
void tets_string8()
{
	string s1("hello");
	string s2 = s1 + "world";//运算符重载只要求有一个类类型 
	cout << s2 << endl;
	string s3 = "world" +s1 ;
	cout << s3 << endl;
}
//int main()
//{
//	//test_string2();
//	//test_string3();
//	//TestPushBack();
//	//test_string4();
//	//tets_string5();
//	//tets_string6();
//	//tets_string7();
//	//tets_string8();
//	return 0;
//}
#include"string.h"
int main()
{
	box::test_string1();
	return 0;
}
