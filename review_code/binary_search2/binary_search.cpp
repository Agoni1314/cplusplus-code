#include<iostream>
#include<string>
#include"binary_search.h"
int main()
{
	/*BSTree<int> sb;
	sb.insert(1);
	sb.insert(2);
	sb.insert(3);
	sb.insert(4);
	sb.InOrder();*/

	string arr[] = {"apple", "peal", "apple", "peal", "apple", "apple", "peal", "apple", "bananar", "apple", "bananar"};
	key_value::BSTree<string, int> counttree;
	for (auto& str : arr)
	{
		auto ret = counttree.Find(str);
		if (!ret)
		{
			counttree.insert(str,1);
		}
		else
		{
			ret->_value++;
		}
	}
	counttree.InOrder();
	return 0;
}
