#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
#include"Stack.h"
#include"Queue.h"
#include"priority_queue.h"

//int main()
//{
//	/*box::stack<int, vector<int>> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	cout << st.top() << endl;
//	st.pop();*/
//
//	/*bix::queue<int, list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	cout << q.front() << endl;*/
//
//	//bix::priority_queue<int> st;//优先级队列默认值大的优先级高
//	//st.push(1);
//	//st.push(2);
//	//st.push(3);
//	//st.push(4);
//	//while (st.empty())
//	//{
//	//	cout << st.top() << " ";
//	//	st.pop();
//	//}
//	//return 0;
//}

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};
template<class Compare>
void bubbleSort(int* a, int n, Compare com)
{
	for (int j = 0; j < n; j++)
	{
		int flag = 0;
		for (int i = 1; i < n - j; i++)
		{
			//if (a[i]<a[i-1]) 
			if (com(a[i], a[i - 1]))
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
int main()
{
	Less<int> lessfunc;
	//cout << lessfunc(1, 2) << endl;
	Greater<int> greaterfunc;
	//cout << greaterfunc(1, 2) << endl;
	/*int a[] = { 6,4,2,7,9,1 };
	bubbleSort(a, 6, lessfunc);
	bubbleSort(a, 6, greaterfunc);*/

	bix::priority_queue<int, vector<int>, Greater<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}