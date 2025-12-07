#include <iostream>
#include <string>
#include "LinkedList.h"
#include <vector>
#include <fstream>
//#include <limits>

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "LinkedList.h"

using namespace std;
class person{
    private:
        string _name;
        string _pass;
        double totalBalance;
        vector<LinkedList> *_lists;
    public:
        person():_name(""),_pass(""),totalBalance(0.0),_lists(nullptr){}
        person(string n,string p, double b, vector<LinkedList> *l):
        _name(n),_pass(p),totalBalance(b),_lists(l){}

        string getName() const{return _name;}
        string getPass() const{return _pass;}
        double getBalance() const{return totalBalance;}

        void setList(vector<LinkedList> *l){_lists = l;}
        bool isValid() const{return !_name.empty() && !_pass.empty();}
        vector<LinkedList> &getList(){return *_lists;}

};

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
        else if(menu_ch == 2){
            int rmv_list;
            int dltElement;
            cout<<"Choose list: ";
            cin>>rmv_list;
            cout<<lists[rmv_list-1];
            cout<<"Choose element to delete: ";
            cin >> dltElement;
            lists[rmv_list-1].removeAt(dltElement);
            break;


        }
        else if(menu_ch == 0) break;
        else{
            cout<<"Invalid choice!\n";
            continue;
        }
        
    }
}
void getData(vector<person> &users){
    ifstream file("database.txt");
    string _name, _pass;
    if(!file.is_open()){
        cout<<"There is a problem about .txt file !\n";
        return;
    }
    while(file >> _name >> _pass){
        cout<<". ";
        if(!_name.empty() && !_pass.empty()){
            person p(_name,_pass,0.0,nullptr);
            users.push_back(p);
            #ifdef _DEBUG
                cout<<"New person: "<<_name<<" | password: "<<_pass<<endl;
                cout<<"Has been created!\n";
            #endif
        }
        
    }
    cout<<endl;
    file.close();
}
int main() {
    vector<LinkedList> lists;
    vector<person> users;
    
    int choice;
    person currentUser;
    string pass, name;
    getData(users);
    while(true){
        cout<<"##### FINANCE APP #####\n";
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter password: ";
        cin>>pass;
        for(int i = 0; i<users.size();i++){
            if(name == users[i].getName() && pass == users[i].getPass()){
                currentUser = users[i];
                #ifdef _DEBUG
                    cout<<"user with given information found.\n";
                #endif
            }
                
        }
        if(!currentUser.isValid()){
            cout<<"No user found with given informations.\n";
            continue;
        }
        
        vector<LinkedList> *lst = new vector<LinkedList>;
        currentUser.setList(lst);
        break;
        
    }
    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Create new list\n";
        cout << "2. Menage lists\n";
        cout << "3. Show lists and stocks\n";
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
            currentUser.getList().push_back(newList);

            cout << "New list has been created: " << _listName << "\n";
        }
        else if (choice == 2) {
            if (currentUser.getList().empty()) {
                cout << "No list exists. Create one first.\n";
                continue;
            }
            manageList(currentUser.getList());
        }
        else if (choice == 3){
            for(int i = 0; i<currentUser.getList().size(); i++){
                cout<<currentUser.getList()[i];
            }
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
    TODO: Check all functions are functional
    TODO: Save lists datas to database or txt file 
    TODO: Improve terminal UI
    TODO: Add quantity to stocks and create user balance
    * Show also user name before printing lists
    ? Add some important functions into person class
    */
