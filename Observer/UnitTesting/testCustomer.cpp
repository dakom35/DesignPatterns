#include "testCustomer.h"

// compile me with : g++ -o test.exe .\UnitTesting\testCustomer.cpp Customer.cpp GroceryStore.cpp Observer.cpp Subject.cpp

int main(void){
    GroceryItem itemList[] = {{"Flour", 10}, {"Rice", 10}, {"Brown Bread", 0}, \
                              {"Blueberry Syrup", 0}, {"Detergent", 10}};   
    GroceryStore *groceryStore = new GroceryStore(itemList);
    Customer *customer = new Customer(*groceryStore,"Bjarne");
    test_constructor(customer);


}


void test_constructor(Customer *customer){
    if(customer->getName() == "Bjarne"){
        std::cout << "TEST SUCCESSFUL \n" ;
    }
    else{
        std::cout <<"TEST FAILED \n" ;
    }

}