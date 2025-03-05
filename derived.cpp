#include "header.h"

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy)
:Dish(dishName,dishPrice),isSpicy(spicy){};

void Appetizer::display() const
{
    std::cout<<name<<" "<<price<<" "<<isSpicy<<std::endl;
}

Entree::Entree(std::string dishName, double dishPrice, int cal)
:Dish(dishName,dishPrice),calories(cal){};

void Entree::display() const
{
    std::cout<<name<<" "<<price<<" "<<calories<<std::endl;
}

Dessert::Dessert(std::string dishName, double dishPrice, bool nuts)
:Dish(dishName,dishPrice),containsNuts(nuts){};

void Dessert::display() const
{
    std::cout<<name<<" "<<price<<" "<<containsNuts<<std::endl;
}