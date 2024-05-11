#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include<QToolTip>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //需要对每个子窗口实现鼠标追踪，对父画面实现追踪不能被子画面继承
    setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"mouseMoveEvent";
    QPoint pos = event->pos();
    QString tipText = QString("Mouse Position: (%1,%2)").arg(pos.x()).arg(pos.y());
    QToolTip::showText(mapToGlobal(pos),tipText,this);
    qDebug()<<tipText;
    QMainWindow::mouseMoveEvent(event);
}
