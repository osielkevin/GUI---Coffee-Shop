#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
    public:
        Product(std::string name, double price, double cost);
        std::string name();
        virtual std::string to_string();
        double profit();

    protected:
        std::string _name;
        double _price;
        double _cost;
};

#endif // PRODUCT_H
