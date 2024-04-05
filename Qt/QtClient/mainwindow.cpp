#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("客户端");

    m_tcp= new QTcpSocket(this);
    ui->port->setText("8899");
    ui->ip->setText("127.0.0.1");

    connect(m_tcp,&QTcpSocket::readyRead,this,[=](){
                QByteArray data = m_tcp->readAll();
                ui->record->append("服务端say："+data);
            });
    connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
        m_tcp->close();
        m_tcp->deleteLater();
        m_status->setPixmap(QPixmap("://false.webp").scaled(20,20));
        ui->record->append("断开了连接。。。");
    });

    connect(m_tcp,&QTcpSocket::connected,this,[=](){
        m_status->setPixmap(QPixmap("://true.webp").scaled(20,20));
        ui->record->append("建立了连接。。。");

    });

    m_status = new QLabel;
    m_status->setPixmap(QPixmap("://false.webp").scaled(20,20));
    ui->statusBar->addWidget(new QLabel("连接状态："));
    ui->statusBar->addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_setListen_clicked()
//{
//    unsigned short port = ui->port->text().toShort();
//    m_s->listen(QHostAddress::Any,port);
//    ui->setListen->setDisabled(true);
//}

//void MainWindow::on_sendMsg_clicked()
//{
//    QString msg = ui->msg->toPlainText();
//    m_tcp->write(msg.toUtf8());
//    ui->record->append("服务端say："+msg);
//}

void MainWindow::on_connect_clicked()
{
    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();
    m_tcp->connectToHost(QHostAddress(ip),port);
}

void MainWindow::on_sendMsg_clicked()
{
    QString msg = ui->msg->toPlainText();
    m_tcp->write(msg.toUtf8());
     ui->record->append("客户端say："+msg);
}

void MainWindow::on_disconnect_clicked()
{
    m_tcp->close();
}
