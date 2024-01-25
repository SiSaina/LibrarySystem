#pragma once
#include <iostream>
#include <fstream>
#include "InputValidation.cpp"
#include "ExceptionHandling.cpp"

using namespace std;

class LoginAndRegister {
private:
    string name, pass;
    InputValidation val;
public:
    LoginAndRegister() : name("unknown"), pass("unknown") { }
    LoginAndRegister(string name, string pass){
        setName(name);
        setPass(pass);
    }

    string getName() const{
        return name;
    }
    string getPass() const{
        return pass;
    }
    void setName(const string name) {
        this->name = (name.length() > 0) ? name : throw ExceptionHandling();
    }
    void setPass(const string pass) {
        this->pass = (pass.length() > 0) ? pass : throw ExceptionHandling();
    }

    bool userLogin() {
    name=val.enterName();
    pass=val.enterPass();
    
    bool found = false;
    string fileUsername, filePassword;
    ifstream file("users.dat", ios::in);

    if (!file.is_open()) {
        cerr << "Cannot open file" << endl;
        return false;
    }

    while (file >> fileUsername >> filePassword) {
        if (fileUsername == name && filePassword == pass) {
            cout << "Welcome to library management" << " "<< name << endl;
            found = true;
            break;
        }
    }
        
    file.close();

    if (!found) {
        cout << "User not found" << endl;
    }

    return found;
    }

    void userRegister() {
        name=val.enterName();
        pass=val.enterPass();
        ofstream file("users.dat", ios::out | ios::app);

        if (!file.is_open()) {
            cerr << "Cannot open file" << endl;
            return;
        }

        file << name << " " << pass << endl;
        file.close();

        cout << "User created" << endl;
    }
};