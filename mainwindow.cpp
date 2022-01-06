#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playerTurnSwitch = false, scoreLock = false;
    playerMarker = 'X';
    strPlayer = 'X';
    strPointsX = "0", strPointsO = "0", strPointsTie = "0";
    pointsX = 0, pointsO = 0, pointsTie = 0, tieCounter = 0;
    ui->textEditInfo->setText("Player " + strPlayer + " turn");
    ui->lineEditPlayerX->setText(strPointsX);
    ui->lineEditPlayerO->setText(strPointsO);
    ui->lineEditTie->setText(strPointsTie);
    connect(this, SIGNAL(turnCompleted()), this, SLOT(switchTurn()));
    connect(this, SIGNAL(buttonValue()), this, SLOT(winnerCounting()));
    connect(this, SIGNAL(countPoints()), this, SLOT(scoreboard()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_0_clicked()
{
    if(boardButton[0][0] == '0') {
        ui->pushButton_0->setText(playerMarker);
        boardButton[0][0] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    if(boardButton[0][1] == '1') {
        ui->pushButton_1->setText(playerMarker);
        boardButton[0][1] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(boardButton[0][2] == '2') {
        ui->pushButton_2->setText(playerMarker);
        boardButton[0][2] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(boardButton[1][0] == '3') {
        ui->pushButton_3->setText(playerMarker);
        boardButton[1][0] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(boardButton[1][1] == '4') {
        ui->pushButton_4->setText(playerMarker);
        boardButton[1][1] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(boardButton[1][2] == '5') {
        ui->pushButton_5->setText(playerMarker);
        boardButton[1][2] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(boardButton[2][0] == '6') {
        ui->pushButton_6->setText(playerMarker);
        boardButton[2][0] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(boardButton[2][1] == '7') {
        ui->pushButton_7->setText(playerMarker);
        boardButton[2][1] = playerMarker;

        emit buttonValue();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(boardButton[2][2] == '8') {
        ui->pushButton_8->setText(playerMarker);
        boardButton[2][2] = playerMarker;

        emit buttonValue();
    }
}

void MainWindow::switchTurn()
{
    if(playerMarker == 'X') {
        playerMarker = 'O';
        strPlayer = 'O';
    } else if(playerMarker == 'O') {
        playerMarker = 'X';
        strPlayer = 'X';
    }
    ui->textEditInfo->setText("Player " + strPlayer + " turn");
}

void MainWindow::winnerCounting()
{
    for (int i = 0; i < 3; i++ ) {
        if((boardButton[0][i] == boardButton[1][i] and boardButton[1][i] == boardButton[2][i]) or
                (boardButton[i][0] == boardButton[i][1] and boardButton[i][1] == boardButton[i][2])) {
            ui->textEditInfo->setText("Player " + strPlayer + " WINS!");
            playerTurnSwitch = true;
            emit countPoints();
        }
    }
    if((boardButton[0][0] == boardButton[1][1] and boardButton[1][1] == boardButton[2][2]) or
            (boardButton[0][2] == boardButton[1][1] and boardButton[1][1] == boardButton[2][0])) {
        ui->textEditInfo->setText("Player " + strPlayer + " WINS!");
        playerTurnSwitch = true;
        emit countPoints();
    }
    if(playerTurnSwitch == false) {
        tieCounter += 1;
        emit turnCompleted();
    }
    if(tieCounter == 9) {
        emit countPoints();
    }
}

void MainWindow::scoreboard()
{
    if(playerMarker == 'X' and tieCounter < 9 and scoreLock == false) {
        pointsX += 1;
        scoreLock = true;
        strPointsX = QString::number(pointsX);
        ui->lineEditPlayerX->setText(strPointsX);
    } else if (playerMarker == 'O' and tieCounter < 9 and scoreLock == false) {
        pointsO += 1;
        scoreLock = true;
        strPointsO = QString::number(pointsO);
        ui->lineEditPlayerO->setText(strPointsO);
    } else if(scoreLock == false){
        pointsTie += 1;
        ui->textEditInfo->setText("It is a tie");
        strPointsTie = QString::number(pointsTie);
        ui->lineEditTie->setText(strPointsTie);
    }



}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape) {
        this->close();
    }
}


void MainWindow::on_btnNewRound_clicked()
{
    ui->pushButton_0->setText("");
    ui->pushButton_1->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    playerTurnSwitch = false, scoreLock = false;
    playerMarker = 'X', strPlayer = 'X';
    ui->textEditInfo->setText("Player " + strPlayer + " turn");
    tieCounter = 0;

    int value = 0;
    QChar charValue = value + '0';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++ ) {
            boardButton[i][j] = charValue;
            value += 1;
            charValue = value + '0';
        }
    }

}


void MainWindow::on_btnClearScores_clicked()
{
    pointsX = 0, pointsO = 0, pointsTie = 0;
    strPointsX = "0", strPointsO = "0", strPointsTie = "0";
    ui->lineEditPlayerX->setText(strPointsX);
    ui->lineEditPlayerO->setText(strPointsO);
    ui->lineEditTie->setText(strPointsTie);
}

