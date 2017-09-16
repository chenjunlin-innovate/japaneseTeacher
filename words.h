#ifndef WORDS_H
#define WORDS_H
#include<iostream>
using namespace std;

class words
{
string japanese;
string pronunciation;
string chinese;
string property;

public:
    words();
string get_japanese()const{
    return japanese;
}
string get_pronunciation()const{
    return pronunciation;
}
string get_chinese()const{
    return chinese;
}
string get_property()const{
    return property;
}

};

#endif // WORDS_H
