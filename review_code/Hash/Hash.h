#pragma once
enum state
{
	EXIST,
	EMPTY,
	DELETE
};
template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	state _state = EMPTY;
};
template<class K, class V>
class HashTable
{
public:
	HashTable()
		:_tables(__stl_next_prime(0))
		,_n(0)
	{ }
	inline unsigned long __stl_next_prime(unsigned long n)
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
	bool insert(const pair<K, V>& kv)
	{
		if (_n * 10 / _tables.size() >= 7)
		{
			if (find(kv.first))
				return false;
			HashTable<K, V> newh;
			newh._tables.resize(_tables.size() * 2);
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						newh.insert(data._kv);
						++_n;
					}
				}
			_tables.swap(newh._tables);
		}
		size_t primitive_hashi = kv.first % _tables.size();
		size_t hashii = primitive_hashi;
		size_t i = 1;
		while (_tables[primitive_hashi]._state == EXIST)
		{
			hashii = (primitive_hashi + i) % _tables.size();
			++i;
		}
			_tables[hashii]._kv = kv; 
			_tables[hashii]._state = EXIST;
		++_n;
		return true;
	}
	HashNode<K, V>* find(const K& key)
	{
		size_t primitive_hashi = key % _tables.size();
		size_t hashii = primitive_hashi;
		size_t i = 1;
		while (_tables[hashii]._state != EMPTY)
		{
			if (_tables[hashii]._state == EXIST && _tables[hashii]._kv.first == key)
			{
				return& _tables[hashii];
			}
			hashii = (primitive_hashi + i) % _tables.size();
			++i;
		}
		return nullptr;
	}
	bool ersae(const K& key)
	{
		HashNode* ret = find(key);
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
	vector<HashNode<K,V>> _tables;
	size_t _n;
};