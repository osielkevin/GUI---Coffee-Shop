#ifndef DONUT_H
#define DONUT_H
#include "product.h"
//Could've used enum class but for the sake of time I used enum
enum Frosting {Unfrosted, Chocolate_top, Vanilla_top,Pink_Top};
enum Filling {Unfilled, Creme, Bavarian, Strawberry};

//Inheretence is used here. Donut is a Product
class Donut : public Product
{
    public:
        Donut(std::string name, double price, double cost,Frosting frosting,bool sprinkles, Filling filling);
        std::string to_string()override;
        virtual ~Donut();
    protected:
        Frosting _frosting;
        bool _sprinkles;
        Filling _filling;
};

#endif // DONUT_H
