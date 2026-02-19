#include"Date.h"
int main()
{
	Date d1(2024, 1, 2);
	Date d2=d1 + 100;
	d1.print();
	d2.print();
	return 0;
}