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
        ifstream module;
        string vaule;

        QFile modulex(":/01/word");
        modulex.open(QFile::ReadOnly);

        stringstream xx;
        xx<<modulex.readAll().toStdString();

        module.open("D://01//word.csv");
        while(xx.peek()!=EOF){
            getline(xx,vaule,',');
            string a=vaule;
            getline(xx,vaule,',');
            string b=vaule;
            getline(xx,vaule,',');
            string c=vaule;
            getline(xx,vaule,'\n');
            string d=vaule;
            words w(a,b,c,d);
            Words.push_back(w);
        }
    }
};

#endif // MANAGEMENT_H
