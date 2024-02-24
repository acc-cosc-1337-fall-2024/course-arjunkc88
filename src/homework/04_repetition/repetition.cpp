//add include statements
#include "repetition.h"

//add function(s) code here

// Implementing the factorial function
int factorial(int num)
{
    int sum = 1; // Initializing sum to 1 instead of 0 for multiplication
    while (num > 0) {
        sum *= num; // Multiplying the current number with the sum
        num--; // Decrementing the number by 1
    }
    return sum;
}

// Implementing the gcd function
int gcd(int num1, int num2) 
{
    while (num1 != num2) 
    {
        if (num1 > num2) 
        {
            num1 -= num2; // Subtracting num2 from num1
        } else {
            // Swapping num1 and num2 if num1 is less than num2
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
    }
    return num1;
}
