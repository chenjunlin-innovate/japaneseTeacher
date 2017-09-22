#ifndef TOPWINDOWSUI_H
#define TOPWINDOWSUI_H

#include"qheadfile.h"

class TopWindowsUI : public QWidget
{
    Q_OBJECT
public:
    QPushButton *NavigationButton1;
    QPushButton *NavigationButton2;
    QPushButton *NavigationButton3;
    QPushButton *NavigationButton4;

    explicit TopWindowsUI(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TOPWINDOWSUI_H
