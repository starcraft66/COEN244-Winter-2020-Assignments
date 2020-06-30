#include "customerorder.hpp"
#include <iostream>

void CustomerOrder::addFoodItem( Food * item ) {
    bool inserted = false;
    for (Food*& food : this->orderedItems)
    {
        if (food == nullptr)
        {
            food = item;
            inserted = true;
            return;
        }
    }
    try
    {
        if (inserted == false)
        {
            throw "Array is full, order cannot be completed";
        }
    }
    catch (const char* ex)
    {
        std::cout << ex;
    }
}

double CustomerOrder::getOrderCost( ) const {
    double cost = 0.0;
    for (auto const& food : this->orderedItems)
    {
        if (food != nullptr)
        {
            cost += food->getCost();
        }
    }
    return cost;
}

std::ostream& operator<<( std::ostream& out, const CustomerOrder& order)  {
    int items = 0;
    for (auto const& food : order.orderedItems)
    {
        if (food != nullptr)
        {
            items++;
        }
    }
    return out << order.getOrderNum() << " " << order.getCustomerName() << " " << items << " " << order.getOrderCost();
}
