#include"mainwindow.h"
#include <QMouseEvent>
#include <QGroupBox>
#include <QButtonGroup>
#include <QPushButton>
#include <QString>
#include <QPainter>
#include <QLabel>
#include <QBitmap>
#include <QFont>
#include <QRadioButton>
#include <QWidget>
#include <QListWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QScrollBar>
#include <QSplashScreen>
#include <QApplication>
#include <QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->SetWindowsSize(1050,700);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget{background-color:#4da6de;border:2px groove gray;border-radius:10px;padding:2px 4px;}");

    SetFillet();
    MainManagement=new management;
    TopGroupBox=new QGroupBox(this);                           SetTopGroupBox();
    FootGroupBox=new QGroupBox(this);                          SetFooterMessage();
    MainUiGroupBox=new QGroupBox(this);                        SetMainGroupBox();
    RightGroupBox=new QGroupBox(this);                         SetRightGroupBox();

    FunctionSelection =new FunctionSelectionUI(MainUiGroupBox);  //主页选择页面
    WordList =new WordListUI(MainUiGroupBox);                    //单词列表
    WordStudy = new WordStudyUI(MainUiGroupBox);                 //单词学习
    Problem = new ProblemUI(MainUiGroupBox);                     //测试页面

    //WordStudyGroupBox=new QGroupBox(MainUiGroupBox);           SetWordStudyGroupBox();
    //WordStudyGroupBox->hide();

    WordList->MainManagement=MainManagement;
    WordStudy->MainManagement=MainManagement;
    FunctionSelection->MainManagement=MainManagement;
    Problem->MainManagement=MainManagement;

    AllWindowsHide();   //隐藏所有窗口
    SetMainConnect();   //各类窗口切换Connect
}

MainWindow::~MainWindow()
{
    delete MainManagement;
}

void MainWindow::SetWindowsSize(int x, int y)
{
    this->resize(x,y);
    this->setMaximumSize(x,y);
    this->setMinimumSize(x,y);
}


void MainWindow::SetFillet()
{
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),20,20);
    setMask(bmp);
}

void MainWindow::SetFooterMessage()
{
    FootGroupBox->setGeometry(5,this->height()*0.94,this->width()-6,this->height()*0.06);

    QLabel *FootLabel=new QLabel(FootGroupBox);
    FootLabel->setStyleSheet("color:#ffffff;border:0px groove gray;");
    FootLabel->move(20,17);
    FootLabel->setText("V 1.00 版权所有 水木日语教育科技有限公司");
}

void MainWindow::SetSettingBar()
{
    QGroupBox *SetButtonGroupBox=new QGroupBox(TopGroupBox);

    QPushButton *Button1=new QPushButton(SetButtonGroupBox);
    QPushButton *Button2=new QPushButton(SetButtonGroupBox);
    QPushButton *Button3=new QPushButton(SetButtonGroupBox);
    QPushButton *Button4=new QPushButton(SetButtonGroupBox);

    SetButtonGroupBox->setStyleSheet("border:0px");

    SetButtonGroupBox->setGeometry(TopGroupBox->width()-260,10,250,55);

    Button1->setStyleSheet("background-image:url(:/imagefile/home);");
    Button2->setStyleSheet("background-image:url(:/imagefile/help);");
    Button3->setStyleSheet("background-image:url(:/imagefile/set);");
    Button4->setStyleSheet("background-image:url(:/imagefile/close);");


    Button1->setGeometry(0,0,51,51);
    Button2->setGeometry(65,0,51,51);
    Button3->setGeometry(130,0,51,51);
    Button4->setGeometry(195,0,51,51);

    QObject::connect(Button1,&QPushButton::clicked,this,&MainWindow::GoBackToMain);

    QObject::connect(Button4, &QPushButton::clicked, &QApplication::quit);
}

void MainWindow::SetTopGroupBox()
{
    TopGroupBox->setGeometry(5,3,this->width()-10,this->height()*0.11-3);

    QGroupBox *LogoGroupBox=new QGroupBox(TopGroupBox);
    LogoGroupBox->setGeometry(20,19,150,40);
    LogoGroupBox->setStyleSheet("background-image:url(:/imagefile/logo);border:0px groove gray;border-radius:0px;padding:0px 0px;");
    SetSettingBar();

}

void MainWindow::SetMainGroupBox()
{
    MainUiGroupBox->setGeometry(5,TopGroupBox->height(),this->width()*0.7,this->height()-TopGroupBox->height()-FootGroupBox->height());
    MainUiGroupBox->setStyleSheet("background-color:#ffffff;border:1px groove gray;border-radius:0px;padding:0px 0px;");
}

void MainWindow::SetRightGroupBox()
{
    RightGroupBox->setGeometry(MainUiGroupBox->width()+5,TopGroupBox->height(),this->width()-MainUiGroupBox->width()-10,this->height()-TopGroupBox->height()-FootGroupBox->height());
    RightGroupBox->setStyleSheet("background-color:#ffffff;border:1px groove gray;border-radius:0px;padding:0px 0px;");

    QGroupBox *RightTopBox=new QGroupBox(RightGroupBox);
    QGroupBox *FootTopBox=new QGroupBox(RightGroupBox);
    RightTopBox->setGeometry(0,0,RightGroupBox->width(),RightGroupBox->height()*0.3);
    FootTopBox->setGeometry(0,RightTopBox->height(),RightGroupBox->width(),RightGroupBox->height()-RightTopBox->height());

    QPushButton *ProblemButton=new QPushButton(RightTopBox);
    ProblemButton->setText( "我的错题本");
    ProblemButton->setStyleSheet("QPushButton{border:1px groove gray;border-radius:5px;padding:0px 0px;color:#ffffff;font-weight:bold;}"
                                 "QPushButton{background:#62B1E1;}"
                                 "QPushButton:hover{background:#42A1E1;}"
                                 "QPushButton:pressed{background:#2281B1;}");
    ProblemButton->setGeometry((RightTopBox->width()-110)/2,(RightTopBox->height()-45)/2,110,40);
}


void MainWindow::SetMainConnect()
{
    QObject::connect(FunctionSelection->BegainButton,&QPushButton::clicked,this,&MainWindow::GoToWordList);
    QObject::connect(WordList->gotostudy,&QPushButton::clicked,this,&MainWindow::GoToWordStudy);
    QObject::connect(WordList->gototest,&QPushButton::clicked,this,&MainWindow::GoToProblem);
}

void MainWindow::AllWindowsHide()
{
    WordList->hide();
    WordStudy->hide();
    Problem->hide();
}

void MainWindow::GoBackToMain()
{
    FunctionSelection->show();
    WordList->hide();
    WordList->WordList->clear();
    WordStudy->hide();
    Problem->hide();
}

void MainWindow::GoToWordList()
{
    MainManagement->clear();
    MainManagement->readfile();
    FunctionSelection->hide();
    WordList->AddWord();
    WordList->show();
    WordStudy->hide();
    Problem->hide();
}

void MainWindow::GoToWordStudy()
{
    FunctionSelection->hide();
    WordList->hide();
    WordStudy->show();
    WordStudy->former_change();
    Problem->hide();
}

void MainWindow::GoToProblem()
{
    FunctionSelection->hide();
    WordList->hide();
    WordStudy->hide();
    Problem->show();
}
