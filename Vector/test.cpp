#include<iostream>
#include<vector>
using namespace std;

void test1()
{
	vector<int>v1;
	vector<int>v2(10, 1);
	vector<int> v3(++v2.begin(), --v2.end());
	/*for (auto sc : v2)
	{
		cout << sc << " ";
	}*/
	/*for (size_t i = 0;i < v2.size();i++)
	{
		cout << v2[i] <<" ";
	}*/
	//vector<int>::iterator it = v2.begin();
	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		++it;
	}
}
void test2()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "fold\n";
	for (int i = 0;i < 100;++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "YAMAHA" << sz << "\n";
		}
	}
	cout << endl;
}
void test3()
{
	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << endl;
	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << endl;
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << endl;
}
void test4()
{
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin()+3, 0);
	for (auto it : v)
	{
		cout << it << " ";
		it++;
	}
	cout << endl;
	vector<int> v1(5.0);
	for (size_t i = 0;i < 5;i++)
	{
		cin >> v1[i];
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test5()
{
	vector<string> v1;
	string s1("xxxx");
	v1.push_back(s1);

	v1.push_back("xxx");
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	//二维数组
	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);
	vv[2][1] = 2;
	//vv.operator[](2).operator[](1) = 2;
	for (size_t i = 0;i < vv.size();i++)
	{
		for (size_t j = 0;j < vv[i].size();++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//template<class T>
//class vector
//{
//	T& operator[](int i)
//	{
//		assert(i < _size);
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};
	////vector<int>
	//class vector
	//{
	//	int& operator[](int i)
	//	{
	//		assert(i < _size);
	//		return _a[i];
	//	}
	//private:
	//	int* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};

	////vector<vector<int>>
	//class vector
	//{
	//	vector<int>& operator[](int i)
	//	{
	//		assert(i < _size);
	//		return _a[i];
	//	}
	//private:
	//	vector<int>* _a;
	//	size_t _size;
	//	size_t _capacity;
	//};

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}