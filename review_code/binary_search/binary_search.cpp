#include<iostream>
#include"binary_search.h"
int main()
{
	BSTree<int> sb;
	sb.insert(1);
	sb.insert(2);
	sb.insert(3);
	sb.insert(4);
	sb.InOrder();
	return 0;
}
