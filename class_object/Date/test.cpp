#include"Date.h"
void test1()
{
	calendar day1(2020, 12, 12);
	calendar day2(2020, 12, 12);
	bool ret = day1.operator==(day2);
	cout << ret << endl;
}
void test2()
{
	calendar day1(2026, 3, 15);
	/*day1+=100;
	day1.print();
	day1 += 10000;
	day1.print();*/
	/*calendar day2 = day1 + 10000;
	day2.print();*/
	day1.print();
	/*day1 -= 20000;
	day1.print();*/
	calendar day2 = day1 - 10000;
	day2.print();
}
void test3()
{
	calendar day1(2026, 3, 15);
	calendar day2(2025, 3, 15);
	bool ret=day1 < day2;
	cout << ret << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}