#include <iostream>
#include <string>
#include "LinkedList.h"
#include <vector>
//#include <limits>

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "LinkedList.h"

using namespace std;
void manageList(vector<LinkedList> & lists){
    int menu_ch;
    for(int i = 0; i<lists.size();i++){
        cout<<i+1<<". "<<lists[i].getListName()<<endl;
    }
    while(true){
        cout<<"####### MENU #######\n";
        cout<<"1. Add new stock to list\n";
        cout<<"2. Remove stock from list\n";
        cout<<"0. Back to menu\n";
        if(!(cin >> menu_ch)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(menu_ch == 1){
            string stockName;
            double stockPrice;
            int ch;
            //if(ch < lists.size()) continue;
            cout<<"Choose list: ";
            cin>>ch;
            cout<<"Enter stock name: ";
            cin >> stockName;
            cout<<"Enter buy price: ";
            cin >> stockPrice;
            stock s(stockName,stockPrice);
            lists[ch-1] += s;
            cout<<"##################\n";
            cout<<lists[ch-1];
        }
        else if(menu_ch == 2) cout<<"remove\n";
        else if(menu_ch == 0) break;
        else{
            cout<<"Invalid choice!\n";
            continue;
        }
        
    }
}
int main() {
    vector<LinkedList> lists;
    int choice;

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Create new list\n";
        cout << "2. Menage lists\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            // yanlış girişte programı kurtaralım
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // \n temizle

        if (choice == 1) {
            string _listName;
            cout << "Enter list name: ";
            getline(cin, _listName);

            LinkedList newList(_listName);
            lists.push_back(newList);

            cout << "New list has been created: " << _listName << "\n";
        }
        else if (choice == 2) {
            if (lists.empty()) {
                cout << "No list exists. Create one first.\n";
                continue;
            }
            manageList(lists);
        }
        else if (choice == 0) {
            cout << "Bye!\n";
            break;
        }
        else {
            cout << "Unknown option.\n";
        }
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
