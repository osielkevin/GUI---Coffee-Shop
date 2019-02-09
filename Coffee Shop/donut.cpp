#include "donut.h"
#include <sstream>
//This function uses a constructor and chains it with a previous constructor that was made with products.
Donut::Donut(std::string name, double price, double cost,Frosting frosting,bool sprinkles, Filling filling):Product{name, price, cost}, _frosting{frosting}, _sprinkles{sprinkles},_filling{filling}{ };


//This function used for printing puproses on the format of the GUI
std::string Donut::to_string(){
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
    std::string word = "Type: DONUT, Name: ";
    word += Product::name();
    word+=", Price: $";
    word+=price;
    word+=", Cost: $";
    word+=cost;
    word+=", Frosting: ";
    switch(_frosting){
    case Frosting::Unfrosted:
        word+="Unfrosted";
        break;
    case Frosting::Chocolate_top:
        word+="Chocolate_top";
        break;
    case Frosting::Vanilla_top:
        word+="Vanilla_top";
        break;
    case Frosting::Pink_Top:
        word+="Pink_top";
        break;
    }
    word+=", Filling: ";
    switch(_filling){
    case 0:
        word+= "Unfilled";
        break;
    case 1:
        word+= "Creme";
        break;
    case 2:
        word+= "Bavarian";
        break;
    case 3:
        word+= "Strawberry";
        break;
    }
    if(_sprinkles == true){
      word+= " , Has Sprinkles";
    }else{
      word+= " , No Sprinkles";
    }
    return word;
}
//Destructor
Donut::~Donut(){}
