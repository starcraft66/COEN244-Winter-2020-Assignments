#include "food.hpp"
#include <string>

class CustomerOrder
{
private:
    std::string customerName; // customer name
    int orderNum;             // order number
    Food *orderedItems[6];    // stores pointers to food items, ordered by the customer
                              // Assume a max of 6 items can be ordered
public:
    CustomerOrder(int orderNum1, std::string customerName1)
    {
        orderNum = orderNum1;
        customerName = customerName1;
        for (int i = 0; i < 6; i++)
        orderedItems[i] = nullptr;
    }

    /* Assume copy constructor and destructor are defined here */

    /* Getters and setters */

    int getOrderNum() const { return orderNum; }
    std::string getCustomerName() const { return customerName; }
    void setCustomerName(std::string customerName1) { customerName = customerName1; }

    /* Assume the functions isFull() and isEmpty()  below are implemented */

    bool isFull() const;  // returns true if the array orderedItems is full; false otherwise
    bool isEmpty() const; // returns true if the array orderedItems is empty; false otherwise

    /* You will be asked to implement some of the functions below */

    void addFoodItem(Food *);
    void removeFoodItem(Food *);

    double getOrderCost() const;

    friend std::ostream &operator<<(std::ostream &, const CustomerOrder &);
};
