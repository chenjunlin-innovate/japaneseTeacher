#ifndef WORDLISTUI_H
#define WORDLISTUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QSize>
#include <QString>
#include <vector>
#include <QScrollBar>
#include <QSplashScreen>


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

    void AddWord();
signals:

public slots:

};

#endif // WORDLISTUI_H
