#include "Observer.h"
#include "GroceryStore.h"

class Customer : public Observer {
 
private:
    GroceryStore &subject_;

public:
    Customer(GroceryStore &subject);
    virtual ~Customer();
    void update(const string &msg);
    void unsubscribeCustomer();
    bool purchaseItem(string itemName,GroceryItem* groceryInventory);

};