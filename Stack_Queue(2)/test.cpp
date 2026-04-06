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

int main ()
{
	//box::priority_queue<int,vector<int>,greater<int>> pq;
	//box::priority_queue<int> pq;
	box::priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(7);
	pq.push(9);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}

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