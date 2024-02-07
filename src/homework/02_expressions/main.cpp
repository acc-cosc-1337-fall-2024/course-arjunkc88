#include <iostream>
#include "hwexpressions.h"
//write include statements
using std::cout;
using std::cin;

//write namespace using statement for cout

int main()
{
	 double meal_amount, tip_rate, tax_amount, tip_amount, total;

	cout << "Enter meal amount: ";

	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

    cout << "Enter tip rate (%): ";

	cin >> tip_rate;

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tax_amount + tip_amount;

	 std::cout << "\nReceipt:\n";
    std::cout << "Meal Amount:        " << meal_amount << std::endl;
    std::cout << "Sales Tax:          " << tax_amount << std::endl;
    std::cout << "Tip Amount:         " << tip_amount << std::endl;
    std::cout << "Total:              " << total << std::endl;

	return 0;
}
