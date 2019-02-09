#ifndef STORE_H
#define STORE_H
#include "product.h"
#include <vector>
#include "donut.h"
#include "java.h"
#include "customer.h"
#include "order.h"
#include <map>
class Store
{
    public:
        /*------Store things*/
        Store(std::string store_name);
        std::string name();
        /*------Manipulating Capsulation*/
        void add_product(Product* product);
        void add_customer(Customer* customer);
        /*-----Retrieving size of vectors*/
        int number_of_products();
        int number_of_customers();
        /*Retrieving string of private variables*/
        std::string product_to_string(int product);
        std::string customer_to_string(int customer);
        double cash();
        /*-----Orders----------*/
        Product* get_product(int product);
        void place_order(Order order, int customer);
        int number_of_orders();
        std::string order_to_string(int order_number);
        void pay_order(int order_number);
        bool order_is_paid(int order_number);
        void fill_order(int order_number);
        bool order_is_filled(int order_number);
        void discard_order(int order_number);
        bool order_is_discarded(int order_number);
        bool order_is_completed(int order_number);
        bool order_is_pending(int order_number);
        const Order& find_order_pair(int order_number);
        /*Overload*/


    protected:
        std::string _name;
        std::vector<Product*> _products;
        std::vector<Customer*> _customers;
        std::map<Order,Customer> _orders;
        double _cash_register = 10000;
};

#endif // STORE_H
