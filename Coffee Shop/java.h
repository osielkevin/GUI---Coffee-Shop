#ifndef JAVA_H
#define JAVA_H
#include <vector>
#include "product.h"
//Used enum for the sake of programming faster.
enum Shot{None,Chocolate,Vanilla,Peppermint,Hazzelnut};
enum Darkness{Blonde, Light, Medium, Dark,Extra_dark};
//Java is a product. Inheretence is used. Parent is product.
class Java : public Product
{
    public:
        Java(std::string name, double price, double cost,Darkness darkness);
        void add_shot(Shot shot);
        std::string to_string()override;
        virtual ~Java();

    protected:
        Darkness _darkness;
        std::vector<Shot> _shots;
};

#endif // JAVA_H
