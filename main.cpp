#include <iostream>
#include <string>
#include "LinkedList.h"
#include <vector>
using namespace std;
void CreateList(vector<LinkedList> & list){
    string _listName;
    cout<<"Enter list name:";
    
    getline(cin, _listName);
    cin.ignore();
    LinkedList newList(_listName);
    list.push_back(newList);
    cout<<"New list has been created.\n";
}
void addStock(vector<LinkedList> & list){
    for(int i = 0; i<list.size();i++){
        cout<<i+1<<". list: "<<list[i].getListName()<<endl;
    }
}
int main(){
    vector<LinkedList> lists;
    int choice;
    while(true){
        cout<<"1. Create List\n";
        cout<<"2. Add Stock\n";
        cout<<"3. Exit\n";
        cin>>choice;
        if(choice == 1){
            CreateList(lists);
            continue;
        }
        else if(choice == 2){
            addStock(lists);
            continue;
        }
        else{break;}
    }
    
    return 0;
    /*
    TODO: Clean main.cpp and start basic UI
    * create list
        ? list name
        ? back
    * add stock
        ? choose list
            ! enter name 
            ! enter price
        ? back
    ! CONVERT IT VECTOR TO POINTER VECTOR
    */
}