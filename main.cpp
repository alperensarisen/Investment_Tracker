#include <iostream>
#include <string>
#include "LinkedList.h"
#include <vector>


using namespace std;
int main() {
    vector<LinkedList> lists;
    int choice;

    while(true){
        
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buffer temizle

        if(choice == 1){
            string _listName;
            cout << "Enter list name: ";
            getline(cin, _listName);

            LinkedList newList(_listName);
            lists.push_back(newList);

            cout << "New list has been created: " << _listName << "\n";
        }
        else if(choice == 2){
            if(lists.empty()){
                cout << "No list exists. Create one first.\n";
                continue;
            }
            for(int i = 0; i < lists.size(); i++)
                cout << i+1 << ". list: " << lists[i].getListName() << endl;
        }
        else break;
    }
    return 0;
}

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
    ! FIX BUGS
    */
