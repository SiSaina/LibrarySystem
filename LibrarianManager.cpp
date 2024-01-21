#pragma once
#include <iostream>
#include <vector>
#include "LibrarianAccount.cpp"
#include "InputValidation.cpp"

using namespace std;

class LibrarianManager {
private:
    vector<LibrarianAccount*> LA;
    InputValidation val;

	void findMenu(){
		cout << "==============FIND MENU=============="<<endl;
		cout << "1. Find by ID"<<endl;
		cout << "2. Find by name"<<endl;
	}
public:
    ~LibrarianManager(){
        for(auto& acc : LA){
		delete acc;
		}
    }

    void addAccount(){
        LibrarianAccount* acc = new LibrarianAccount();
        acc->input();
        LA.push_back(acc);
    }

    void viewAllAccount(){
        if (LA.empty()) {
        cout << "No accounts to display." << endl;
        return;
    }
    cout << "----------------------------------------LIBRARIAN ACCOUNT------------------------------------------" << endl;
    cout << "ID" << "\t" << setw(30) << left << "Name" << "\t" << "Wage($/day)" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    for (const LibrarianAccount* acc : LA) {
        acc->output();
        cout << endl;
    }
    }

    void updateSingleDetail(LibrarianAccount* acc){
        cout<<"==============UPDATE MENU=============="<<endl;
        cout<<"1. Update ID"<<endl;
        cout<<"2. Update name"<<endl;
        cout<<"3. Update wage"<<endl;
        int choice=val.enterChoice();
        switch (choice) {
        case 1:{
            int id=val.enterID();
            acc->setID(id);
            break;
        }
        case 2:{
            string name=val.enterName();
            acc->setName(name);
            break;
        }
        case 3:{
            double wage=val.enterWage();
            acc->setWage(wage);
            break;
        }
        default:
            cout<<"Error: INVALID INPUT"<<endl;
            break;
        }
    }
    void updateAllDetail(LibrarianAccount* acc){
        cout<<"==============UPDATE MENU=============="<<endl;
		acc->input();
    }
    void updateHandleMenu(LibrarianAccount* acc) {
        cout << "==============UPDATE MENU=============="<<endl;
        cout << "1. Update a single detail"<<endl;
        cout << "2. Update all detail"<<endl;
        int option = val.enterChoice();
            switch (option) {
                case 1:
                    updateSingleDetail(acc);
                    break;
                case 2:
                    updateAllDetail(acc);
                    break;
                default:
                    cout << "Error: INVALID INPUT" << endl;
                    break;
            }
    }
    void updateAccount(LibrarianAccount* acc){
        findMenu();
        int choice=val.enterChoice();
        switch (choice) {
        case 1:{
            int key=val.enterID();

            auto it = find_if(LA.begin(), LA.end(), [key](const LibrarianAccount* acc) 
            { return acc->getID() == key;});

            if (it != LA.end()) {
				updateHandleMenu(*it);
			} else {
				cout << "Not found" << endl;
			}
            break;
        }
        case 2:{
            string key=val.enterName();

            auto it = find_if(LA.begin(), LA.end(), [key](const LibrarianAccount* acc) 
            { return acc->getName() == key;});

            if (it != LA.end()) {
				updateHandleMenu(*it);
			} else {
				cout << "Not found" << endl;
			}
            break;
        }
        default:
            cout<<"Error: INVALID INPUT"<<endl;
            break;
        }
    }

};