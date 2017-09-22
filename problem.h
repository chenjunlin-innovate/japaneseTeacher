#ifndef PROBLEM_H
#define PROBLEM_H
#include<string>
#include<iostream>
using namespace std;

class problem
{
    string issue;
    string ans,ans1,ans2,ans3;
    
public:
    problem();
    problem(string a,string b,string c,string d,string e):issue(a),ans(b),ans1(c),ans2(d),ans3(e){
        
    }

    string get_issue(){
        return issue;
    }
    string get_ans(){
        return ans;
    }
    string get_ans1(){
        return ans1;
    }
    string get_ans2(){
        return ans2;
    }
    string get_ans3(){
        return ans3;
    }
    problem operator =(const problem &p){
        issue=p.issue;
        ans=p.ans;
        ans1=p.ans1;
        ans2=p.ans2;
        ans3=p.ans3;
        return *this;
    }
    
};

#endif // PROBLEM_H
