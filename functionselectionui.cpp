#include "functionselectionui.h"

FunctionSelectionUI::FunctionSelectionUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,parent->width(),parent->height());
    this->setStyleSheet("background-color:#ffffff;border:0px groove gray;border-radius:0px;padding:0px 0px;");

    ChoiceGroupBox=new QGroupBox(this);
    BegainButton=new QPushButton(this);
    MainLabel=new QLabel(this);
    SpeedLabel=new QLabel(this);

    WordButton=new QRadioButton(ChoiceGroupBox);
    GrammarButton=new QRadioButton(ChoiceGroupBox);
    TextButton=new QRadioButton(ChoiceGroupBox);

    setallstyle();
}

void FunctionSelectionUI::setallstyle()
{
    ChoiceGroupBox->setGeometry((this->width()-350)/2,this->height()*0.45,350,30);
    ChoiceGroupBox->setStyleSheet("border:0px groove gray;");

    MainLabel->setText( "第 1 课");
    MainLabel->setStyleSheet("font-size:50px;font-family:Microsoft YaHei;color:#555555;border:0px groove gray;");
    MainLabel->move(this->width()/2-80,this->height()*0.15);

    SpeedLabel->setText( "完成 0 个词/共 10 个词");
    SpeedLabel->setStyleSheet("font-size:20px;font-family:Microsoft YaHei;color:#000000;border:0px groove gray;");
    SpeedLabel->move(this->width()/2-110,this->height()*0.3);

    TextButton->setText( "课文");
    WordButton->setText( "单词");
    GrammarButton->setText( "语法");

    TextButton->move(ChoiceGroupBox->width()-65,3);
    WordButton->move(5,3);
    GrammarButton->move(ChoiceGroupBox->width()-200,3);

    BegainButton->setText( "开始学习");
    BegainButton->setGeometry((this->width()-260)/2,this->height()*0.55,260,80);
    BegainButton->setStyleSheet("QPushButton{font-size:35px;font-family:Microsoft YaHei;color:#FFFFFF;border:2px groove gray;border-radius:10px;padding:2px 4px;font-weight:bold;}"
                                "QPushButton{background:#98dd34;}"
                                "QPushButton:hover{background:#85d413;}"
                                "QPushButton:pressed{background:#7ac212;}");
}
