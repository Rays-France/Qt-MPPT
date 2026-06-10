#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyComboBox.h"


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
    //Config Port Série
    COMPORT = new QSerialPort();

    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud19200);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);

    //Config Liste Port COM
    MyComboBox *myCombo = new MyComboBox(this);
    myCombo->setGeometry(110,30,150,20);
    connect(myCombo,&MyComboBox::aboutToPopup, this,&MainWindow::ReloadCOMList);

    const auto listPorts = QSerialPortInfo::availablePorts();
    qDebug() << "Serial ports count : " << listPorts.size();

    foreach (const QSerialPortInfo &portInfo, listPorts) {
        qDebug() << "-----------------------------------------------------";
        qDebug() << "Port Name:          " << portInfo.portName();
        qDebug() << "System Location:    " << portInfo.systemLocation();
        qDebug() << "Description:        " << portInfo.description();
        qDebug() << "Manufacturer:       " << portInfo.manufacturer();
        myCombo->addItem(portInfo.portName()+" "+portInfo.description());
    }
    myCombo->adjustSize();



    //COMPORT->open(QSerialPort::ReadWrite);

}


void MainWindow::ReloadCOMList()
{
    myCombo->clear();

    const auto listPorts = QSerialPortInfo::availablePorts();
    qDebug() << "Serial ports count : " << listPorts.size();

    foreach (const QSerialPortInfo &portInfo, listPorts) {
        myCombo->addItem(portInfo.portName()+" "+portInfo.description());
    }
    myCombo->adjustSize();

    qDebug() << "Ports update";
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


