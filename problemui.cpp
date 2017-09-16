#include "problemui.h"

ProblemUI::ProblemUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,parent->width(),parent->height());

    ProblemDescribe= new QLabel(this);
    ProblemOption1= new QPushButton(this);
    ProblemOption2= new QPushButton(this);
    ProblemOption3= new QPushButton(this);
    ProblemOption4= new QPushButton(this);

    ProblemDescribe->setText("日本語");
    ProblemOption1->setText("日语");
    ProblemOption2->setText("英语");
    ProblemOption3->setText("法语");
    ProblemOption4->setText("俄语");

    ProblemDescribe->move(this->width()*0.1,this->height()*0.08);
    ProblemDescribe->setStyleSheet("font-size:22px;");
    ProblemOption1->setGeometry(this->width()*0.06,this->height()*0.3,560,60);
    ProblemOption2->setGeometry(this->width()*0.06,this->height()*0.45,560,60);
    ProblemOption3->setGeometry(this->width()*0.06,this->height()*0.6,560,60);
    ProblemOption4->setGeometry(this->width()*0.06,this->height()*0.75,560,60);
}
