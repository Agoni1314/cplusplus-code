#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#include"Hash.h"
int main()
{
	int a[] = { 2,23,4,5,6,1 };
	HashTable<int, int> it;
	for (auto e : a)
	{
		it.insert({ e,e });
		HashNode<int, int>* ret = it.find(e);
		if (ret)
		{
			cout << ret->_kv.first << ":" << ret->_kv.second << endl;
		}
	}
	return 0;
}