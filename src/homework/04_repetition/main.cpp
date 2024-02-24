//write include statements
#include <iostream>
#include "repetition.h"

using namespace std; //write using statements

int main()
 {
    int choice;
    do 
	{
        cout << "1-Factorial\n2-Greatest Common Divisor\n3-Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) 
		{
            case 1: 
			{
                int num;
                cout << "Enter a number for factorial: ";
                cin >> num;
                cout << "Factorial of " << num << " is " << factorial(num) << endl;
                break;
            }
            case 2: 
			{
                int num1, num2;
                cout << "Enter two numbers for GCD: ";
                cin >> num1 >> num2;
                cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
                break;
            }
            case 3: 
			{
                char confirm;
                cout << "Are you sure you want to exit? (y/n): ";
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    return 0; // Exiting the program
                }
                break;
            }
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (true);
}

