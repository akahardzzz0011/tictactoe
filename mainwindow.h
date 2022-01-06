#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void switchTurn();
    void winnerCounting();
    void scoreboard();
    void on_btnNewRound_clicked();
    void on_btnClearScores_clicked();

signals:
    void turnCompleted();
    void buttonValue();
    void countPoints();

private:
    Ui::MainWindow *ui;
    QChar playerMarker;
    QString strPlayer, strPointsX, strPointsO, strPointsTie;
    QChar boardButton[3][3] =  {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};
    int pointsX, pointsO, pointsTie, tieCounter;
    bool playerTurnSwitch, scoreLock;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
