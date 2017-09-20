#ifndef WORDSTUDYUI_H
#define WORDSTUDYUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMediaPlayer>
#include <QString>
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

    QPushButton *gototest;

    management *MainManagement;

    QMediaPlayer *player;

signals:

public slots:
    void former_change();
    void next_change();
};

#endif // WORDSTUDYUI_H
