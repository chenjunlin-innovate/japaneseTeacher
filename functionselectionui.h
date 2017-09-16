#ifndef FUNCTIONSELECTIONUI_H
#define FUNCTIONSELECTIONUI_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>

class FunctionSelectionUI : public QWidget
{
    Q_OBJECT
public:
    explicit FunctionSelectionUI(QWidget *parent = nullptr);
    void setallstyle();

    QGroupBox *ChoiceGroupBox;
    QPushButton *BegainButton;
    QRadioButton *WordButton;
    QRadioButton *GrammarButton;
    QRadioButton *TextButton;

    QLabel *MainLabel;
    QLabel *SpeedLabel;
signals:

public slots:


};

#endif // FUNCTIONSELECTIONUI_H
