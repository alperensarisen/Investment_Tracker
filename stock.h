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
        string getName() const{return name;};
        double getPrice() const{return B_price;};

};
#endif