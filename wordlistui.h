#ifndef WORDLISTUI_H
#define WORDLISTUI_H

#include "qheadfile.h"
#include "management.h"


class WordListUI : public QWidget
{
    Q_OBJECT
public:
    explicit WordListUI(QWidget *parent = nullptr);

    QPushButton *gotostudy;
    QPushButton *gototest;
    QGroupBox *tipBox;
    QLabel *tips;
    QLabel *numberTips;
    QListWidget *WordList;

    management *MainManagement;

    void AddWord();
signals:

public slots:

};

#endif // WORDLISTUI_H
