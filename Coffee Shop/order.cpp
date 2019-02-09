#include "order.h"
int Order::_next_order_number = 0;
Order::Order(){
  _order_number = _next_order_number;
  _next_order_number++;
}
int Order::order_number()const{
  return _order_number;
}
void Order::pay(){
  if(_is_paid == false && _is_discarded == false){
    _is_paid = true;
  }
}
bool Order::paid()const{
  return _is_paid;
}
void Order::fill(){
  if(_is_filled == false && _is_discarded == false){
    _is_filled  = true;
  }

  //exception code here
}
bool Order::filled()const{
  return _is_filled;
}
void Order::discard(){
  if(_is_discarded == false && _is_filled == false){
    _is_discarded = true;
  }
}
bool Order::discarded()const{
  return _is_discarded;
}

bool Order::pending()const{
  if(_is_discarded == false && _is_paid == false && _is_filled == false){
    return true;
  }else{
    return false;
  }
}
bool Order::completed()const{
  if(_is_paid == true && _is_filled == true){
    return true;
  }else{
    return false;
  }
}

void Order::add_product(Product *product){
  _products.push_back(product);
}
std::string Order::order_string()const{
  std::string send = "";
  for(auto q: _products){
    send+= q->to_string();
    send+= "\n";
  }
    return send;
}
double Order::profit(){
  double profit = 0;
  for(auto q: _products){
    profit+= q->profit();
  }
    return profit;

}

/*Operator Overload----*/
bool Order::operator<(const Order& a)const{
  return _order_number < a.order_number();
}
