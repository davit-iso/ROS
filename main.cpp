#include "header.h"
#include "derived.h"
#include "order.h"
#include "customer.h"
#include "dish.h"
#include "menu.h"

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
}