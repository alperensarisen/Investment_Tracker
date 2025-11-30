#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(const LinkedList & other){
    copyFrom(other);
}
LinkedList::~LinkedList(){clear();}

void LinkedList::copyFrom(const LinkedList & other){
    clear();
    if(!other.head) return;
    head = new node(other.head->data,nullptr);
    node* temp = other.head->next;
    node* nh = head;
    while(temp){
        nh->next = new node(temp->data,nullptr);
        size++;
        nh = nh->next;
        temp = temp->next;
    }
}
void LinkedList::clear(){
    if(!head) return;
    node* temp = head;
    while(temp){
        node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    size = 0;
    head = nullptr;
}
void LinkedList::printList() const{
    node *temp = head;
    while(temp){
        cout<<"Name: "<<temp->data.getName()<<" Price: "<<temp->data.getPrice()<<endl;
        temp = temp->next;
    }
}
LinkedList &LinkedList::operator=(const LinkedList & rhs){
    if(this != &rhs){
        clear();
        copyFrom(rhs);
    }
    return *this;
}
LinkedList &LinkedList::operator+=(const node & rhs){
    if(!head){
        head = new node(rhs.data,nullptr);
        size = 1;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new node(rhs.data,nullptr);
    size++;
    return *this;
}
LinkedList LinkedList::operator+(const LinkedList &rhs) const{
    LinkedList result(*this);
    node *temp = rhs.head;
    while(temp){
        result += temp->data;
        temp = temp->next;
    }
    return result;
}