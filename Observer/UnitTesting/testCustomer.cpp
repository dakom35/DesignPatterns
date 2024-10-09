#include "testCustomer.h"

// compile me with : g++ -o test.exe .\UnitTesting\testCustomer.cpp Customer.cpp GroceryStore.cpp Observer.cpp Subject.cpp

int main(void){
    GroceryItem itemList[] = {{"Flour", 10}, {"Rice", 10}, {"Brown Bread", 0}, \
                              {"Blueberry Syrup", 0}, {"Detergent", 10}};   
    GroceryStore *groceryStore = new GroceryStore(itemList);
    bool res = test_constructor_name_pass(groceryStore,"John ColdTrain");
    interpret_test(true,res,0);
    res = test_constructor_name_empty(groceryStore);
    interpret_test(true,res,1);


}

// Constructor tests


/*  @brief Tests the case where a valid name is used to initialize the Customer instance via the constructor
*
*   @param groceryStore pointer to the groceryStore (publisher/subject) used
*   @param name string that should contain a valid name to initialize the Customer instance via its constructor. 
*   @return bool True if the name entered in the constructor is actually defining the name_ attribute of the customer instance. 
*
*   @warning You shouldn't use this test to see what happens when you use an empty string. test_constructor_name_empty() is there for that.
*   
*/ 
bool test_constructor_name_pass(GroceryStore *groceryStore, std::string name){
    Customer *customer = new Customer(*groceryStore,name);
    if(customer->getName() == name){
        return true ;
    }
    else{
        return false ; 
    }
}


/*  @brief Tests the case where an empty string is used for the name in the constructor
*
*   @param groceryStore pointer to the groceryStore (publisher/subject) used
*   @return bool True if the getter returns "AnonymousCustomer". Else, false.
*   
*/ 
bool test_constructor_name_empty(GroceryStore *groceryStore){
    Customer *customer = new Customer(*groceryStore,"");
    if(customer->getName() == "AnonymousCustomer"){
        return true ;
    }
    else{
        return false ; 
    }
}

/*  @brief Interprets the result of a test.
*
*   Compares the expected result with the actual result to determine 
*   if the test is successful or not. 
*   
*   @param expected The expected result of the test
*   @param actual The actual result returned by the test method
*   @param num The test number
*   @return void
*   
*/ 
void interpret_test(bool expected, bool actual, int num){
    if(expected == actual){
        std::cout << "TEST #"<<num<<" SUCCESSFUL \n" ;
    }
    else{
        std::cout << "TEST #"<<num<<" FAILED \n" ;
    }
}