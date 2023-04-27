#include<iostream>
#include ".\payment.h"
using namespace std;

void print_payment(payment pay)
{
	pay.show();
}
int main()
{
	payment pay;
	pay.show();
	payment pay2("Nikolai", 40000, 5000);
	pay2.show();
	payment pay3 = pay2;
	pay3.setName("Masha");
	pay3.setSalary(80000);
	pay3.setBonus(8000);
	print_payment(pay3);
	return 0;
}