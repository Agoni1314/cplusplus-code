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
	
		:_tables(pow(2,_m))
		,_n(0)
		{ }
	static inline unsigned long __stl_next_prime(unsigned long n)
	{
		// Note: assumes long is at least 32 bits.
		static const int __stl_num_primes = 28;
		static const unsigned long __stl_prime_list[__stl_num_primes] =
		{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
		};
		const unsigned long* first = __stl_prime_list;
		const unsigned long* last = __stl_prime_list + __stl_num_primes;
		const unsigned long* pos = lower_bound(first, last, n);
		return pos == last ? *(last - 1) : *pos;
	}
	size_t HashFunc(const K& key)
	{
		//size_t hashi = key % _tables.size();
		//size_t hashi = key &(pow(2,_m)-1);
		size_t hashi = key & (_tables.size() - 1);
		hashi ^= (key >> (32 - _m)); 
		return hashi;
	}
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
			++_m;
			newt._tables.resize(pow(2,_m));
			newt._tables.resize(_tables.size() * 2);
			//newt._tables.resize(__stl_next_prime(_tables.size()+1));
			for (auto& data : _tables)
			{
				if (data._state == EXIST)
				{
					newt.insert(data._kv);
				}
			}
			_tables.swap(newt._tables);
		}
		//size_t hashi0 = kv.first % _tables.size();
		size_t hashi0 = HashFunc(kv.first);
		size_t hashii = hashi0;
		size_t i = 1;
		while (_tables[hashii]._state == EXIST)
		{
			//线性探测
			hashii = (hashi0+i) % _tables.size();
			++i;
		}
		//二次探测
		/*int flag = 1;
		while (_tables[hashii]._state == EXIST)
		{
		hashii = (hashi0+(i*i*flag)) % _tables.size();
			if (hashii<_tables.size();)
				hashii+=_tables.size();
				if (flag = 1)
				{
					flag = -1;
				}
				else
				{
					++i;
					flag = 1;
				}
		
		}*/
		
		_tables[hashii]._kv = kv;
		_tables[hashii]._state = EXIST;
		++_n;
		return true;
	}
	HashData<K, V>* find(const K& key)
	{
		//size_t hashi0 = key.first %_tables.size();
		size_t hashi0 = HashFunc(key);
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
	size_t _m = 16;
};