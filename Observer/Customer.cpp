#include "Customer.h"
 
Customer::Customer(GroceryStore &subject) : subject_(subject) {
    this->subject_.subscribe(this);
}

Customer::~Customer() {
    std::cout << "Goodbye, I was an implementation of the Observer called Customer.\n";
}

void Customer::update(const string &msg) {
    std::cout << "Hey customer! A new message is available --> " << msg << "\n";
}

void Customer::unsubscribeCustomer() {
    std::cout << "Customer wants to unsubscribe the Grocery Store notifications - ";
    subject_.unsubscribe(this);
}

bool Customer::purchaseItem(string itemName,GroceryItem* groceryInventory) {
    std::cout << "Customer wants to purchase item " << itemName << " - ";
    for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
        if (itemName == groceryInventory[i].itemName) {
            if (groceryInventory[i].quantity > 0) {
                groceryInventory[i].quantity--;
                cout << "Item " << itemName << " is available\n";
                return true;
            }
        }
    }
    std::cout << "The item " << itemName << " is not available in the Grocery Store\n"; 
    return false;
}

