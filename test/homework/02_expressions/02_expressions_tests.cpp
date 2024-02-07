#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

// Test Case 1: Test Get Sales Tax
void test_get_sales_tax() 
{
    assert(get_sales_tax_amount(10) == 0.675);
    assert(get_sales_tax_amount(20) == 1.35);
}

// Test Case 2: Test Get Tip Amount
void test_get_tip_amount() 
{
    assert(get_tip_amount(20, 15) == 3);
    assert(get_tip_amount(20, 20) == 4);
}
