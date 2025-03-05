#include "header.h"
#include "resturant.h"

Restaurant::Restaurant():menu(),orders(),customers(){};

Restaurant::Restaurant(const Restaurant& other)
{
    menu = other.menu;
    for(const auto& c : other.customers)
    {
        customers.push_back(new Customer(*c));
    }
    orders = other.orders;
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
    if(this != &other)
    {
        menu = other.menu;
        for(auto& c : customers)    
        {
            delete c;
        }
        customers.clear();
        for(const auto& c : other.customers)
        {
            customers.push_back(new Customer(*c));
        }
        orders = other.orders;
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
    menu = std::move(other.menu);
    customers = std::move(other.customers);
    other.customers.clear();
    orders = std::move(other.orders);
    other.orders.clear();
}

Restaurant& Restaurant::operator=(Restaurant&& other)noexcept
{
    if(this != &other)
    {
        menu = std::move(other.menu);
        for(auto& c : customers)
        {
            delete c;
        }
        customers.clear();
        customers = std::move(other.customers);
        orders = std::move(other.orders);
    }
    return *this;
}

Restaurant::~Restaurant()
{
    for(auto& c : customers)
    {
        delete c;
    }
}

void Restaurant::showMenu() const
{
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string& name)
{
    for(int i = 0; i < customers.size(); ++i)
    {
        if(customers[i]->getName() == name)
        {
            return customers[i];
        }
    }
    return nullptr;
}

Customer* Restaurant::searchCustomer(const std::string& customerName)
{
    for(int i = 0; i < customers.size(); ++i)
    {
        if(customers[i]->getName() == customerName)
        {
            return customers[i];
        }
    }
    return nullptr;
}

void Restaurant::createCustomer(const std::string& customerName, const std::string& contactInfo)
{
    Customer* cus = new Customer(customerName,contactInfo);
    customers.push_back(cus);
    std::cout<<"Customer "<<cus->getName()<<" is created"<<std::endl;
}

void Restaurant::placeNewOrder(const std::string& customerName)
{
    Customer* customer;
    if(!searchCustomer(customerName))
    {
        std::string ci;
        std::cout<<"Input contact info for creating"<<std::endl;
        std::cin>>ci;
        createCustomer(customerName,ci);
        customer = customers[customers.size()-1];
    }
    else
    {
        customer = searchCustomer(customerName);
    }
    Order ord(customer);
    std::string tmp="ShowMenu";
    while(true)
    {
        std::cout<<"Choose dishes by name or select to finish it"<<std::endl;
        showMenu();
        std::cin>>tmp;
        if(tmp == "select")
        {
            break;
        }
        Dish* d = menu.getDishByName(tmp);
        ord.addDish(d);
    }
    ord.calculateTotal();
}

void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const
{
    for(int i = 0; i < customers.size(); ++i)
    {
        customers[i]->viewOrderHistory();
    }
}