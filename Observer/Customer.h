#include "Observer.h"
#include "GroceryStore.h"

class Customer : public Observer {
 
private:
    GroceryStore &subject_;
    std::string name_ ;

public:
    Customer(GroceryStore &subject, std::string name);
    virtual ~Customer();
    void update(const std::string &msg);
    void unsubscribeCustomer();
    bool purchaseItem(std::string itemName,GroceryItem* groceryInventory);

};