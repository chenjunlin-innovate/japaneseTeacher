#ifndef WORDSTUDYUI_H
#define WORDSTUDYUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "management.h"

class WordStudyUI : public QWidget
{
    Q_OBJECT
public:
    explicit WordStudyUI(QWidget *parent = nullptr);

    QPushButton *Radio;
    QLabel *japanese;
    QLabel *read;
    QLabel *chinese;
    QPushButton *firstButton;
    QPushButton *secondButton;
    QPushButton *previous;
    QPushButton *nextword;

    management *MainManagement;
signals:

public slots:
};

#endif // WORDSTUDYUI_H
