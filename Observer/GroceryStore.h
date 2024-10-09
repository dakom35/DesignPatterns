#ifndef GROCERYSTORE_H
#define GROCERYSTORE_H
#include <iostream>
#include <list>
#include <string>
#include "Subject.h"


#define TOTAL_GROCERY_ITEMS 5


struct GroceryItem {
    std::string itemName;
    int quantity;
};


/**
 * GroceryStore is the Subject/Publisher here that owns some important
 * state and notifies observers (i.e. customers) when the state changes.
 */
class GroceryStore : public Subject {

private:
    std::list<Observer *> list_observer;
    GroceryItem groceryItems[TOTAL_GROCERY_ITEMS];

public:
    GroceryStore(GroceryItem* grocery);
    
    virtual ~GroceryStore();
    void subscribe(Observer *observer);
    void unsubscribe(Observer *observer);
    void notify(std::string msg);
    void refillInventory(std::string itemName, int quantity);

};


#endif
