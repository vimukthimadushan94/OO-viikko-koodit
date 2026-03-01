#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QTimer>

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

    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    int seconds;
    QTimer *pQTimer;

    void updateProgressBar();
    void setGameInfoText(QString,short);

private slots:
    void timeout();
    void on_set_mins_clicked();
    void on_set_secs_clicked();
    void on_start_btn_clicked();
    void on_stop_btn_clicked();
    void on_player1_switch_clicked();
    void on_player2_switch_clicked();
};
#endif // MAINWINDOW_H
