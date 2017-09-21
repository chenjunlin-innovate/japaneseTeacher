#ifndef PROBLEMUI_H
#define PROBLEMUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "management.h"
#include<cstdlib>
#include<ctime>

class ProblemUI : public QWidget
{
    Q_OBJECT
public:
    explicit ProblemUI(QWidget *parent = nullptr);

    QLabel *ProblemDescribe;
    QLabel *Tips;

    QPushButton *ProblemOption1;
    QPushButton *ProblemOption2;
    QPushButton *ProblemOption3;
    QPushButton *ProblemOption4;

    QPushButton *NextTest;

    management *MainManagement;

signals:

public slots:
    void next_test();
    string op1();
    string op2();
    string op3();
    string op4();
    void updata_tips(string s);


};

#endif // PROBLEMUI_H
