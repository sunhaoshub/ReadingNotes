# 信号槽

信号槽是可以被继承的

建立信号函数和槽函数之间的对应关系，使用QObject类的connect函数

基本模板：

```C++
connect(const QObject* sender,&Qobject::signal
       	const QObject* receiver,&QObject::method);
```

## 标准信号槽

## 自定义信号槽

* 自定义的信号或槽是需要在新的类中实现，而不是在已有的类中添加；
* 新的类必须继承QObject类或其子类，并且加入Q_OBJECT宏；

### 自定义信号

* void类型
* 用signals声明，类似public

### 自定义槽

* 参数个数与信号对应（大于等于即可）