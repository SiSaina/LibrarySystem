#pragma once
#include <iostream>
#include <memory>
#include "BookManager.cpp"
#include "BookAccount.cpp"
#include "InputValidation.cpp"
#include "PremiumBookAccount.cpp"
#include "BasicBookAccount.cpp"
#include "LibrarianManager.cpp"

using namespace std;

enum {
    ADD = 1,
    OUTPUT,
    UPDATE,
    DELETE,
    SEARCH,
    SORT,
    SAVE,
    LOGOUT,
    EXIT = 0
};

class Application{
private:
    BookManager BM;
    BookAccount* accBA{};
    LibrarianManager LM;
    LibrarianAccount* accLA{};
    InputValidation val;
    
    void bookMenu(){
        cout<<"==================Book Manager Menu=================="<<endl;
        cout<<"1. Create book information"<<endl;
        cout<<"2. View all book information"<<endl;
        cout<<"3. Update book information"<<endl;
        cout<<"4. Delete book information"<<endl;
        cout<<"5. Search book information"<<endl;
        cout<<"6. Sort book information"<<endl;
        cout<<"7. Save data"<<endl;
        cout<<"8. Log out"<<endl;
        cout<<"0. Exit"<<endl;
    }
    void librarianMenu(){
        cout<<"==================Librarian Manager Menu=================="<<endl;
        cout<<"1. Create new account"<<endl;
        cout<<"2. View all account"<<endl;
        cout<<"3. Update account"<<endl;
        cout<<"4. Delete account"<<endl;
        cout<<"5. Search account"<<endl;
        cout<<"6. Sort account information"<<endl;
        cout<<"7. Save data"<<endl;
        cout<<"8. Log out"<<endl;
        cout<<"0. Exit"<<endl;
    }
public:

    void bookManager(){
        int choice=0;
        int option=0;

        do{
            bookMenu();
            choice=val.enterChoice();

            switch (choice) {
            case ADD:
                BM.addBookMenu();
                break;
            case OUTPUT:
                BM.viewAllBook();
                break;
            case UPDATE: {
                char choice;
                do{
                    BM.updateBook(accBA);

                    cout<<"Do you want to update again??"<<endl;
                    choice=val.enterYN();
                }while(choice=='y'||choice=='Y');
                }
                break;
            case DELETE:{
                char choice;
                do{
                    BM.deleteBook(accBA);

                    cout<<"Do you want to delete again??"<<endl;
                    choice=val.enterYN();
                }while(choice=='y'||choice=='Y');
                }
                break;
            case SEARCH:{
                char choice;
                do{
                    BM.searchBook(accBA);

                    cout<<"Do you want to search again??"<<endl;
                    choice=val.enterYN();
                }while(choice=='y'||choice=='Y');
                }
                break;
            case SORT:
                BM.sortBook();
                break;
            case SAVE:
                // BM.saveBook();
                break;
            case LOGOUT:
                break;
            case EXIT:
                exit(0);
            default:
                cout<<"Error: INVALID INPUT"<<endl;
                break;
            }
        } while(choice!=10);
    }

    void librarianManager(){
        int choice=0;
        int option=0;

        do {
            librarianMenu();
            choice=val.enterChoice();

            switch (choice) {
            case ADD:
                LM.addAccount();
                break;
            case OUTPUT:
                LM.viewAllAccount();
                break;
            case UPDATE:
                LM.updateAccount(accLA);
                break;
            case EXIT:
                exit(0);
            default:
                cout<<"Error: INVALID INPUT"<<endl;
                break;
            }
        } while(choice!=10);

    }
    void run(){
        // BM.loadBook();
        bookManager();
        // librarianManager();
    }
};