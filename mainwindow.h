#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>

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

private slots:
    void on_pushButton_Send_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    QSerialPort *COMPORT;
};
#endif // MAINWINDOW_H
