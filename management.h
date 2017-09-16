#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include"words.h"
#include<string>
#include<QString>
#include<QFile>
#include<fstream>
#include<vector>
#include<iostream>
#include<stdlib.h>

using namespace std;

class management
{
private:
    string ClassNumber;
    vector<words> Words;
public:
    management();
    void get_num(string s){
     ClassNumber=s;
    }

    int get_sise(){
        return Words.size();
    }
    string get_i_Jan(int i)const{
        return Words[i].get_japanese();
    }
    string get_i_propety(int i){
        return Words[i].get_property();
    }
    string get_i_ch(int i){
        return Words[i].get_chinese();
    }

    void readfile(){
        ifstream module;
        string vaule;

        module.open("D://01//word.csv");
        while(module.peek()!=EOF){
            getline(module,vaule,',');
            string a=vaule;
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
