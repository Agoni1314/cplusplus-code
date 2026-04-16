#include<iostream>
#include<set>
using namespace std;
//int main()
//{
//	// 去重+升序排序
//	set<int> s;
//	// 去重+降序排序（给一个大于的仿函数）
//	//set<int, greater<int>> s;
//	s.insert(5);
//	s.insert(2);
//	s.insert(7);
//	s.insert(5);
//	//set<int>::iterator it = s.begin();
//	auto it = s.begin();
//	while (it != s.end())
//	{
//		// “it”: 不能给常量赋值
//		// *it = 1;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	set<int> its;
//	its.insert(1);
//	its.insert(3);
//	its.insert(4);
//	its.insert(4);
//	its.insert(6);
//	set<int>::iterator sc = its.begin();
//	while (sc != its.end())
//	{
//		cout << *sc << " ";
//		sc++;
//	}
//	cout << endl;
//	/*set<string> fruit = {"apple","bananer","peal","apple"};
//	for (auto scc : fruit)
//	{
//		cout << scc << endl;
//	}
//	cout << endl;*/
//	/*its.erase(its.begin());
//	for (auto e : its)
//	{
//		cout << e << " ";
//	}
//	cout << endl;*/
//	int x;
//	cin >> x;
//	auto pos = s.find(x);
//	if (pos != s.end())
//	{
//		s.erase(pos);
//	}
//	else
//	{
//		cout << x << "不存在！" << endl;
//	}
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	// 算法库的查找 O(N)
//	auto pos1 = find(s.begin(), s.end(), x);
//	// set自身实现的查找 O(logN)
//	auto pos2 = s.find(x);
//}

int main()
{
	// 相比set不同的是，multiset是排序，但是不去重
	multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 相比set不同的是，x可能会存在多个，find查找中序的第一个
	int x;
	cin >> x;
	auto pos = s.find(x);
	while (pos != s.end() && *pos == x)
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;
	// 相比set不同的是，count会返回x的实际个数
	cout << s.count(x) << endl;
	// 相比set不同的是，erase给值时会删除所有的x
	s.erase(x);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}