#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerMarker = 'X';
    btn0 = 'Z', btn1 = 'Z', btn2 = 'Z', btn3 = 'Z', btn4 = 'Z', btn5 = 'Z',
            btn6 = 'Z', btn7 = 'Z', btn8 = 'Z';
    ui->textEditInfo->setText("Player " + playerMarker + " turn");
    connect(this, SIGNAL(turnCompleted()), this, SLOT(switchTurn()));
    connect(this, SIGNAL(buttonValue()), this, SLOT(winnerCounting()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_0_clicked()
{
    if(btn0 == 'Z') {
        ui->pushButton_0->setText(playerMarker);
        btn0 = playerMarker;
        emit turnCompleted();
        emit buttonValue();
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    if(btn1 == 'Z') {
        ui->pushButton_1->setText(playerMarker);
        btn1 = playerMarker;
        emit turnCompleted();
        emit buttonValue();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(btn2 == 'Z') {
        ui->pushButton_2->setText(playerMarker);
        btn2 = playerMarker;
        emit turnCompleted();
        emit buttonValue();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(btn3 == 'Z') {
        ui->pushButton_3->setText(playerMarker);
        btn3 = playerMarker;
        emit turnCompleted();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(btn4 == 'Z') {
        ui->pushButton_4->setText(playerMarker);
        btn4 = playerMarker;
        emit turnCompleted();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(btn5 == 'Z') {
        ui->pushButton_5->setText(playerMarker);
        btn5 = playerMarker;
        emit turnCompleted();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(btn6 == 'Z') {
        ui->pushButton_6->setText(playerMarker);
        btn6 = playerMarker;
        emit turnCompleted();
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(btn7 == 'Z') {
        ui->pushButton_7->setText(playerMarker);
        btn7 = playerMarker;
        emit turnCompleted();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(btn8 == 'Z') {
        ui->pushButton_8->setText(playerMarker);
        btn8 = playerMarker;
        emit turnCompleted();
    }
}

void MainWindow::switchTurn()
{
    if(playerMarker == 'X') {
        playerMarker = 'O';
    } else if(playerMarker == 'O') {
        playerMarker = 'X';
    }
    ui->textEditInfo->setText("Player " + playerMarker + " turn");
}

void MainWindow::winnerCounting()
{
    if(btn0 == 'X' and btn1 == 'X' and btn2 == 'X') {
        playerMarker = 'X';
        ui->textEditInfo->setText("Player " + playerMarker + " WINS!");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) {
        this->close();
    }
}

