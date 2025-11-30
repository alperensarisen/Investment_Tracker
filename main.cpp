#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main(){
    stock apple("APPL",287.5);
    stock amazon("AMZN",128.3);
    stock google("GOGL",459.4);
    stock tesla("TSLA",345.8);
    cout<<"MYCART: \n";
    LinkedList myCart;
    myCart += apple;
    myCart += amazon;
    myCart += google;
    myCart.printList();
    LinkedList myFav;
    myFav = myCart;
    cout<<"MYFAV:\n";
    myFav.printList();
    LinkedList ObList;
    ObList += tesla;
    cout<<"Operator + test: \n";
    LinkedList trial;
    trial = ObList+myFav;
    trial.printList();
    return 0;
}