#include "GroceryStore.h"
#include "Customer.h"
#include "Observer.h"
#include "Subject.h"

// compile me with following command : 
// g++ -o main.exe main.cpp GroceryStore.cpp Customer.cpp Observer.cpp Subject.cpp

int main() {
    GroceryItem itemList[] = {{"Flour", 10}, {"Rice", 10}, {"Brown Bread", 0}, \
                              {"Blueberry Syrup", 0}, {"Detergent", 10}};   
    GroceryStore *groceryStore = new GroceryStore(itemList);
    Customer *customer = new Customer(*groceryStore,"Bjarne");
    GroceryItem* itemInventory = itemList ;

    customer->purchaseItem("Detergent", itemInventory,3);
    customer->purchaseItem("Flour",itemInventory,3);
    customer->purchaseItem("Rice",itemInventory,4);
    customer->purchaseItem("Brown Bread",itemInventory,5);
    customer->purchaseItem("Blueberry Syrup",itemInventory,7);

    groceryStore->refillInventory("Brown Bread",10);
    customer->purchaseItem("Brown Bread",itemInventory,8);
    customer->unsubscribeCustomer();

    groceryStore->refillInventory("Blueberry Syrup",10);
    
    return 0;
}