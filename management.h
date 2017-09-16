#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include"words.h"
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

class management
{
private:
    int ClassNumber;
    vector<words> Words;
public:
    management();
    void readfile(){
        ifstream module;
        string vaule;
        module.open(":/1.csv");
        while(module.peek()!=EOF){
            getline(module,vaule,',');
            string a=vaule;
            cout<<vaule<<endl;
            getline(module,vaule,',');
            string b=vaule;
            getline(module,vaule,',');
            string c=vaule;
            getline(module,vaule,',');
            string d=vaule;
            words w(a,b,c,d);
            Words.push_back(w);
        }
    }
};

#endif // MANAGEMENT_H
