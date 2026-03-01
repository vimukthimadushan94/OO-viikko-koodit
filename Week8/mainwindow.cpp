#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player1Time = 0;
    player2Time = 0;
    currentPlayer = 1;
    gameTime = 0;
    seconds=0;

    pQTimer = new QTimer(this);
    connect(pQTimer, SIGNAL(timeout()), this, SLOT(timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProgressBar()
{
    qDebug()<<"update progress bar";


    ui->player1_proBar->setValue((player1Time * 100) / gameTime);
    ui->player2_probar->setValue((player2Time * 100) / gameTime);
}



void MainWindow::setGameInfoText(QString text, short fontSize)
{
    QFont font;
    font.setPointSize(fontSize);

    ui->label_info->setFont(font);
    ui->label_info->setText(text);
}

void MainWindow::timeout()
{
    qDebug()<<"timeout function ";

    if (currentPlayer == 1)
    {
        player1Time--;
        if (player1Time <= 0)
        {
            player1Time = 0;
            pQTimer->stop();
            setGameInfoText("Player 2 wins!", 16);
        }
    }
    else
    {
        player2Time--;
        if (player2Time <= 0)
        {
            player2Time = 0;
            pQTimer->stop();
            setGameInfoText("Player 1 wins!", 16);
        }
    }

    qDebug()<<"Player 1"<<player1Time;
    qDebug()<<"Player 2"<<player2Time;

    updateProgressBar();
}

void MainWindow::on_set_mins_clicked()
{
    gameTime=gameTime+60;
    qDebug()<<gameTime;
    player1Time = gameTime;
    player2Time = gameTime;
    int minutes = gameTime / 60;
    ui->set_mins->setText(QString::number(minutes) + " min");
    updateProgressBar();
    setGameInfoText("1 min selected. Press START GAME.", 12);
}

void MainWindow::on_set_secs_clicked()
{
    qDebug()<<"start seconds";
    gameTime=this->gameTime+1;
    seconds=seconds+1;
    qDebug()<<"Seconds: "<<seconds;
    qDebug()<<"GameTime: "<<gameTime;
    player1Time = gameTime;
    player2Time = gameTime;

    ui->set_secs->setText(QString::number(seconds) + " sec");

    updateProgressBar();
    setGameInfoText("1 sec selected. Press START GAME.", 12);
}

void MainWindow::on_start_btn_clicked()
{
    qDebug()<<"start button pressd";

    currentPlayer = 1;

    pQTimer->start(1000);

    setGameInfoText("Game started. Player 1 turn.", 12);
}

void MainWindow::on_stop_btn_clicked()
{
    qDebug()<<"stop button pressd";
    pQTimer->stop();
    gameTime=1;
    player1Time = 0;
    player2Time = 0;
    qDebug()<<"Player 111"<<player1Time;
    qDebug()<<"Player 222"<<player2Time;

    ui->set_mins->setText(QString::number(0) + " min");
    ui->set_secs->setText(QString::number(0) + " sec");
    updateProgressBar();
    setGameInfoText("Game Stopped", 12);
}

void MainWindow::on_player1_switch_clicked()
{
    qDebug()<<"player switch1 button pressd";
    currentPlayer=1;
}

void MainWindow::on_player2_switch_clicked()
{
    qDebug()<<"player switch2 button pressd";
    currentPlayer=2;
}
