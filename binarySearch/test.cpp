#include<iostream>
#include"BinarySearch.h"
int main()
{
	/*key::BSTree<int> t;
	int a[] = { 8,3,1,10,1,6,5,7,14,13 };
	for (auto e : a)
	{
		t.insert(e);
	}
	t.InOrder();

	t.insert(100);
	t.InOrder();

	t.erase(3);
	t.InOrder();*/

	/*key_value::BSTree<string, string> dict;
	dict.insert("left", "左边");
	dict.insert("right", "右边");
	dict.insert("insert", "插入");
	dict.insert("string", "字符串");
	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << "->" << ret->_value << endl;
		}
		else
		{
			cout << "无此单词，请重新输入" << endl;
		}
	}
	return 0;*/
	string arr[] = { "apple", "peal", "apple", "peal", "apple", "apple", "peal", "apple", "bananar", "apple", "bananar" };
	key_value::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的结点中水果对应的次数++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
	key_value::BSTree<string, int> cpoy = countTree;
	
}
	


	
