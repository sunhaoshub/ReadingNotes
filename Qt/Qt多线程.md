* 默认的线程在Qt中称为窗口线程，也叫主线程，负责窗口事件处理或者窗口控件数据的更新
* 子线程负责后台的业务逻辑处理，不能对窗口对象进行任何操作，这些事情需要交给窗口线程处理
* 主线程和子线程进行数据的传递，需要使用信号槽

# 线程类QThread

相关函数：

```C++
//判断执行的任务是否结束
bool isfinished();
//判断子线程是否正在运行
bool isRunning();

//退出函数,执行之后并不是立即退出，而是等待任务执行结束之后退出
void exit();
bool wait();


[signal] void finished();//执行任务结束后发出的信号

[slot] void terminate();//立刻终止任务
[slot] void quit();//和exit一样
[slot] void start();//启动线程

[static] QThread* QThread::currentThread();//返回当前执行线程的指针
//线程休眠函数
[static] void QThread::msleep(unsigned long);//毫秒
[static] void QThread::sleep(unsigned long);//秒
[static] void QThread::usleep(unsigned long);//微秒

[virtual protected]  void run();
如果想让创建的子线程执行某个任务，需要写一个子类让其继承QThread，并且在子类中重写父类的run()方法，函数体就是对应的任务处理流程。另外，这个函数是一个受保护的成员函数，不能够在类的外部调用，如果想要让线程执行这个函数中的业务流程，需要通过当前线程对象调用槽函数start()启动子线程，当子线程被启动，这个run()函数也就在线程内部被调用了。
```



## 使用方法1

```
1、创建子线程类并继承QThread
2、在子线程类中重写run方法，并在start函数中使用run方法
3、在主线程中声明子类并使用
```

通过子线程生成随机数，并返回给主线程：

mainwindow.h

```C++
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
signals:
    void starting(int num);
};

#endif // MAINWINDOW_H

```

mythread.h

```C++
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QThread>
#include<QVector>

class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

signals:
    void sendArray(QVector<int> list);
public slots:
    void recvNum(int num);
protected:
    void run();
private:
    int m_num;
};

#endif // MYTHREAD_H

```



main.cpp

```C++
#include "mainwindow.h"
#include <QApplication>
#include<QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //原始的信号槽不支持传递QVector<int>，需要声明
    qRegisterMetaType<QVector<int>>("QVector<int>");
    MainWindow w;
    w.show();

    return a.exec();
}

```



mainwindow.cpp

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mythread.h"
#include<QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Generate* gen = new Generate;
    connect(this,&MainWindow::starting,gen,&Generate::recvNum);
    //点击按钮启动
    connect(ui->startBtn,&QPushButton::clicked,this,[=]{
        emit starting(100000);
        gen->start();
    });

    connect(gen,&Generate::sendArray,this,[=](QVector<int> list){
            for(int i = 0;i < list.size();i++)
            {
                ui->randList->addItem(QString::number(list[i]));
            }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

```

mythread.cpp

```C++
#include "mythread.h"
#include<QDebug>
#include<QElapsedTimer>

Generate::Generate(QObject *parent) : QThread(parent)
{

}
//接收主线程传过来的生成随机数的数量的值
void Generate::recvNum(int num)
{
    m_num = num;
}

void Generate::run()
{
    qDebug()<<"子线程的地址是:"<<QThread::currentThreadId();
    QElapsedTimer time;
    QVector<int> list;
    time.start();
    for(int i = 0;i < m_num;i++)
    {
        list.push_back(qrand()%100000);
    }
    int milsec = time.elapsed();
    qDebug()<<"生成"<<m_num<<"个随机数所用的时间是："<<milsec<<"毫秒";
    //发射信号将存储随机数的vector传给主线程
    emit sendArray(list);
}

```

## 使用方法2

1.创建一个新的类，让这个类从QObject类中派生

```C++
class MyWork:public QObject
{}
```

2.在类中添加一个公共成员函数(可以自由传递参数)，函数体就是子线程的业务逻辑

```C++
class MyWork:public QObject
{
    public:
    	void working();
}
```

3.在主线程中创建QThread对象

```C++
QTread* thread = new QThread;
```

4.创建工作类对象(不要指定父对象)

```C++
MyWork* work = new MyWork;
```

5.将工作对象移动到子线程中，使用QObject类提供的moveToThread方法

```C++
work->moveToThread(sub);
```

6.调用start方法启动线程，但线程没有工作

7.调用工作类的工作函数开始使用

