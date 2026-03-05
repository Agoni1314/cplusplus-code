#include<iostream>
#include<stdlib.h>
using namespace std;
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
// 定位new/replacement new
int main()
{
	//A * p1 = new A(1);
	A* p2 = (A*)operator new(sizeof(A));
	return 0;
}