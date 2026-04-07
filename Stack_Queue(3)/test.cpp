#include<iostream>
using namespace std;
#include"Stack.h"
#include"Queue.h"
#include<queue>
#include<stack>
#include<algorithm>
#include"Priority_Queue.h"
//int main()
//{
//	box::stack<int, vector<int>>st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.top() << endl;
//	//st.pop();//按需实例化,用哪个接口才实例化哪个接口，其他接口细节不检查
//	//box::queue<int, list<int>>q;//因为没有调用pop()，就没有报错
//	box::queue<int>q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	cout << q.front() << endl;
//	q.pop();
//	return 0;
//}

//int main ()
//{
//	//box::priority_queue<int,vector<int>,greater<int>> pq;
//	//box::priority_queue<int> pq;
//	
//	//box::priority_queue<int, vector<int>, greater<int>> pq;
//	//priority_queue<int> pq;//取小堆
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(4);
//	pq.push(1);
//	pq.push(5);
//	pq.push(7);
//	pq.push(9);
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	int myints[] = { 10,20,30,5,15 };
//	sort(myints, myints + 5);
//	std::vector<int> v(myints, myints + 5);
//	cout << is_heap(v.begin(), v.end());
//	cout << endl;
//	make_heap(v.begin(), v.end());
//	cout << is_heap(v.begin(), v.end());
//	std::sort_heap(v.begin(), v.end());
//	
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//访函数,本质是一个类，这个类重载operator()，对象可以像函数一样使用
template <class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};
template <class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
template<class Compare>
void bubbleSort(int* a, int n,Compare com) 
{
    for (int j=0; j < n; j++) 
	{
		int flag = 0;
        for (int i = 1; i < n -j; i++) 
		{
            //if (a[i]<a[i-1]) 
			if(com(a[i], a[i - 1]))
			{ 
				swap(a[i - 1], a[i]);
				flag = 1;
            }
        }
		if (flag == 0)
		{
			break;
		}
    }
}
//int main()
//{
//	Less<int> lessfunc;
//	Greater<int> Greaterfunc;
//	//函数对象
//	cout << lessfunc(1, 2) << endl;
//	cout << lessfunc.operator()(1, 2) << endl;
//	
//	int a[] = { 6,4,2,7,9,1 };
//	bubbleSort(a, 6,lessfunc);
//	bubbleSort(a, 6, Greaterfunc);
//
//	bubbleSort(a, 6, Less<int>());
//	bubbleSort(a, 6, Greater<int>());
//	return 0;
//}

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
	}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	
private:
	int _year;
	int _month;
	int _day;
};
 ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
 class Dateless
 {
 public:
	 bool operator()(Date* p1, Date* p2)
	 {
		 return *p1 < *p2;
	 }
 };
int main()
{
	// 大堆，需要用户在自定义类型中提供<的重载
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;
	cout << endl;
	// 如果要创建小堆，需要用户提供>的重载
	//类类型不支持比较大小，虽然支持比较大小，但是比较的逻辑不对，需要自己写防函数

	priority_queue<Date*, vector<Date*>, Dateless> q2;
	q2.push(new Date(2018, 10, 29));
	q2.push(new Date(2018, 10, 28));
	q2.push(new Date(2018, 10, 30));
	cout << *q2.top() << endl;
	q2.pop();
	cout << *q2.top() << endl;
	q2.pop();
	cout << *q2.top() << endl;
	q2.pop();
	/*priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << q2.top() << endl;*/
	return 0;
}
