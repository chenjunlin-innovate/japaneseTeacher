#ifndef MAKE_PROBLEMS_H
#define MAKE_PROBLEMS_H
#include"problem.h"
#include<vector>
#include"management.h"
#include<cstdlib>
#include<ctime>
class make_problems
{
    vector<problem> ve;
    int pos;
    management *MainManagement;
public:
    make_problems();
    void init(){
        int maxn=MainManagement->get_sise();

        for(int i=0;i<maxn;i++){
           string po=MainManagement->get_i_Jan(i);
           string ans=MainManagement->get_i_ch(i);
           int a=rand()%maxn;
           while(a==i)a=rand()%maxn;
           string ans1=MainManagement->get_i_ch(a);
           int b=rand()%maxn;
           while(b==i||b==a)b=rand()%maxn;
           string ans2=MainManagement->get_i_ch(b);

           int c=rand()%maxn;
           while(c==b||c==i||c==a)c=rand()%maxn;
           string ans3=MainManagement->get_i_ch(c);
           problem p(po,ans,ans1,ans2,ans3);
           ve.push_back(p);
        }
            for(int i=0;i<maxn/4;i++){
                int tmp1=rand()%maxn;
                int tmp2=rand()%maxn;
                problem temp=ve[tmp1];
                ve[tmp1]=ve[tmp2];
                ve[tmp2]=temp;

            }
        for(int i=0;i<maxn;i++){
           string po=MainManagement->get_i_ch(i);
           string ans=MainManagement->get_pronun(i);
           int a=rand()%maxn;
           while(a==i)a=rand()%maxn;
           string ans1=MainManagement->get_pronun(a);
           int b=rand()%maxn;
           while(b==i||b==a)b=rand()%maxn;
           string ans2=MainManagement->get_pronun(b);

           int c=rand()%maxn;
           while(c==b||c==i||c==a)c=rand()%maxn;
           string ans3=MainManagement->get_pronun(c);
           problem p(po,ans,ans1,ans2,ans3);
           ve.push_back(p);
        }
        for(int i=0;i<maxn/4;i++){
            int tmp1=rand()%((maxn*2-maxn)+maxn);
            int tmp2=rand()%((maxn*2-maxn)+maxn);
            problem temp=ve[tmp1];
            ve[tmp1]=ve[tmp2];
            ve[tmp2]=temp;

        }


    }
    int getsize(){
        return ve.size();
    }
    problem get_problem(int i){
        return ve[i];
    }

    void nextpos(){
        if(pos<ve.size()-1)pos++;
    }

    int getpos(){
        return pos;
    }
    void make_empty(){
        ve.clear();
        pos=0;
    }

    
};

#endif // MAKE_PROBLEMS_H
