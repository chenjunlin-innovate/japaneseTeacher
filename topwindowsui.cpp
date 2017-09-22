#include "topwindowsui.h"

TopWindowsUI::TopWindowsUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(5,3,parent->width()-10,parent->height()*0.11-3);
    QGroupBox *LogoGroupBox=new QGroupBox(this);
    LogoGroupBox->setGeometry(20,19,150,40);
    LogoGroupBox->setStyleSheet("background-image:url(:/imagefile/logo);border:0px groove gray;border-radius:0px;padding:0px 0px;");

    QGroupBox *SetButtonGroupBox=new QGroupBox(this);

    NavigationButton1=new QPushButton(SetButtonGroupBox);
    NavigationButton2=new QPushButton(SetButtonGroupBox);
    NavigationButton3=new QPushButton(SetButtonGroupBox);
    NavigationButton4=new QPushButton(SetButtonGroupBox);

    SetButtonGroupBox->setStyleSheet("border:0px");
    SetButtonGroupBox->setGeometry(this->width()-260,10,250,55);

    NavigationButton1->setStyleSheet("background-image:url(:/imagefile/home);");
    NavigationButton2->setStyleSheet("background-image:url(:/imagefile/help);");
    NavigationButton3->setStyleSheet("background-image:url(:/imagefile/set);");
    NavigationButton4->setStyleSheet("background-image:url(:/imagefile/close);");


    NavigationButton1->setGeometry(0,0,51,51);
    NavigationButton2->setGeometry(65,0,51,51);
    NavigationButton3->setGeometry(130,0,51,51);
    NavigationButton4->setGeometry(195,0,51,51);

    QObject::connect(NavigationButton4, &QPushButton::clicked, &QApplication::quit);
}
