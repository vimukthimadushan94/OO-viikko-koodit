#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* numberButtons[10];
    numberButtons[0] = ui->N0;
    numberButtons[1] = ui->N1;
    numberButtons[2] = ui->N2;
    numberButtons[3] = ui->N3;
    numberButtons[4] = ui->N4;
    numberButtons[5] = ui->N5;
    numberButtons[6] = ui->N6;
    numberButtons[7] = ui->N7;
    numberButtons[8] = ui->N8;
    numberButtons[9] = ui->N9;

    for (int i = 0; i < 10; i++) {
        numberButtons[i]->setProperty("numVal",i);
        connect(numberButtons[i], &QPushButton::clicked,this, [this,i]{
            numberClickHandler(i);
        });
    }


    connect(ui->add,&QPushButton::clicked,this,[this]{
        addSubMulDivHandler('+');
    });

    connect(ui->sub,&QPushButton::clicked,this,[this]{
        addSubMulDivHandler('-');
    });

    connect(ui->mul,&QPushButton::clicked,this,[this]{
        addSubMulDivHandler('*');
    });

    connect(ui->div,&QPushButton::clicked,this,[this]{
        addSubMulDivHandler('/');
    });

    //clear and enter
    connect(ui->clear,&QPushButton::clicked,this,[this]{
        clearAndEnterClickHandler("clear");
    });

    connect(ui->enter,&QPushButton::clicked,this,[this]{
        clearAndEnterClickHandler("enter");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler(int i)
{
    qDebug()<<"number painettu"<<i;
    qDebug()<<"State: "<<state;
    QString tempNum = QString::number(i);
    if(state==1){
        number1 = number1+tempNum;
        qDebug()<<"Number 1: "<<number1;

        ui->num1->setText(number1);
    }else{
        number2 = number2+tempNum;
        qDebug()<<"Number 2: "<<number2;

        ui->num2->setText(number2);
    }


}

void MainWindow::clearAndEnterClickHandler(string op)
{
    if(op=="clear"){
        resetLineEdits();
    }else if(op=="enter"){
        state=1;
        if(operand=='+'){
            float result = QString(number1).toDouble()+QString(number2).toDouble();
            ui->result->setText(QString::number(result));
        }else if(operand=='-'){
            float result = QString(number1).toDouble()-QString(number2).toDouble();
            ui->result->setText(QString::number(result));
        }else if(operand=='*'){
            float result = QString(number1).toDouble()*QString(number2).toDouble();
            ui->result->setText(QString::number(result));
        }else if(operand=='/'){
            float result = QString(number1).toDouble()/QString(number2).toDouble();
            ui->result->setText(QString::number(result));
        }else{
            qDebug()<<"Unsupported opperend";
        }
    }else{
        qDebug()<<"Unsupported command";
    }
}

void MainWindow::addSubMulDivHandler(char op)
{
    qDebug()<<"Pressed Operator";
    operand=op;
    if(operand=='+'|| operand=='-'|| operand=='*'|| operand=='/'){
        state=2;
    }

    qDebug()<<"State: "<<state;
}

void MainWindow::resetLineEdits()
{
    state=1;
    number1=0;
    number2=0;
    ui->num1->setText(number1);
    ui->num2->setText(number2);
    ui->result->setText(0);
    qDebug()<<"Resetting";
    qDebug()<<"State: "<<state;
}
