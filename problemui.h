#ifndef PROBLEMUI_H
#define PROBLEMUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "management.h"
#include"make_problems.h"
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
    QPushButton *Radio;

    QPushButton *NextTest;

    management *MainManagement;
    make_problems *pro;

signals:

public slots:
    void next_test();
    void newstart();



};

#endif // PROBLEMUI_H
