#include "Customer.h"
 
Customer::Customer(GroceryStore &subject, std::string name) : subject_(subject), name_(name) {
    if(name_ == "") name_ = "AnonymousCustomer" ;
    this->subject_.subscribe(this) ;
}

Customer::~Customer() {
    std::cout << "Goodbye, I was an implementation of the Observer called " << this->name_<< ".\n";
}

void Customer::update(const std::string &msg) {
    std::cout << "Hey " << this->name_ << "! A new message is available --> " << msg << "\n";
}

void Customer::unsubscribeCustomer() {
    std::cout << this->name_ << " unsubscribes from Grocery Store";
    subject_.unsubscribe(this);
}

bool Customer::purchaseItem(std::string itemName, GroceryItem* groceryInventory) {
    std::cout << this->name_ <<" wants to purchase item " << itemName << " - ";
    for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
        if (itemName == groceryInventory[i].itemName) {
            if (groceryInventory[i].quantity > 0) {
                groceryInventory[i].quantity--;
                std::cout << "Item " << itemName << " is available\n";
                return true;
            }
        }
    }
    std::cout << "The item " << itemName << " is not available in the Grocery Store\n"; 
    return false;
}

// Getter for subject_
GroceryStore& Customer::getSubject() {
    return subject_;
}

// Getter for name_
std::string Customer::getName() {
    return name_;
}

// Setter for name_
void Customer::setName(std::string &name) {
    name_ = name;
}

