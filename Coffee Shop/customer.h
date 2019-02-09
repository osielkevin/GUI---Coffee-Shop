#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
class Customer{
  public:
    Customer(std::string customer, std::string customer_phone);
    std::string to_string();
  private:
    std::string _customer;
    std::string _customer_phone;
};



#endif // JAVA_H
