#include<iostream>
#include<list>
using namespace std;
void test1()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);
	list<int>::iterator it = It.begin();
	while (it != It.end())
	{
		cout << *it << " ";
		++it;
	} 
	cout << endl;
}
struct A
{
public:
	A(int a1 = 1, int a2 = 2)
		:_a1(a1)
		,_a2(a2)
	{ }
	int _a1;
	int _a2;
};
void test2()
{
	/*list<int> It;
	It.emplace_back(1);
	It.emplace_back(2);
	It.emplace_back(3);
	It.emplace_back(4);
	for (auto e : It)
	{
		cout << e << " ";
	}
	cout << endl;*/
	list<A>It;
	A aa1(1,1);
	It.push_back(aa1);
	It.push_back(A(2,2));//只支持一个参数
	It.emplace_back(aa1);//支持可变参数
	It.emplace_back(A(2,2));
	It.emplace_back(3,3);
}
void test3()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);
	It.push_back(5);
	It.push_back(6);
	
	
	auto it = It.begin();
	int k = 3;
	while (--k)
	{
		++it;
	}
	cout << endl;
	It.insert(it, 30);
	for (auto e : It)
	{
		cout << e << " ";
	}
	int x = 0;
	cin >> x;
	it = find(It.begin(), It.end(), x);
		if (it != It.end())
		{
			It.erase(it);
		}
		for (auto e : It)
		{
			cout << e << " ";
		}
}
void test4()
{
	list<double>first, second;
	first.push_back(1.1);
	first.push_back(1.2);
	first.push_back(1.3);

	second.push_back(2.1);
	second.push_back(2.2);
	second.push_back(2.3);
	first.sort();
	second.sort();

	first.merge(second);


}
void test5()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);
	It.push_back(4);
	It.push_back(5);
	It.push_back(5);
	It.push_back(6);
	It.push_back(6);
	for (auto e : It)
	{
		cout << e << " ";
	}
	cout << endl;
	It.unique();//默认你是有序，重复的值在一起
	for (auto e : It)
	{
		cout << e << " ";
	}
}
void test6()
{
	list<int> mylist1, mylist2;
	list<int>::iterator it;
	for (int i = 1;i <= 4;++i)
		mylist1.push_back(i);
	for (int i = 1;i <= 4;++i)
		mylist2.push_back(i*10);
	it = mylist1.begin();
	++it;
	mylist1.splice(it, mylist2);
}
void test7()
{
	list<int> It;
	It.push_back(1);
	It.push_back(2);
	It.push_back(3);
	It.push_back(4);
	It.push_back(5);
	for (auto e : It)
	{
		cout << e << " ";
	}
	int x = 0;
	cin >> x;
	auto it = It.begin();
	it = find(It.begin(), It.end(), x);
	if (it != It.end())
	{
		It.splice(It.begin(), It,it,It.end());
	}
	for (auto e : It)
	{
		cout << e << " ";
	}
}
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	test7();
//	return 0;
//}