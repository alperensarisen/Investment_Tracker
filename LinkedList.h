#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "stock.h"
#include <iosfwd>
struct node
{
    stock data;
    node *next;
    node(stock d, node* n = nullptr):data(d),next(n){}
};
class LinkedList{
    private:
        
        node *head;
        int size;
    public:
        LinkedList():head(nullptr),size(0){}   //Default constructor
        LinkedList(node *h, int s):head(h),size(s){}
        LinkedList(const LinkedList & other);
        ~LinkedList();

        void copyFrom(const LinkedList &other);
        void clear();
        void printList() const;
        
        LinkedList &operator=(const LinkedList & rhs);
        LinkedList &operator+=(const node & rhs);
        LinkedList operator+(const LinkedList & rhs) const;
        bool operator==(const LinkedList &rhs) const;
        friend ostream &operator<<(ostream &out, const LinkedList & list);
};
#endif