#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString number1=0;
    QString number2=0;
    int state=1;
    float result;
    short operand;

    void numberClickHandler(int);
    void clearAndEnterClickHandler(string);
    void addSubMulDivHandler(char);
    void resetLineEdits();
};
#endif // MAINWINDOW_H
