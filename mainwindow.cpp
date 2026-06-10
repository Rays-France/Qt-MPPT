#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitCOM();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitCOM()
{
    COMPORT = new QSerialPort();
    const auto listPorts = QSerialPortInfo::availablePorts();
    qDebug() << "Serial ports count : " << listPorts.size();

    foreach (const QSerialPortInfo &portInfo, listPorts) {
        qDebug() << "-----------------------------------------------------";
        qDebug() << "Port Name:          " << portInfo.portName();
        qDebug() << "System Location:    " << portInfo.systemLocation();
        qDebug() << "Description:        " << portInfo.description();
        qDebug() << "Manufacturer:       " << portInfo.manufacturer();
        qDebug() << "Serial Number:      " << portInfo.serialNumber();


    }

    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud19200);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    //COMPORT->open(QSerialPort::ReadWrite);


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

void MainWindow::on_comboBox_activated(int index)
{
    ui->COMBox->clear();
    foreach (const QSerialPortInfo &portInfo, listPorts) {
        ui->COMBox->additem(portInfo.portName()+" "+portInfo.description());
    }
}

