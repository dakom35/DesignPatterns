#ifndef TESTCUSTOMER_H
#define TESTCUSTOMER_H
#include "../Customer.h"

bool test_constructor_name_pass(GroceryStore *groceryStore, std::string name);
bool test_constructor_name_empty(GroceryStore *groceryStore, std::string name);
void interpret_test(bool expected, bool actual, int num);

#endif 