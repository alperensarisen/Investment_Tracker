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
    if(myCart == myFav){
        cout<<"== operator is working\n";
    }
    else cout<<"There is some problem\n";
    LinkedList ObList;
    ObList += tesla;
    cout<<"########################\n";
    cout<<"Operator + test: \n";
    LinkedList trial;
    trial = ObList+myFav;
    trial.printList();
    cout<<"########################\n";
    cout<<trial;
    return 0;
}