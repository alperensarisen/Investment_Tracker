#ifndef STOCK_H_
#define STOCK_H_
#include <string>
using namespace std;
class stock{
    private:
        string name;
        double B_price;
    public:
        stock(string n, double p):name(n),B_price(p){}
        string getName() const;
        double getPrice() const;

};
string stock::getName() const{return name;}
double stock::getPrice() const{return B_price;}
#endif