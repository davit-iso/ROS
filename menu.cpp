#include "header.h"
#include "order.h"
#include "customer.h"
#include "dish.h"
#include "menu.h"

Menu::Menu(const Menu& other)
{
    for(int i = 0; i < other.dishes.size(); ++i)
    {
        for(auto& d : other.dishes)
        {
            dishes.push_back(new Dish(*d));
        }
    }
}

Menu& Menu::operator=(const Menu& other)
{
    
    if(this != &other)
    {
        for(auto& d : dishes)
        {
            delete d;
        }
        dishes.clear();
        for(auto& d : other.dishes)
        {
            dishes.push_back(new Dish(*d));
        }
    }
    return *this;
}

Menu::Menu(Menu&& other) noexcept
{
    dishes = std::move(other.dishes);
}

Menu& Menu::operator=(Menu&& other) noexcept
{
    if(this != &other)
    {
        dishes = std::move(other.dishes);
    }
    return *this;
}

Menu::~Menu()
{
    for(int i = 0; i < dishes.size(); ++i)
    {
        delete dishes[i];
    }
}

void Menu::addDish(Dish* dish)
{
    dishes.push_back(dish);
}

void Menu::displayMenu() const
{
    std::cout<<"Menu include"<<std::endl;
    for(int i = 0; i < dishes.size(); ++i)
    {
        std::cout<<i<<" - ";
        dishes[i]->display();
    }
}

Dish* Menu::getDishByName(const std::string& dishName) const
{
    for(int i = 0; i < dishes.size(); ++i)
    {
        if(dishes[i]->getName() == dishName)
        {
            return dishes[i];
        }
    }
}