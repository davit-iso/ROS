#ifndef CUSTOMER
#define CUSTOMER
#include "header.h"
#include "order.h"

class Customer {
    private:
        std::string name;
        std::string contactInfo;
        std::vector<Order> orderHistory;
    public:
        Customer(std::string customerName, std::string contact);
        Customer(const Customer& other);
        Customer& operator=(const Customer& other);
        Customer(Customer&& other) noexcept;
        Customer& operator=(Customer&& other) noexcept;
        ~Customer() = default;
        void placeOrder(Order order);
        void viewOrderHistory() const;
        std::string getName() const;
    };
#endif