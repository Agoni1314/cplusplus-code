#include<iostream>
using namespace std;
#include"myset.h"
#include"mymap.h"

int main()
{
	boxset::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	boxset::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
	boxmap::map<string, string> dict;
	dict.insert({ "sort", "ÅÅĞò" });
	dict.insert({ "left", "×ó±ß" });
	dict.insert({ "right", "ÓÒ±ß" });

	/*dict["left"] = "×ó±ß£¬Ê£Óà";
	dict["insert"] = "²åÈë";
	dict["string"];*/
	boxmap::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// ²»ÄÜĞŞ¸Äfirst£¬¿ÉÒÔĞŞ¸Äsecond
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	boxset::set<int>::iterator sitc = s.begin();
	while (sitc !=s.end())
	{
		//*sitc += 10;
		cout << *sitc << " ";
		++sitc;
	}
	return 0;
}