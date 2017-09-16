#ifndef PROBLEMUI_H
#define PROBLEMUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class ProblemUI : public QWidget
{
    Q_OBJECT
public:
    explicit ProblemUI(QWidget *parent = nullptr);

    QLabel *ProblemDescribe;

    QPushButton *ProblemOption1;
    QPushButton *Problem;
    QPushButton *ProblemOption3;
    QPushButton *ProblemOption4;


signals:

public slots:
};

#endif // PROBLEMUI_H
