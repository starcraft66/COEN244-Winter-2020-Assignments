#include <string>
#include "customerorder.hpp"

class FoodManager
{
private:
    CustomerOrder *orders[50]; // stores pointers to CustomerOrder objects;
                               // Assume maximum number of orders is 50
public:
    FoodManager()
    {
        for (int i = 0; i < 50; i++)
            orders[i] = nullptr;
    }

    /*  Assume  the following functions for adding and removing customer orders are defined */

    void addOrder(CustomerOrder *);
    void removeOrder(CustomerOrder *);

    /* You will be asked to implement some of the following functions */

    double getTotalSales() const;    // returns total sales of the restaurant
    void getOrder(int, std::string) const; // receives order from a customer
};
