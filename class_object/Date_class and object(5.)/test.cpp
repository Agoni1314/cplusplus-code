#include"Date.h"
void test1()
{
	Date d1(2000, 1, 1);
	Date d2 = d1 + 20;
	d1.print();
	d2.print();
	/*Date d3(2025, 12, 1);
	Date d4 = d3 - 10;
	d3.print();
	d4.print();*/
	/*Date d1(2000, 1, 1);
	Date d2(20201,1);
	d2 = d1;
	d2.print();*/
}
void test2()
{
	Date d5(2020, 1, 2);
	Date d6 = d5 + 100;
	d6.print();
	/*d5 += -100;
	d5.print();*/
	/*Date d7 = ++d5;
	d7.print();*/
	/*Date d6 = d5--;
	d6.print();*/
	
}
void test3()
{
	Date d1(2024, 12, 1);
	Date d2(2024, 1, 1);
	cout << d1 - d2 << endl;
}
void test4()
{
	/*Date d1(1999, 12, 31);
	Date d2;*/
	/*cin >> d1 >> d2;
	cout << d1 << d2;*/
	//cout << d1;
	//d1 << cout;                
	
	/*cout << d1;
	operator<<(cout, d1);*/
	//cout << d1 << d2; //赋值从右往左，流插入从左往右
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;
	cout << d1 - d2 << endl;
}
void test5()
{
	const Date d1(2020, 1, 1);
	d1.print();
	Date d2(2020, 1, 2);
	d2.print();
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}

