#include<iostream>
#include"AVL.h"
void test1()
{
	int arr[] = { 1,2,4,5,7,3,16,8 };
	AVLTree<int, int> it;
	for (auto e : arr)
	{
		it.insert({ e, e });
	}
	it.InOrder();
}
int main()
{
	test1();
	return 0;
}