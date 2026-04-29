#pragma once
#include<vector>
#include<utility>

enum state
{
	EXIST,
	EMPTY,
	DELETE
};
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	state _state = EMPTY;
};
template<class K,class V>
class HashTable
{
public:
	HashTable()
	
		:_tables(11)
		,_n(0)
		{ }
	
	bool insert(const pair<K, V>& kv)
	{
		if (find(kv.first))
			return false;
		//负载因子>=0.7
		if (_n * 10 / _tables.size() >= 7)
		{
			//vector<HashData<K, V>> newtables(_tables.size() * 2);
			//	for (auto& data : _tables)
			//	{
			//		//旧表的数据映射到新表
			//		if (data._state == EXIST)
			//		{
			//			size_t hashi0 = data._kv.first % newtables.size();
			//		}
			//}
			//_tables.swap(newtables);
			HashTable<K, V> newt;
			newt._tables.resize(_tables.size() * 2);
			for (auto& data : _tables)
			{
				if (data._state == EXIST)
				{
					newt.insert(data._kv);
				}
			}
			_tables.swap(newt._tables);
		}
		size_t hashi0 = kv.first % _tables.size();
		size_t hashii = hashi0;
		size_t i = 1;
		while (_tables[hashii]._state == EXIST)
		{
			//线性探测
			hashii = (hashi0+i) % _tables.size();
			++i;
		}
		_tables[hashii]._kv = kv;
		_tables[hashii]._state = EXIST;
		++_n;
		return true;
	}
	HashData<K, V>* find(const K& key)
	{
		size_t hashi0 = key% _tables.size();
		size_t hashii = hashi0;
		size_t i = 1;
		while (_tables[hashii]._state !=EMPTY)
		{
			if (_tables[hashii]._state == EXIST&&_tables[hashii]._kv.first == key)
			{
				return& _tables[hashii];
			}
			//线性探测
			hashii = (hashi0+i) % _tables.size();
			++i;
		}
		return nullptr;
	}
	bool erase(const K& key)
	{
		HashData<K, V>* ret = find(key);
		if (ret)
		{
			ret->_state = DELETE;
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n;
};