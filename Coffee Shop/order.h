#ifndef ORDER_H
#define ORDER_H
#include "product.h"
#include <vector>
#include <map>
class Order
{
    public:
      Order();
      int order_number()const;
      void add_product(Product *product);
      bool paid()const;
      void pay();
      bool filled()const;
      void fill();
      bool discarded()const;
      void discard();
      bool pending()const;
      bool completed()const;
      bool operator<(const Order& a)const;
      std::string order_string()const;
      double profit();


    protected:
      std::vector<Product *> _products;

    private:
      int _order_number;
      bool _is_discarded = false;
      bool _is_paid = false;
      bool _is_filled = false;
      int static _next_order_number;
};

#endif // ORDER_H
