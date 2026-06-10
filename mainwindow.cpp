#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    COMPORT = new QSerialPort();
    COMPORT->setPortName("COM14");
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud19200);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QSerialPort::ReadWrite);

    if (COMPORT->isOpen()) {
        qDebug() << "Serial Port is Connected.";

    } else {
        qDebug() << "Serial Port is not Connected.";
        qDebug() << COMPORT->error();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Send_clicked()
{
    QByteArray StartCom = QByteArray::fromHex("02011601");
    if (COMPORT->isOpen()) {
        COMPORT->write(StartCom);
        qDebug() << StartCom;
    } else {
        COMPORT->write(StartCom);
        qDebug() << StartCom;
    }
}

//COMPORT->write(ui->lineEdit_Serial_Data->text().toLatin1() + char(02) + char(1) + char(16) + char (1));
