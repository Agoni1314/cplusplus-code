#include"Date.h"
int main()
{
	Date d1(2000, 1, 1);
	Date d2=d1 + 20;
	d1.print();
	d2.print();
	Date d3(2025, 12, 1);
	Date d4 = d3 - 10;
	d3.print();
	d4.print();
	return 0;
}