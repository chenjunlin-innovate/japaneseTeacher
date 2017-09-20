#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGroupBox>
#include <QPushButton>
#include <QMainWindow>
#include "qheadfile.h"
#include "wordlistui.h"
#include "management.h"
#include "wordstudyui.h"
#include "topwindowsui.h"
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
    TopWindowsUI *Topwindows;

    QGroupBox *FootGroupBox;
    QGroupBox *RightGroupBox;
    management *MainManagement;

    QPoint mousePosition;
    bool isMousePressed;
protected:
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event) ;
    void mouseReleaseEvent(QMouseEvent*event);
private:
    void SetWindowsSize(int x,int y);
    void SetFillet();
    void SetFooterMessage();
    void SetMainGroupBox();
    void SetRightGroupBox();
    //设定初始窗口大小

    void SetMainConnect();
    void AllWindowsHide();
public slots:
    void GoBackToMain();
    void GoToWordList();
    void GoToWordStudy();
    void GoToProblem();
};

#endif // MAINWINDOW_H
