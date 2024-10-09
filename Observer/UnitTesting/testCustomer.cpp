#include "testCustomer.h"

// compile me with : g++ -o test.exe .\UnitTesting\testCustomer.cpp Customer.cpp GroceryStore.cpp Observer.cpp Subject.cpp

int main(void){
    GroceryItem itemList[] = {{"Flour", 10}, {"Rice", 10}, {"Brown Bread", 0}, \
                              {"Blueberry Syrup", 0}, {"Detergent", 10}};   
    GroceryStore *groceryStore = new GroceryStore(itemList);
    bool res = test_constructor_name_pass(groceryStore,"John ColdTrain");
    interpret_test(true,res,0);
    res = test_constructor_name_empty(groceryStore,"");
    interpret_test(true,res,1);


}

// Constructor tests
bool test_constructor_name_pass(GroceryStore *groceryStore, std::string name){
    Customer *customer = new Customer(*groceryStore,name);
    if(customer->getName() == name){
        return true ;
    }
    else{
        return false ; 
    }
}

bool test_constructor_name_empty(GroceryStore *groceryStore, std::string name){
    Customer *customer = new Customer(*groceryStore,name);
    if(customer->getName() == "AnonymousCustomer"){
        return true ;
    }
    else{
        return false ; 
    }
}


void interpret_test(bool expected, bool actual, int num){
    if(expected == actual){
        std::cout << "TEST #"<<num<<" SUCCESSFUL \n" ;
    }
    else{
        std::cout << "TEST #"<<num<<" FAILED \n" ;
    }
}