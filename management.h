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
#include<sstream>

using namespace std;

class management
{
private:
    string ClassNumber;
    vector<words> Words;
    int location;
public:
    management();
    void get_num(string s){
     ClassNumber=s;
    }
    void next(){
    if(location<Words.size()-1)location++;
    }
    void fomer(){
        if(location>0)location--;

    }
    int getlocation(){
        return location;
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
    string get_pronun(int i){
        return Words[i].get_pronunciation();
    }

    void readfile(){
        string vaule;
        stringstream module;

        QFile modulex(":/1/word");
        modulex.open(QFile::ReadOnly);

        module<<modulex.readAll().toStdString();

        while(module.peek()!=EOF){
            getline(module,vaule,',');
            string a=vaule;
            getline(module,vaule,',');
            string b=vaule;
            getline(module,vaule,',');
            string c=vaule;
            getline(module,vaule,'\n');
            string d=vaule;
            words w(a,b,c,d);
            Words.push_back(w);
        }
    }
};

#endif // MANAGEMENT_H
