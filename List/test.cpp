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
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}