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

# QWidget



```C++
//构造函数
QWidget::QWidget(QWidget* parent = nullptr,Qt::WindowFlags f = new WindowFlags());
//WindowFlags：显示窗口边框

//设置父对象
void QWidget::setParent(QWidget* parent);
//获取当前窗口的父对象
QWidget* QWidget::parentWidget() const;


//信号
void customContextMenuRequested(const QPoint& pos);
void windowIconCHanged(const QIcon& icon);
void windowTitleChanged(const QString& title);
```



```C++
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口最小值
    //setMinimumSize(300,300);
    //设置窗口最大值
    //setMaximumSize(600,600);
    //设置固定大小窗口
    //setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("Hello,Qt");
    //设置窗口图标
    //setWindowIcon
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_moveBtn_clicked()
{
    QRect rect = this->geometry();
    move(rect.topLeft()+QPoint(10,20));
}

void Widget::on_positionBtn_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << "左上角: " << rect.topLeft()
                 << "右上角: " << rect.topRight()
                 << "左下角: " << rect.bottomLeft()
                 << "右下角: " << rect.bottomRight()
                 << "宽度: " << rect.width()
                 << "高度: " << rect.height();

}

void Widget::on_geometryBtn_clicked()
{
    int x = 100 + rand() % 500;
        int y = 100 + rand() % 500;
        int width = this->width() + 100;
        int height = this->height() + 100;
    setGeometry(x,y,width,height);

}
```

```C++
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMainWindow>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口最小值
    //setMinimumSize(300,300);
    //设置窗口最大值
    //setMaximumSize(600,600);
    //设置固定大小窗口
    //setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("Hello,Qt");
    //设置窗口图标
    setWindowIcon(QIcon("C:\\Users\\sunha\\Desktop\\book\\ReadingNotes\\Qt\\Icon.webp"));
    //QWidget信号槽
    connect(this,&Widget::windowTitleChanged,this,[=](const QString& title){
        qDebug()<<"修改后的标题"<<title;
    });
    connect(this,&Widget::windowIconChanged,this,[=](const QIcon& icon){
        qDebug()<<"图标改变了";
    });
    //右键显示菜单
    //1.发出信号
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&Widget::customContextMenuRequested,this,[=](const QPoint& pos){
        QMenu menu;
        menu.addAction("a");
        menu.exec(QCursor::pos());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_moveBtn_clicked()
{
    QRect rect = this->geometry();
    move(rect.topLeft()+QPoint(10,20));
}

void Widget::on_positionBtn_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << "左上角: " << rect.topLeft()
                 << "右上角: " << rect.topRight()
                 << "左下角: " << rect.bottomLeft()
                 << "右下角: " << rect.bottomRight()
                 << "宽度: " << rect.width()
                 << "高度: " << rect.height();

}

void Widget::on_geometryBtn_clicked()
{
    int x = 100 + rand() % 500;
        int y = 100 + rand() % 500;
        int width = this->width() + 100;
        int height = this->height() + 100;
    setGeometry(x,y,width,height);

}

void Widget::on_modifyBtn_clicked()
{
    setWindowTitle("Hello,World");
    setWindowIcon(QIcon("C:\\Users\\sunha\\Desktop\\book\\ReadingNotes\\Qt\\icon2.webp"));
}
```

# QDialog

MyDialog.cpp

```
#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_acceptBtn_clicked()
{
    this->accept();
}

void MyDialog::on_rejectBtn_clicked()
{
    this->reject();
}

void MyDialog::on_doneBtn_clicked()
{
    this->done(1);
}

```

widget.cpp

```C++
#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMainWindow>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_modelBtn_clicked()
{
    MyDialog dialog;
    connect(&dialog,&QDialog::accepted,this,[=](){
       qDebug()<<"accept 信号被接受了";
    });
    connect(&dialog,&QDialog::rejected,this,[=](){
       qDebug()<<"reject 信号被接受了";
    });
    connect(&dialog,&QDialog::finished,this,[=](int res){
       qDebug()<<"finished 信号被接受了："<<res;
    });
    int ret = dialog.exec();
    if(ret == QDialog::Accepted)
    {
        qDebug()<<"accept button clicked";
    }
    else if(ret == QDialog::Rejected)
    {
         qDebug()<<"reject button clicked";
    }
    else
    {
         qDebug()<<"done button clicked";
    }
}

```

# QFileDialog

## 静态成员方法

```
//获取一个目录的绝对路径
QString QDileDialog::getExistingDirectory();
//获取一个文件的绝对路径
QString QDileDialog::getOpenFileName();
//获取多个文件的绝对路径
QStringList QFileDialog::getOpenFileNames();
//打开一个目录，用这个目录来保存指定的文件
QStringList QFileDialog::getSaveFileName();


/*
通用参数:
  - parent: 当前对话框窗口的父对象也就是父窗口
  - caption: 当前对话框窗口的标题
  - dir: 当前对话框窗口打开的默认目录
  - options: 当前对话框窗口的一些可选项,枚举类型, 一般不需要进行设置, 使用默认值即可
  - filter: 过滤器, 在对话框中只显示满足条件的文件, 可以指定多个过滤器, 使用 ;; 分隔
    - 样式举例: 
	- Images (*.png *.jpg)
	- Images (*.png *.jpg);;Text files (*.txt)
  - selectedFilter: 如果指定了多个过滤器, 通过该参数指定默认使用哪一个, 不指定默认使用第一个过滤器
*/
```

```C++
#include "dialog.h"
#include "ui_dialog.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_filedDlg_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this,u8"open file","C:\\");
    QMessageBox::information(this,"打开目录","选择的目录是："+dirName);
}

void Dialog::on_openFile_clicked()
{
    QString arg("Text files (*.txt)");
    QString fileName = QFileDialog::getOpenFileName(this,"open file",
                                                    "C:\\Users\\sunha\\Desktop\\book", "Images (*.png *.jpg);;Text files (*.txt);;pdf files(*.pdf);;zip files(*.zip *.rar)",&arg);
    QMessageBox::information(this,"打开文件","打开的文件是："+fileName);
}

void Dialog::on_multiFiles_clicked()
{
    QString arg("Text files (*.txt)");
    QStringList fileNames = QFileDialog::getOpenFileNames(this,"open file",
                                       "C:\\Users\\sunha\\Desktop\\book","Images (*.png *.jpg);;Text files (*.txt);;pdf files(*.pdf);;zip files(*.zip *.rar)",&arg);
    QString names;
    for(int i=0;i < fileNames.size();i++)
    {
        names += fileNames.at(i)+" ";
    }
    qDebug()<<names;
    QMessageBox::information(this,"打开文件(s)","打开的文件是："+names);
}

```

# QInputDialog
