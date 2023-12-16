# 信号槽

信号槽是可以被继承的

建立信号函数和槽函数之间的对应关系，使用QObject类的connect函数

基本模板：

```C++
Qt5：
connect(const QObject* sender,&Qobject::signal
       	const QObject* receiver,&QObject::method);
//传递信号和槽的地址
Qt4：
    connect(const QObject* sender,SIGNAL(Qobject::signal())
       	const QObject* receiver,SLOT(QObject::method));
```

槽函数的类型：

* 类的成员函数
* 全局函数
* 静态函数
* Lambda表达式

## 标准信号槽

## 自定义信号槽

* 自定义的信号或槽是需要在新的类中实现，而不是在已有的类中添加；
* 新的类必须继承QObject类或其子类，并且加入Q_OBJECT宏；

### 自定义信号

* void类型
* 用signals声明，类似public
* 只需声明，无需定义
* **需要通过其他手段将自定义信号发射出去**；

### 自定义槽

* 参数个数与信号对应（大于等于即可）

* 使用`public slots`声明

* 需要在对应的cpp文件添加定义

  

## Lambda表达式

```
[capture](param) opt ret{body}();
--capture：捕获列表
--param：参数列表
--opt：选项 mulitable 允许使用只读数据
--ret：返回值类型
第二个()表示实参
```

### 捕获列表

```
[]--不捕获任何信号
[&]--捕获外部作用域的所有变量，并作为引用在函数体内使用（按引用捕获）
[=]--捕获外部作用域的所有变量，并作为副本在函数体内使用，拷贝的副本在匿名函数体内部是只读的（按值捕获）
[=,&foo]--按值捕获所有变量，并按引用捕获变量foo
[bar]--按值捕获bar变量
[this]--捕获当前类的this指针
	让lambda表达式拥有和当前类成员函数同样的访问权限
	如果已经使用了&或者=，默认添加此选项
```

# QTimer

```
1.创建QTimer对象
	QTimer(QObject* parent = nullptr);
2.设置启动时间
	start(int msec);
	
	setInterval(int msec);
	start();
3.定时器到时间后，会发出信号
	timeout();
```



```
设置时间精度：setTimerType(Qt::TimerType);
判断定时器是否正在运行：QTimer::isActive();
判断定时器是否只触发一次：bool QTimer::isSingleSlot();
设置定时器是否只触发一次：QTimer::setSingleSlot(bool singleSlot);
只发射一次的静态函数：singleShot
[static] void QTimer::singleShot(
        int msec, const QObject *receiver, 
        PointerToMemberFunction method);
```

mainwindow.cpp

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QTimer>
#include<QTime>
#include<QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
    //循环监听
    connect(ui->loopBtn,&QPushButton::clicked,this,[=](){
        if(timer->isActive())
        {
            timer->stop();
            ui->loopBtn->setText("开始");
        }
        else
        {
            ui->loopBtn->setText("关闭");
            //1s后启动定时器
            timer->start(1000);
        }

    });
    connect(timer,&QTimer::timeout,this,[=](){
        QTime tm = QTime::currentTime();
        QString curTime = tm.toString("hh:mm:ss.zzz");
        ui->curTime->setText(curTime);
    });
    //单次监听
    connect(ui->singleButton,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(2000,this,[=](){
            QTime tm = QTime::currentTime();
            QString curTime = tm.toString("hh:mm:ss.zzz");
            ui->singleTime->setText(curTime);
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

