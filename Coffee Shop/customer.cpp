#include "customer.h"
#include <iostream>
Customer::Customer(std::string customer, std::string customer_phone): _customer{customer},_customer_phone{customer_phone}{ };

std::string Customer::to_string(){
  std::string name = "Name: ";
  name+= _customer;
  name+=" Phone: ";
  name+= _customer_phone;
  name+= "\n";
  return name;
}
