#include"Date.h"
int main()
{
	Date d1(2024, 1, 2);
	Date d2=d1 + 100;
	d1.print();
	d2.print();
	Date d3(2024, 12, 3);
	Date d4 = d3 - 10000;
	d3.print();
	d4.print();
	return 0;
}