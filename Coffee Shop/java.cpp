#include "java.h"
#include <sstream>
#include <vector>
//Used Chain Constructor to make an object of type Java.
Java::Java(std::string name, double price, double cost, Darkness darkness): Product{name, price, cost}, _darkness{darkness} { };
void Java::add_shot(Shot shot){
    _shots.push_back(shot);
}

//Destructor
Java::~Java(){}

//To string function helps for printing out for the GUI.
std::string Java::to_string(){
int i;
std::stringstream sso;
std::string price;
std::stringstream ssi;
std::string cost;
sso.precision(2);
ssi.precision(2);
sso<<std::fixed<<_price;
ssi<<std::fixed<<_cost;
sso>>price;
ssi>>cost;
std::string enter = "Type: JAVA, Name: ";
enter += Product::name();
enter+=", Price: $";
enter+=price;
enter+=", Cost: $";
enter+=cost;
enter+=", Darkness: ";
ssi.clear();
switch(_darkness){
  case 0:
    enter+= "Blonde";
    break;
  case 1:
    enter+="Light";
    break;
  case 2:
    enter+="Medium";
    break;
  case 3:
    enter+="Extra Dark";
    break;
}
enter+=", Shots: ";
for(i = 0; i < _shots.size(); i++){
    switch(_shots[i]){
case 0:
    break;
case 1:
    enter+=" Chocolate,";
    break;
case 2:
    enter+=" Vanilla,";
    break;
case 3:
    enter+= " Peppermint,";
    break;
case 4:
    enter+= " Hazelnut,";
    break;

    }
}
return enter;
}
