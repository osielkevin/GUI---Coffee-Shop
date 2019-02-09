#include "product.h"
#include <iostream>
Product::Product(std::string name, double price, double cost) : _name{name}, _price{price}, _cost{cost}{ };
std::string Product::name(){
return _name;
}
std::string Product::to_string(){
return " ";
}
double Product::profit(){
  double profit;
  profit = _price - _cost;
  return profit;
}
