#include "header.h"
#include "derived.h"
#include "order.h"
#include "customer.h"
#include "dish.h"
#include "menu.h"
#include "resturant.h"

int main()
{
    Menu menu;
    Appetizer* ap = new Appetizer("ap",15.7,true);
    Entree* en = new Entree("en",12.8,105);
    Dessert* de = new Dessert("de",22.7,true);
    menu.addDish(ap);
    menu.addDish(en);
    menu.addDish(de);
    menu.displayMenu();
    std::cout<<"test"<<std::endl;
    Restaurant res;
    res.showMenu();
    res.insertMenu(&menu);
    res.showMenu();
    Dessert* dde = new Dessert("dde",12.2,false);
    std::cout<<"Test 2"<<std::endl;
    menu.addDish(dde);
    res.insertMenu(&menu);
    res.showMenu();
    res.placeNewOrder("John");
}