#include "GroceryStore.h"
#include "Customer.h"
#include "Observer.h"
#include "Subject.h"

int main() {
    GroceryItem itemList[] = {{"Flour", true}, {"Rice", true}, {"Brown Bread", false}, \
                              {"Blueberry Syrup", false}, {"Detergent", true}};   
    GroceryStore *objGs = new GroceryStore(itemList);
    Customer *objCust = new Customer(*objGs);
    GroceryItem* itemInventory = itemList ;

    objCust->purchaseItem("Detergent", itemInventory);
    objCust->purchaseItem("Flour",itemInventory);
    objCust->purchaseItem("Rice",itemInventory);
    objCust->purchaseItem("Brown Bread",itemInventory);
    objCust->purchaseItem("Blueberry Syrup",itemInventory);

    objGs->refillInventory("Brown Bread");
    objCust->purchaseItem("Brown Bread",itemInventory);
    objCust->unsubscribeCustomer();

    objGs->refillInventory("Blueberry Syrup");
    
    return 0;
}