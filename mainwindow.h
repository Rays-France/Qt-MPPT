#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QMouseEvent>

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
    void InitCOM();
    void ReloadCOMList();

private slots:
    void on_pushButton_Send_clicked();


private:
    Ui::MainWindow *ui;
    QSerialPort *COMPORT;
};



#endif // MAINWINDOW_H
