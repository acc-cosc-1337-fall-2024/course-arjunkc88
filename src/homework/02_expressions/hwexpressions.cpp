#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write function code here
double get_sales_tax_amount(double meal_amount) {
    double tax_rate = 0.0675; // 6.75% tax rate
    return meal_amount * tax_rate;
}

double get_tip_amount(double meal_amount, double tip_rate) {
    return meal_amount * (tip_rate / 100.0); // Convert tip_rate to percentage
}



