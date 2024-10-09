#include "GroceryStore.h"
#include "Customer.h"
#include "Observer.h"
#include "Subject.h"

// compile me with following command : 
// g++ -o main.exe main.cpp GroceryStore.cpp Customer.cpp Observer.cpp Subject.cpp

int main() {
    GroceryItem itemList[] = {{"Flour", 10}, {"Rice", 10}, {"Brown Bread", 0}, \
                              {"Blueberry Syrup", 0}, {"Detergent", 10}};   
    GroceryStore *objGs = new GroceryStore(itemList);
    Customer *objCust = new Customer(*objGs);
    GroceryItem* itemInventory = itemList ;

    objCust->purchaseItem("Detergent", itemInventory);
    objCust->purchaseItem("Flour",itemInventory);
    objCust->purchaseItem("Rice",itemInventory);
    objCust->purchaseItem("Brown Bread",itemInventory);
    objCust->purchaseItem("Blueberry Syrup",itemInventory);

    objGs->refillInventory("Brown Bread",10);
    objCust->purchaseItem("Brown Bread",itemInventory);
    objCust->unsubscribeCustomer();

    objGs->refillInventory("Blueberry Syrup",10);
    
    return 0;
}