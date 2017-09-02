#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGroupBox>
#include"management.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGroupBox *MainUiGroupBox;
    QGroupBox *FunctionSelectionGroupBox;
    QGroupBox *TopGroupBox;
    QGroupBox *FootGroupBox;
    QGroupBox *RightGroupBox;

    QGroupBox *WrodListGroupBox;

    management *MainManagement;
private:
    void SetWindowsSize(int x,int y);
    void SetFunctionSelectionGroupBox();
    void SetFillet();
    void SetFooterMessage();
    void SetSettingBar();
    void SetTopGroupBox();
    void SetMainGroupBox();
    void SetRightGroupBox();
    void SetWrodListGroupBox();
    //设定初始窗口大小
};

#endif // MAINWINDOW_H
