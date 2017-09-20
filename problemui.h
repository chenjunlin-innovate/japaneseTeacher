#ifndef PROBLEMUI_H
#define PROBLEMUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "management.h"

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
};

#endif // PROBLEMUI_H
