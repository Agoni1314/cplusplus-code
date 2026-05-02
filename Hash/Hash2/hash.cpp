#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
//int main()
//{//哈希表遍历无序
//	unordered_set<int> arr = { 1,2,3,4,5,1,2,3,4 };
//	unordered_set<int>::iterator it = arr.begin();
//	while (it != arr.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

void test_set2()
{
	const size_t N = 1000000;
	unordered_set<int> us;
	set<int> s;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand()); // N比较大时，重复值比较多​
		v.push_back(rand() + i); // 重复值相对少​
		//v.push_back(i); // 没有重复，有序​
	}
	// 21:15
	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;
	size_t begin2 = clock();
	us.reserve(N);
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;
	int m1 = 0;
	size_t begin3 = clock();
	for (auto e : v)
	{
		auto ret = s.find(e);
		if (ret != s.end())
		{
			++m1;
		}
	}
	size_t end3 = clock();
	cout << "set find:" << end3 - begin3 << "->" << m1 << endl;
	int m2 = 0;
	size_t begin4 = clock();
	for (auto e : v)
	{
		auto ret = us.find(e);
		if (ret != us.end())
		{
			++m2;
		}
	}
	size_t end4 = clock();
	cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
	cout << "插入数据个数：" << s.size() << endl;
	cout << "插入数据个数：" << us.size() << endl << endl;
	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;
	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
	return ;
}
#include"HashTable.h"
//int main()
// {
//	//test_set2();
	/*int a[] = {12,23,45,567,2,312,34};
	HashTable<int, int> it;
	for (auto e : a)
	{
		it.insert({ e,e });
		HashData<int, int>* ret = it.find(e);
		{
			if (ret)
			{
				cout << ret->_kv.first << ":" << ret->_kv.second << endl;
			}
		}
	}
	cout << endl;*/
//	int x;
//	it.erase(30);
//	if (it.find(20))
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "没有" << endl;
//	}
//	cout << HashTable<int,int>:: __stl_next_prime(53) << endl;
//	cout << HashTable<int, int>::__stl_next_prime(54) << endl;
//	return 0;
//}

struct StringHaahFunc
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
		}
		return hash;
	}
};
struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
};

struct DateHashFunc
{
	size_t operator()(const Date& d)
	{
		size_t hash = 0;
		hash += d._year;
		hash *= 131;

		hash += d._month;
		hash *= 131;

		hash += d._day;
		hash *= 131;

		return hash;
	}
};
int main()
{
	const char* a[] = {"abcd","apple","china"};
	HashTable<string,string, StringHaahFunc> it;
	for (auto& e : a)
	{
		it.insert({ e,e });
		HashData<string,string>* ret = it.find(e);
		{
			if (ret)
			{
				cout << ret->_kv.first << ":" << ret->_kv.second << endl;
			}
		}
	}
	cout << endl;
	int a2[] = { 12,23,45,567,2,312,34 };
	HashTable<int, int> its;
	for (auto e : a2)
	{
		its.insert({ e,e });
		HashData<int, int>* ret = its.find(e);
		{
			if (ret)
			{
				cout << ret->_kv.first << ":" << ret->_kv.second << endl;
			}
		}
	}
	cout << HashFunc<string>()("abcd") << endl;
		cout << HashFunc<string>()("bcad") << endl;
		cout << HashFunc<string>()("aadd") << endl;
	
		int a3[] = { -19,-30,5,36,13,20,21,12 };
		HashTable<int, int> ht2;
		for (auto e : a3)
		{
			ht2.insert({ e, e });
		}
	
		// 哈希冲突
		HashTable<Date, int, DateHashFunc> ht;
		ht.insert({ { 2024, 10, 12 }, 1});
		ht.insert({ { 2024, 12, 10 }, 1 });
	cout << endl;
	return 0;
}