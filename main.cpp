#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main(){
    stock apple("APPL",287.5);
    stock amazon("AMZN",128.3);
    stock google("GOGL",459.4);

    LinkedList myCart;
    myCart += apple;
    myCart += amazon;
    myCart += google;
    myCart.printList();
    return 0;
}