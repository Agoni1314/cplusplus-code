#include<iostream>
#include"RBTree.h"
using namespace std;
void test1()
{
	RBTree<int, int > t;
	int a[] = { 1,5,3,4,7,8,9,21 };
	for (auto e : a)
	{
		t.Insert({ e,e });
	}
	t.InOrder();
}
int main()
{
	test1();
	return 0;
}