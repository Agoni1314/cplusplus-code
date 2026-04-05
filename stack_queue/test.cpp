#include<iostream>
using namespace std;
#include"Stack.h"
#include"Queue.h"


int main()
{
	box::stack<int, vector<int>>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.top() << endl;
	//st.pop();//按需实例化,用哪个接口才实例化哪个接口，其他接口细节不检查
	//box::queue<int, list<int>>q;//因为没有调用pop()，就没有报错
	box::queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << endl;
	q.pop();
	return 0;
}