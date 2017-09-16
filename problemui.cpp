#include "problemui.h"

ProblemUI::ProblemUI(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,parent->width(),parent->height());

    ProblemDescribe->setText("日本語");
    ProblemOption1->setText("日语");
    ProblemOption2->setText("英语");
    ProblemOption3->setText("法语");
    ProblemOption4->setText("俄语");
}
