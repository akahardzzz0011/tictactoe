#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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

signals:
    void turnCompleted();
    void buttonValue();

private:
    Ui::MainWindow *ui;
    QString playerMarker;
    QString btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
