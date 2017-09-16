#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGroupBox>
#include <QPushButton>
#include <QMainWindow>
#include "wordlistui.h"
#include "management.h"
#include "wordstudyui.h"
#include "problemui.h"
#include "functionselectionui.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGroupBox *MainUiGroupBox;

    WordListUI *WordList;
    WordStudyUI *WordStudy;
    ProblemUI *Problem;
    FunctionSelectionUI *FunctionSelection;

    QGroupBox *TopGroupBox;
    QGroupBox *FootGroupBox;
    QGroupBox *RightGroupBox;
    management *MainManagement;

private:
    void SetWindowsSize(int x,int y);
    void SetFillet();
    void SetFooterMessage();
    void SetSettingBar();
    void SetTopGroupBox();
    void SetMainGroupBox();
    void SetRightGroupBox();
    //设定初始窗口大小

    void SetMainConnect();
    void AllWindowsHide();
public slots:
    void GoBackToMain();
    void GoToWordList();
    void GoToWordStudy();
};

#endif // MAINWINDOW_H
