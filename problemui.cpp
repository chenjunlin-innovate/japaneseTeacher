#include "problemui.h"

ProblemUI::ProblemUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,parent->width(),parent->height());
    this->setStyleSheet("QPushButton{border:1px groove #A2E1FF;border-radius:5px;padding:0px 0px;color:#000000;font-size:20px;font-family:Microsoft YaHei;}"
                        "QPushButton{background:#E2F1FF;}"
                        "QPushButton:hover{background:#D2E1FF;}"
                        "QPushButton:pressed{background:#C2E1FF;}"
                        "QLabel{border:0px groove gray;}");

    Tips=new QLabel(this);
    ProblemDescribe= new QLabel(this);
    ProblemOption1= new QPushButton(this);
    ProblemOption2= new QPushButton(this);
    ProblemOption3= new QPushButton(this);
    ProblemOption4= new QPushButton(this);
    NextTest=new QPushButton(this);

    ProblemDescribe->setText("日本語");
    ProblemOption1->setText("日语");
    ProblemOption2->setText("英语");
    ProblemOption3->setText("法语");
    ProblemOption4->setText("俄语");

    ProblemDescribe->move(this->width()*0.15,this->height()*0.18);
    ProblemDescribe->setStyleSheet("font-size:35px;");
    ProblemOption1->setGeometry(this->width()*0.06,this->height()*0.3,560,60);
    ProblemOption2->setGeometry(this->width()*0.06,this->height()*0.43,560,60);
    ProblemOption3->setGeometry(this->width()*0.06,this->height()*0.56,560,60);
    ProblemOption4->setGeometry(this->width()*0.06,this->height()*0.69,560,60);

    NextTest->setText("下一题");
    NextTest->setGeometry(this->width()*0.65,this->height()*0.83,90,33);
    NextTest->setStyleSheet("QPushButton{border:1px groove gray;border-radius:5px;padding:0px 0px;color:#ffffff;font-size:15px;}"
                            "QPushButton{background:#62B1E1;}"
                            "QPushButton:hover{background:#42A1E1;}"
                            "QPushButton:pressed{background:#2281B1;}"
                            "QLabel{border:0px groove gray;}");
    Tips->setGeometry(this->width()*0.35,this->height()*0.83,200,25);
    Tips->setText("回答正确，请继续下一题吧~");
    Tips->setStyleSheet("font-size:15px");
    QObject::connect(NextTest,&QPushButton::clicked,this,&ProblemUI::next_test);

}
void ProblemUI::next_test(){
    int maxn=MainManagement->get_sise();
    int flag;
    srand((unsigned)time(0));
    flag=rand()%maxn;
    QString ans[4];
    QString xx=QString::fromStdString(MainManagement->get_i_Jan(flag));
    ans[0]=QString::fromStdString(MainManagement->get_i_ch(flag));
    ProblemDescribe->setText(xx);
    int a=rand()%maxn;
    while(a==flag)a=rand()%maxn;
    ans[1]=QString::fromStdString(MainManagement->get_i_ch(a));
    int b=rand()%maxn;
    while(b==flag||b==a)b=rand()%maxn;
    ans[2]=QString::fromStdString(MainManagement->get_i_ch(b));

    int c=rand()%maxn;
    while(c==b||c==flag||c==a)c=rand()%maxn;
    ans[3]=QString::fromStdString(MainManagement->get_i_ch(c));
    int tmp1=rand()%4;

    QString mid=ans[0];
    ans[0]=ans[tmp1];
    ans[tmp1]=mid;

    ProblemOption1->setText(ans[0]);
    ProblemOption2->setText(ans[1]);
    ProblemOption3->setText(ans[2]);
    ProblemOption4->setText(ans[3]);
}
string ProblemUI::op1(){
   return ProblemOption1->text().toStdString();

}
string ProblemUI::op2(){
   return ProblemOption2->text().toStdString();

}
string ProblemUI::op3(){
   return ProblemOption3->text().toStdString();

}
string ProblemUI::op4(){
   return ProblemOption4->text().toStdString();

}

void ProblemUI::updata_tips(string s){
    string ans=MainManagement->get_ch_ans(ProblemDescribe->text().toStdString());
    if(ans==s)Tips->setText("回答正确，请继续下一题吧~");
    else Tips->setText("回答错误，要加油哦~");


}
