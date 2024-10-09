#include <iostream>
#include <list>
#include <string>
#include "GroceryStore.h"


GroceryStore::GroceryStore(GroceryItem* grocery) {
    for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
        groceryItems[i].itemName = grocery[i].itemName;
        groceryItems[i].quantity = grocery[i].quantity;
    }
}

GroceryStore::~GroceryStore() {
    cout << "Goodbye, I was the Subject.\n";
}

void GroceryStore::subscribe(Observer *observer) {
    cout << "An observer has subscribed\n";
    list_observer.push_back(observer);
}

void GroceryStore::unsubscribe(Observer *observer) {
    cout << "A customer has unsubscribed\n";
    list_observer.remove(observer);
}

void GroceryStore::notify(string msg) {
    list<Observer *>::iterator iterator = list_observer.begin();

    while (iterator != list_observer.end()) {
        cout << "GroceryStore is sending an update to the customer\n";
        (*iterator)->update(msg);
        ++iterator;
    }
}

void GroceryStore::refillInventory(string itemName, int quantity) {
    for (int i = 0; i < TOTAL_GROCERY_ITEMS; i++) {
        if (itemName == groceryItems[i].itemName) {
            groceryItems[i].quantity = quantity;
            cout << "Refilling the stock for item " << itemName << "\n";
            notify(("Item " + itemName + " has been refilled in the Grocery Store"));
        }
    }
}





