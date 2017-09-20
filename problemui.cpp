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
}
