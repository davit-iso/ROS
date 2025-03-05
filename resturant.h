#ifndef RESTURANT
#define RESTURANT
#include "header.h"
#include "customer.h"
#include "menu.h"
#include "order.h"

class Restaurant {
    private:
        Menu menu;
        std::vector<Customer*> customers;
        std::vector<Order> orders;
    public:
    
        Restaurant();
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        Restaurant& operator=(Restaurant&& other) noexcept;
        ~Restaurant();
        void showMenu() const;
        Customer* getCustomerByName(const std::string& name);
        void placeNewOrder(const std::string& customerName);
        void viewCustomerOrderHistory(const std::string& customerName) const;
        Customer* searchCustomer(const std::string& customerName);
        void createCustomer(const std::string& customerName, const std::string& contactInfo);
        void insertMenu(Menu* menuu);
    };
#endif    