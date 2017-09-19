#include "wordstudyui.h"

WordStudyUI::WordStudyUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,parent->width(),parent->height());
    this->setStyleSheet("background-color:#ffffff;border:0px groove gray;border-radius:0px;padding:0px 0px;");

    this->setStyleSheet("QPushButton{border:1px groove gray;border-radius:5px;padding:0px 0px;color:#ffffff;font-weight:bold;}"
                                     "QPushButton{background:#62B1E1;}"
                                     "QPushButton:hover{background:#42A1E1;}"
                                     "QPushButton:pressed{background:#2281B1;}"
                                     "QLabel{border:0px groove gray;}");

    Radio=new QPushButton(this);
    Radio->setGeometry(this->width()*0.12,this->height()*0.29,35,35);
    Radio->setStyleSheet("border-radius:17px;");

    japanese=new QLabel(this);
    japanese->setText("日本語");
    //japanese->move(this->width()*0.19,this->height()*0.260);
    japanese->setGeometry(this->width()*0.19,this->height()*0.260,600,56);
    japanese->setStyleSheet("font-size:55px;font-family:Microsoft YaHei;");

    read=new QLabel(this);
    read->setText("[ にほん ご ]");
    //read->move(this->width()*0.19,this->height()*0.4);
    read->setGeometry(this->width()*0.19,this->height()*0.4,400,28);
    read->setStyleSheet("font-size:27px;font-family:Microsoft YaHei;");

    chinese=new QLabel(this);
    chinese->setText("【名词】中文翻译");
    //chinese->move(this->width()*0.19,this->height()*0.5);
    chinese->setGeometry(this->width()*0.19,this->height()*0.5,300,26);
    chinese->setStyleSheet("font-size:25px;font-family:Microsoft YaHei;");

    firstButton=new QPushButton(this);
    firstButton->setText("基础学习");
    firstButton->setGeometry(this->width()*0.09,this->height()*0.08,100,45);

    secondButton=new QPushButton(this);
    secondButton->setText("例句学习");
    secondButton->setGeometry(this->width()*0.28,this->height()*0.08,100,45);

    previous= new QPushButton(this);
    previous->setText("上一个");
    previous->setGeometry(this->width()*0.60,this->height()*0.83,90,33);

    nextword=new QPushButton(this);
    nextword->setText("下一个");
    nextword->setGeometry(this->width()*0.78,this->height()*0.83,90,33);
    QObject::connect(previous,&QPushButton::clicked,this,&WordStudyUI::former_change);
    QObject::connect(nextword,&QPushButton::clicked,this,&WordStudyUI::next_change);
}
void WordStudyUI::former_change(){
    MainManagement->fomer();
    int flag=MainManagement->getlocation();
    japanese->setText(QString::fromStdString(MainManagement->get_i_Jan(flag).data()));
    read->setText(QString::fromStdString(MainManagement->get_pronun(flag).data()));
    chinese->setText(QString::fromStdString(("[ "+MainManagement->get_i_propety(flag)+"]"+MainManagement->get_i_ch(flag)).data()));
}
void WordStudyUI::next_change(){
    MainManagement->next();
    int flag=MainManagement->getlocation();
    japanese->setText(QString::fromStdString(MainManagement->get_i_Jan(flag).data()));
    read->setText(QString::fromStdString(MainManagement->get_pronun(flag).data()));
    chinese->setText(QString::fromStdString(("[ "+MainManagement->get_i_propety(flag)+"]"+MainManagement->get_i_ch(flag)).data()));
}
