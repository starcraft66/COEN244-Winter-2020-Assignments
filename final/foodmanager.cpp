#include "foodmanager.hpp"
#include <iostream>

void FoodManager::getOrder(int orderNumber1, std::string customerName1) const
{

    std::string request;
    int quantity1;
    std::string size1;
    Food *itemPtr = nullptr;

    CustomerOrder *myOrder = new CustomerOrder(orderNumber1, customerName1);

    std::cout << "Enter the following to order a menu item or terminate an order" << std::endl;
    std::cout << "Enter Pizza, Softdrink or End" << std::endl;

    std::cin >> request;

    while (request != "End")
    {
        // New menu item
        std::cout << "Enter quantity: " << std::endl;
        std::cin >> quantity1;

        std::cout << "Enter size (small, medium or large): " << std::endl;
        std::cin >> size1;

        // Complete this part
        // Create the requested menu item object using dynamic memory allocation and add it
        // to the customer object.

        if (request == "Pizza")
        {
            Pizza *p = new Pizza(quantity1, size1);
            myOrder->addFoodItem(p);
        }
        else if (request == "Softdrink")
        {
            Softdrink *s = new Softdrink(quantity1, size1);
            myOrder->addFoodItem(s);
        }

        std::cout << "Enter the next menu item to order or terminate an order" << std::endl;
        std::cout << "Enter Pizza, Softdrink or End" << std::endl;
        std::cin >> request;
    }
}
