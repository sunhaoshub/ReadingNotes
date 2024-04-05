#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("服务端");

    m_s = new QTcpServer(this);
    ui->port->setText("8899");

    connect(m_s,&QTcpServer::newConnection,this,[=](){
        m_tcp = m_s->nextPendingConnection();
        m_status->setPixmap(QPixmap("://true.webp").scaled(20,20));

        connect(m_tcp,&QTcpSocket::readyRead,this,[=](){
            QByteArray data = m_tcp->readAll();
            ui->record->append("客户端say："+data);
        });

        connect(m_tcp,&QTcpSocket::disconnected,this,[=](){
            m_tcp->close();
            m_tcp->deleteLater();
            m_status->setPixmap(QPixmap("://false.webp").scaled(20,20));
        });
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

void MainWindow::on_setListen_clicked()
{
    unsigned short port = ui->port->text().toShort();
    m_s->listen(QHostAddress::Any,port);
    ui->setListen->setDisabled(true);
}

void MainWindow::on_sendMsg_clicked()
{
    QString msg = ui->msg->toPlainText();
    m_tcp->write(msg.toUtf8());
    ui->record->append("服务端say："+msg);
}
