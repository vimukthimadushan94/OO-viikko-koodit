#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->countButton,&QPushButton::clicked,this,&MainWindow::setNumber);
    connect(ui->resetButton,&QPushButton::clicked,this,&MainWindow::setZero);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNumber()
{
    counterNumber++;
    ui->spinBox->setValue(counterNumber);
    qDebug()<<"Adding Number";
}

void MainWindow::setZero()
{
    counterNumber=0;
    ui->spinBox->setValue(counterNumber);
    qDebug()<<"Set Value as 0";
}
