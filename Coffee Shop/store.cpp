#include "store.h"
#include <vector>
#include <sstream>
/*------------Constructor-------*/
Store::Store(std::string store_name): _name{store_name}{ };
std::string Store::name(){return _name;}
/*-------------Inserting Products and Customers*/
void Store::add_customer(Customer* customer){
  _customers.push_back(customer);
}
void Store::add_product(Product* product){
_products.push_back(product);
}
/*-------------Retrieving Number of Products / Customers*/
int Store::number_of_products(){
    return _products.size();
}
int Store::number_of_customers(){
    return _customers.size();

}
/*------------Retrieving the string of both product and customer------=-*/
std::string Store::product_to_string(int product){
    return _products[product]->to_string();

}
std::string Store::customer_to_string(int customer){
    return _customers[customer]->to_string();
}
/*----------Order----------------------*/
Product* Store::get_product(int product){
  return _products[product];
}
void Store::place_order(Order order, int customer){
  _orders.insert(std::make_pair(order,*(_customers[customer])));
}

int Store::number_of_orders(){
  return _orders.size();
}
std::string Store::order_to_string(int order_number){
  std::string send = "";
  std::string status = " Status: ";
  for(auto e : _orders){
    if(e.first.order_number() == order_number){
      if(e.first.completed() == true){
        status+= "Completed ";
      }else{
      if(e.first.paid() == true){
        status+= "Paid ";
      }
      if(e.first.filled() == true){
        status+= "Filled ";
      }
      if(e.first.discarded() == true){
        status+= "Discarded ";
      }
    }
    send+= "Order # " + std::to_string(e.first.order_number())+ status + "\n" + e.first.order_string()  + e.second.to_string();
    }
  }
  return send;
}
/*Order Modifying*/
void Store::pay_order(int order_number){
  std::map<Order,Customer>::iterator it = _orders.begin();
  while(it!= _orders.end()){
    if(it->first.order_number() == order_number){
      Order b{it->first};
      b.pay();
      Customer c = it->second;
      it = _orders.erase(it);
      _orders.insert(std::make_pair(b, c));
    }else{
      it++;
    }
  }
}
bool Store::order_is_paid(int order_number){
  for(auto a : _orders){
    if(a.first.order_number() == order_number){
      return a.first.paid();
    }
  }
}
void Store::fill_order(int order_number){
  std::map<Order,Customer>::iterator it = _orders.begin();
  while(it!= _orders.end()){
    if(it->first.order_number() == order_number){
      Order b{it->first};
      b.fill();
      Customer c = it->second;
      it = _orders.erase(it);
      _orders.insert(std::make_pair(b, c));
    }else{
      it++;
    }
  }
}
bool Store::order_is_filled(int order_number){
  for(auto a : _orders){
    if(a.first.order_number() == order_number){
      return a.first.filled();
    }
  }
}
void Store::discard_order(int order_number){
  std::map<Order,Customer>::iterator it = _orders.begin();
  while(it!= _orders.end()){
    if(it->first.order_number() == order_number){
      Order b{it->first};
      b.discard();
      Customer c = it->second;
      it = _orders.erase(it);
      _orders.insert(std::make_pair(b, c));
    }else{
      it++;
    }
  }
}
bool Store::order_is_discarded(int order_number){
  for(auto a : _orders){
    if(a.first.order_number() == order_number){
      return a.first.discarded();
    }
  }
}

bool Store::order_is_completed(int order_number){
  for(auto a : _orders){
    if(a.first.order_number() == order_number){
      return a.first.completed();
    }
  }
}

bool Store::order_is_pending(int order_number){
  for(auto a : _orders){
    if(a.first.order_number() == order_number){
      return a.first.pending();
    }
  }
}

const Order& Store::find_order_pair(int order_number){
  for(auto &a : _orders){
    if(a.first.order_number() == order_number){
      return  a.first;
    }
  }
}


/*-----get money------*/
double Store::cash(){
  return _cash_register;
}
