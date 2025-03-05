#include "header.h"
#include "order.h"
#include "customer.h"
#include "dish.h"

Order::Order(Customer* customer):
customer(customer){};

Order::Order(const Order& other)
{
    customer = other.customer;
    orderedDishes = other.orderedDishes;
    totalPrice = other.totalPrice;
}

Order& Order::operator=(const Order& other)
{
    if(this != &other)
    {
        customer = other.customer;
        orderedDishes = other.orderedDishes;
        totalPrice = other.totalPrice;
    }
    return *this;
}

Order::Order(Order&& other) noexcept
{
    customer = other.customer;
    orderedDishes = std::move(other.orderedDishes);
    totalPrice = other.totalPrice;
    other.customer = nullptr;
    other.totalPrice = 0;
}

Order& Order::operator=(Order&& other) noexcept
{
    if(this != &other)
    {
        customer = other.customer;
        orderedDishes = std::move(other.orderedDishes);
        totalPrice = other.totalPrice;
        other.customer = nullptr;
        other.totalPrice = 0;
    }
    return *this;
}

void Order::addDish(Dish* dish)
{
    orderedDishes.push_back(dish);
}

void Order::calculateTotal()
{
    for(int i = 0; i < orderedDishes.size(); ++i)
    {
        totalPrice += orderedDishes[i]->getPrice();
    }
    std::cout<<"The order value is "<<totalPrice<<std::endl;
}

void Order::displayOrder() const
{
    for(int i = 0; i < orderedDishes.size(); ++i)
    {
        orderedDishes[i]->display();
    }
}