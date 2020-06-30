#include <string>

class Food
{
protected:
    int quantity{1};           // quantity of the same food item a customer purchases
    std::string size{"small"}; // can have value ‘small’, ‘medium’, or ‘large’

public:
    Food(int quantity1, std::string size1)
    {
        quantity = quantity1;
        size = size1;
    }

    /* Assume that get and set functions for quantity and size are implemented here */

    virtual double getCost() const = 0;
};

class Pizza : public Food
{
private:
    double baseCost{10.00}; // cost on which cost of different pizzas is determined.
                            // Assume baseCost = 10.00$.

public:
    Pizza(int quantity1, std::string size1) : Food(quantity1, size1) {}
    double getCost() const;
};

class Softdrink : public Food
{
private:
    double baseCost{3.00}; // cost on which cost of different softdrinks is determined.
                           // Assume baseCost = 3.00$.

public:
    Softdrink(int quantity1, std::string size1) : Food(quantity1, size1) {}
    double getCost() const;
};
