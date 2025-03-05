#ifndef DERIVED
#define DERIVED
#include "header.h"
#include "dish.h"

class Appetizer : public Dish 
{
    private:
        bool isSpicy;
    public:
        Appetizer(std::string dishName, double dishPrice, bool spicy);
        void display() const;
    };
    class Entree : public Dish {
        private:
            int calories;
        public:
            Entree(std::string dishName, double dishPrice, int cal);
            void display() const;
        };
        class Dessert : public Dish {
        private:
            bool containsNuts;
        public:
            Dessert(std::string dishName, double dishPrice, bool nuts);
            void display() const;
        };
            

#endif