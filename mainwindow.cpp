#include "mainwindow.h"
#include<QMouseEvent>
#include<QGroupBox>
#include<QButtonGroup>
#include<QPushButton>
#include<QString>
#include<QPainter>
#include<QLabel>
#include<QBitmap>
#include<QFont>
#include<QRadioButton>
#include<QWidget>
#include<QListWidget>
#include<QComboBox>
#include<QCheckBox>
#include<QScrollBar>
#include<QSplashScreen>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->SetWindowsSize(1120,740);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("QWidget{background-color:#4da6de;border:2px groove gray;border-radius:10px;padding:2px 4px;}");

    SetFillet();

    TopGroupBox=new QGroupBox(this);                           SetTopGroupBox();
    FootGroupBox=new QGroupBox(this);                          SetFooterMessage();
    MainUiGroupBox=new QGroupBox(this);                        SetMainGroupBox();
    RightGroupBox=new QGroupBox(this);                         SetRightGroupBox();

    FunctionSelectionGroupBox=new QGroupBox(MainUiGroupBox);   SetFunctionSelectionGroupBox();
    FunctionSelectionGroupBox->hide();//开发测试

    WrodListGroupBox=new QGroupBox(MainUiGroupBox);            SetWrodListGroupBox();

    //WrodListGroupBox->hide();


}

MainWindow::~MainWindow()
{

}

void MainWindow::SetWindowsSize(int x, int y)
{
    this->resize(x,y);
    this->setMaximumSize(x,y);
    this->setMinimumSize(x,y);
}

void MainWindow::SetFunctionSelectionGroupBox()
{
    FunctionSelectionGroupBox->setGeometry(0,0,MainUiGroupBox->width(),MainUiGroupBox->height());
    FunctionSelectionGroupBox->setStyleSheet("background-color:#ffffff;border:0px groove gray;border-radius:0px;padding:0px 0px;");

    QGroupBox *ChoiceGroupBox=new QGroupBox(FunctionSelectionGroupBox);
    QPushButton *BegainButton=new QPushButton(FunctionSelectionGroupBox);
    QLabel *MainLabel=new QLabel(FunctionSelectionGroupBox);
    QLabel *SpeedLabel=new QLabel(FunctionSelectionGroupBox);

    QRadioButton *WordButton=new QRadioButton(ChoiceGroupBox);
    QRadioButton *GrammarButton=new QRadioButton(ChoiceGroupBox);
    QRadioButton *TextButton=new QRadioButton(ChoiceGroupBox);

    ChoiceGroupBox->setGeometry((FunctionSelectionGroupBox->width()-350)/2,FunctionSelectionGroupBox->height()*0.45,350,30);
    ChoiceGroupBox->setStyleSheet("border:0px groove gray;");

    MainLabel->setText( "第 1 课");
    MainLabel->setStyleSheet("font-size:50px;font-family:Microsoft YaHei;color:#555555;border:0px groove gray;");
    MainLabel->move(FunctionSelectionGroupBox->width()/2-80,FunctionSelectionGroupBox->height()*0.15);

    SpeedLabel->setText( "完成 0 个词/共 10 个词");
    SpeedLabel->setStyleSheet("font-size:20px;font-family:Microsoft YaHei;color:#000000;border:0px groove gray;");
    SpeedLabel->move(FunctionSelectionGroupBox->width()/2-110,FunctionSelectionGroupBox->height()*0.3);

    TextButton->setText( "课文");
    WordButton->setText( "单词");
    GrammarButton->setText( "语法");

    TextButton->move(ChoiceGroupBox->width()-65,3);
    WordButton->move(5,3);
    GrammarButton->move(ChoiceGroupBox->width()-200,3);

    BegainButton->setText( "开始学习");
    BegainButton->setGeometry((FunctionSelectionGroupBox->width()-260)/2,FunctionSelectionGroupBox->height()*0.55,260,80);
    BegainButton->setStyleSheet("QPushButton{font-size:35px;font-family:Microsoft YaHei;color:#FFFFFF;border:2px groove gray;border-radius:10px;padding:2px 4px;font-weight:bold;}"
                                "QPushButton{background:#98dd34;}"
                                "QPushButton:hover{background:#85d413;}"
                                "QPushButton:pressed{background:#7ac212;}");

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

    SetButtonGroupBox->setGeometry(TopGroupBox->width()-260,7,250,55);

    Button4->setText( "×");

    Button1->setGeometry(0,0,55,55);
    Button2->setGeometry(65,0,55,55);
    Button3->setGeometry(130,0,55,55);
    Button4->setGeometry(195,0,55,55);
}

void MainWindow::SetTopGroupBox()
{
    TopGroupBox->setGeometry(5,3,this->width()-10,this->height()*0.1-3);

    QGroupBox *LogoGroupBox=new QGroupBox(TopGroupBox);
    LogoGroupBox->setGeometry(20,15,150,40);
    LogoGroupBox->setStyleSheet("background-image:url(:/imagefile/logo);border:0px groove gray;border-radius:0px;padding:0px 0px;");
    SetSettingBar();

}

void MainWindow::SetMainGroupBox()
{
    MainUiGroupBox->setGeometry(5,TopGroupBox->height(),this->width()*0.7,this->height()-TopGroupBox->height()-FootGroupBox->height());
    MainUiGroupBox->setStyleSheet("background-color:#ffffff;border:0px groove gray;border-radius:0px;padding:0px 0px;");
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

void MainWindow::SetWrodListGroupBox()
{
    WrodListGroupBox->setGeometry(0,0,MainUiGroupBox->width(),MainUiGroupBox->height());
    QListWidget *WordList=new QListWidget(WrodListGroupBox);
    WordList->setGeometry(15,100,WrodListGroupBox->width()-30,WrodListGroupBox->height()-200);
    WordList->setStyleSheet("QListWidget{border:1px groove gray;}");
    WordList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
                                                   "{"
                                                   "width:12px;"
                                                   "background:rgba(0,0,0,0%);"
                                                   "margin:0px,0px,0px,0px;"
                                                   "padding-top:0px;"
                                                   "padding-bottom:0px;"
                                                   "}"
                                                   "QScrollBar::handle:vertical"
                                                   "{"
                                                   "width:12px;"
                                                   "background:rgba(0,0,0,25%);"
                                                   " border-radius:4px;"
                                                   "min-height:20;"
                                                   "}"
                                                   "QScrollBar::handle:vertical:hover"
                                                   "{"
                                                   "width:12px;"
                                                   "background:rgba(0,0,0,50%);"
                                                   " border-radius:4px;"
                                                   "min-height:20;"
                                                   "}"
                                                   "QScrollBar::add-line:vertical"
                                                   "{"
                                                   "height:9px;width:12px;"
                                                   "border-image:url(:/images/a/3.png);"
                                                   "subcontrol-position:bottom;"
                                                   "}"
                                                   "QScrollBar::sub-line:vertical"
                                                   "{"
                                                   "height:9px;width:12px;"
                                                   "border-image:url(:/images/a/1.png);"
                                                   "subcontrol-position:top;"
                                                   "}"
                                                   "QScrollBar::add-line:vertical:hover"
                                                   "{"
                                                   "height:9px;width:12px;"
                                                   "border-image:url(:/images/a/4.png);"
                                                   "subcontrol-position:bottom;"
                                                   "}"
                                                   "QScrollBar::sub-line:vertical:hover"
                                                   "{"
                                                   "height:9px;width:12px;"
                                                   "border-image:url(:/images/a/2.png);"
                                                   "subcontrol-position:top;"
                                                   "}"
                                                   "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
                                                   "{"
                                                   "background:rgba(0,0,0,10%);"
                                                   "border-radius:4px;"
                                                   "}"
                                                   );

    for(int i=0; i<100; i++)
    {
        QListWidgetItem *item = new QListWidgetItem("a",NULL);
        QWidget *itemwidget=new QWidget();
        QPushButton *button=new QPushButton(itemwidget);
        QCheckBox *checkBox =new QCheckBox(itemwidget);
        QLabel *japanese= new QLabel(itemwidget);
        QLabel *chinese= new QLabel(itemwidget);
        QString xx( "日本語");
        xx+=QString::number(i);
        japanese->setText(xx);
        chinese->setText( "【名词】中文翻译");
        item->setSizeHint(QSize(WordList->width()-25, 38));
        button->setGeometry(65,9,20,20);
        checkBox->setGeometry(35,9,20,20);
        japanese->move(100,11);
        chinese->move(370,11);
        itemwidget->setStyleSheet("QWidget{background:#FFFFFF;}"
                                  "QWidget:hover{background:#F2F1F1;}"
                                  "QWidget:pressed{background:#F2F1F1;}"
                                  "QLabel{background-color:rgba(255,255,255,0);}");
        button->setStyleSheet("QPushButton{background:#62B1E1;}"
                              "QPushButton:hover{background:#42A1E1;}"
                              "QPushButton:pressed{background:#2281B1;}");
        //QComboBox *box = new QComboBox();
        //box->addItems(QStringList()<<"1"<<"2");
        WordList->addItem(item);
        WordList->setItemWidget(item,itemwidget);

    }
}
