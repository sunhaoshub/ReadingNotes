# 理解网络编程和套接字

## 1.1理解网络编程和套接字

可以参照固定电话来理解套接字

1.调用socket函数：安装电话机

```C++ 
#include<sys/socket.h>
int socket(int domain,int type,int protocol);
//成功时返回文件描述符，失败时返回-1
```

2.调用bind函数(分配IP地址和端口号)：分配电话号码

```c++
#include<sys/socket.h>
int bind(int sockfd,struct sockaddr *myaddr,socklen_t addrlen);
```

3.调用listen函数：连接电话线

```C++
#include<sys/socket.h>
int listen(int sockfd,int backlog);
```

4.调用accept函数：拿起电话

```C++
#include<sys/socket.h>
int accept(int sockfd,struct sockaddr *addr,socklen_t *addrlen);
```

## 1.2基于Linux的文件操作

​		在Linux中，socket被视为文件的一种，因此，操作socket和操作文件没有区别；但在Windows中有区别，因此需要在WIndows中使用特殊的数据传输函数。

### 底层文件访问（Low-Level File Access）和文件描述符（File Descriptor）

​		**标准输入、标准输出和标准错误也有相应的文件描述符，分别是0,1,2**。文件和输入输出对象一般是经过创建才会有文件描述符，而标准输入输出、错误，程序开始运行后就会自动分配。

#### 打开文件

```C++
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int open(const char* path,int flag);
```

第二个参数可能的值

![image-20231007224610566](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231007224610566.png)

#### 关闭文件

```C++
#include<unistd.h>
int close(int fd);
```

#### 将数据写入文件

```C++
#include<unistd.h>
ssize_t write(int fd,void* buf,size_t nbytes);
/*
buf：传输数据的缓冲地址
nbytes：要传输数据的字节数
*/
```

#### 示例

```C++
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd;
    char buf[] = "Let's go!\n";
    fd = open("/home/ubuntu/study/data.txt",O_CREAT| O_TRUNC|O_WRONLY);
    if(fd == -1)
        printf("open() error\n");
    if(write(fd,buf,sizeof(buf)) == -1)
        printf("write() error\n");
    close(fd);
}
```

#### 从文件中读取数据

```C++
int read(int fd,void* buff,size_t nbytes);
/*
要打开文件的文件描述符
读取数据的缓冲区
接收数据的最大字节数
*/
```

```C++
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#define BUFF_SIZE 100
int main()
{
    int fd;
    fd = open("/home/ubuntu/study/data.txt",O_RDONLY);
    if(fd == -1)
        printf("open() error");
    printf("file descripter = [%d]",fd);
    char buf[BUFF_SIZE];
    if(read(fd,buf,sizeof(buf)) == -1)
        printf("read() error");
    printf("file data = [%s]",buf);
    close(fd);
}
```

## 1.3基于Windows平台的实现

导入winsock2.h

链接ws2_32.lib库

### winsock的初始化

```C++
#include<winsock2.h>
int WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData);
/*
成功时返回0，失败时返回非0的错误代码值
wVersionRequested 程序员需要的Winsock版本信息
lpWSAData WSADATA结构体变量的地址值
*/
```

WORD类型是通过unsigned short类型，若版本为1.2，则1是主版本号，2是副版本号，应该传递0x0201，由此可见，高8位为副版本号，低8位为主版本号，可以借助MAKEWORD宏函数来构建版本信息

```C++
MAKEWORD(1,2);//版本1.2
```

第二个参数lpWSAData需要传入WSADATA 型结构体变量的地址（LPWSADATA是WSADATA 的指针类型）

调用完函数后，相应参数中将填充已初始化的库信息

### winsock的注销

```C++
#include<winsock2.h>
int WSACleanup();//成功返回0，失败返回SOCKET_ERROR
```

调用该函数时，Winsock相关库将归还给Windows操作系统，无法再调用Winsock相关函数

## Windows 中的文件句柄和套接字句柄

Windows中要区分文件句柄和套接字句柄，两者之间有一定的区别，不像Linux下完全相同

### 基于WIndows的IO函数

WIndows严格区分文件IO函数和套接字IO函数

```C++
#include<winsock2.h>
int send(SOCKET s,const char* buf,int len,int flags);
/*
s ：数据传输对象连接的套接字句柄有
flags：传输数据用到的多种选项信息，一般为0
成功时返回传输的字节数，失败时返回SOCKET_ERROR
*/
```

```C++
#include<winsock2.h>
int recv(SOCKET s,char* buf,int len,int flag);
/*
s:数据接收对象的套接字句柄
*/
```

# 2 套接字类型与协议设置

## 2.1套接字协议及数据传输特性

协议：为了完成数据交换而定好的约定

```C++
#include<sys/socket.h>
int socket(int doamain,int type,int protocol);
/*
成功时返回文件描述符，失败时返回-1
domain:协议族信息
type：套接字数据传输类型信息
protocol：计算机通信协议信息
*/
```

### 协议族（Protocol Family）

![image-20231009220507468](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231009220507468.png)

### 套接字类型

套接字传输数据的方式

确定了协议族并不能确定数据传输方式，一个协议族可能对应多种数据传输方式

#### 两种基本套接字

#### 面向连接的套接字（SOCK_STREAM）

* 保证数据传输的顺序正确
* 保证数据不出差错
* 没有数据边界（不考虑传输多少次，只要达到最终的数量就可以）
* 一对一
* 按字节传输

参考流水线

面向连接的套接字内部有缓冲区，收到数据后不一定立刻调用read()函数。只要缓冲区不溢出，可能会调用多次read()，也可能调用一次read()。

在面向连接的套接字中，讨论read()和write()的执行次数并没有太大意义

#### 面向消息的套接字（SOCK_DGRAM）

* 强调快速传输而非传输顺序
* 传输的数据可能丢失也可能损毁
* 传输的数据有数据边界
* 限制每次传输的数据大小

参考快递

面向消息的套接字不存在连接的概念



满足协议族为IPv4协议族（PF_INET），且套接字类型为面向连接传递（SOCKET_STREAM）的，只有一种协议：IPPROTO_TCP，故这个套接字被称为TCP套接字

```C++
int tcp_socket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
```

满足上述条件的面向消息（SOCKET_DGRAM）的套接字只有IPPROTO_UDP，故这个套接字被称为UDP套接字

```C++
int udp_socket = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
```

# 3 地址族与数据序列

端口号不能重复，但TCP套接字和UDP套接字不会共用一个端口，所以允许重复

## 3.2 地址信息的表示

```C++
struct sockaddr_in
{
    sa_family_t sin_family;//地址族
    uint16_t sin_port;//16位端口号
    struct in_addr sin_addr;//32位IP地址
    char sin_zero[8];//不使用
};
struct in_addr
{
    In_addr_t s_addr;//32位Ipv4地址
}

```

sin_family:

![image-20231010220524042](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231010220524042.png)

sin_zero

无特殊含义，只是为了保持与sockaddr结构体一致

## 3.3 网络字节序与地址变换

大端法：正常理解的顺序

主流的Intel系列CPU采用小端法保存数据

网络传输时统一为**大端序**；

### 字节序转换

h代表主机字节序

n代表网络字节序

```C++
unsigned short htons(unsigned short);
unsigned long htonl(unsigned long);
unsigned short ntohs(unsigned short);
unsigned long ntohl(unsigned long);
```

Linux中long占4个字节

除了向sockaddr_in结构体传输数据需要转换字节序外，别的都是自动进行的

## 3.4 网络地址的初始化与分配

### 将字符串信息转化为网络字节序的整数型

```C++
#include<arpa/inet.h>
in_addr_t inet_addr(const char* string);
```

成功时返回32位大端序整数型值，失败时返回INADDR_NONE.

```c
#include<stdio.h>
#include<arpa/inet.h>

int main(int argc,char* argv[])
{
    const char* addr1 = "1.168.0.1";
    const char* addr2 = "0.0.0.256";

    unsigned long conv = inet_addr(addr1);
    if(conv == INADDR_NONE)
        printf("error occured\n");
    else
        printf("net address : %#lx\n",conv);
    conv = inet_addr(addr2);
    if(conv == INADDR_NONE)
        printf("error occured\n");
    else
        printf("net address : %#lx\n",conv);
}
```

inet_aton()函数与inet_addr()函数的功能完全相同，但该函数使用了in_addr结构体，效率更高

```C++
#include<arpa/inet.h>
int inet_aton(const char* string,struct in_addr* addr);
```

```C
#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    char *addr = "192.168.0.1";
    struct sockaddr_in in_addr;
    if(!inet_aton(addr,&in_addr.sin_addr.s_addr))
        printf("error\n");
    else
        printf("Network order integer addr:%#x\n",in_addr.sin_addr.s_addr);
    return 0;
}
```

把网络字节整数型数据转化为熟悉的点分十进制字符串形式的函数

```C
#include<arpa/inet.h>
char* inet_ntoa(struct in_addr adr);
```

该函数未要求程序员分配内存空间，而是在内部申请了一块内存空间，在再一次调用inet_ntoa()函数之前，地址都是有效的，若要长期保存，则需要用新的内存空间保存

### 服务端网络地址初始化

```C
struct sockaddr_in addr;
char* serv_ip = "127.0.0.1";
char* serv_port = "8081";
memset(&addr,0,sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = inet_addr(serv_ip);
addr.sin_port = htons(atoi(serv_port));
```

### 客户端网络地址初始化

服务端采用bind函数完成地址初始化，而客户端采用connect函数完成地址初始化；

### INADDR_ANY

常数，自动获取服务器客户端的IP地址

若一台计算器有多个IP地址，如路由器，只要端口一致，就可以从不同IP地址接收数据

### 向套接字分配网络地址

```C
#include<sys/socket.h>
int bind(int sockfd,struct sockaddr* myaddr,socklen_t addrlen);
/*
成功时返回0，失败时返回-1；
sockfd：要分配地址信息（IP地址和端口）的套接字描述符
myaddr：存有地址信息的结构体变量地址值
addrlen：结构体变量的长度
*/
```

### 服务端常用的套接字绑定步骤

```C
int serv_sock;
char* serv_port = "9190";
serv_sock = socket(PF_INET,SOCK_STREAM,0);
struct sockaddr_in addr;
memset(&addr,0,sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY);
addr.sin_port = htons(atoi(serv_port));

bind(serv_sock,(struct sockaddr*)&addr,sizeof(addr));
```

# 4 基于TCP的服务端/客户端(1)

IP协议本身是面向消息的，不可靠的传输协议，不能处理数据传输出错的情况

IP层解决数据传输的路径问题；

TCP和UDP依据IP层选择好的路径来传输数据；

为什么TCP协议能保证数据准确传输，但却选择了IP协议为基础？

​	如果数据交换过程中可以确认对方已经收到数据，并重传丢失数据，那么即使IP层不保证数据传输可靠性，这类通信也是你可靠的

## 4.2 实现基于TCP的服务端/客户端

![image-20231012163029923](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231012163029923.png)

### 进入等待连接请求状态（listen函数）

调用bind()函数为套接字分配地址后，调用listen()函数进入等待连接请求状态

```C
#include<sys/socket.h>
int listen(int sock,int backlog);
/*
成功时返回0，失败时返回-1
backlog:连接请求等待队列的长度
*/
```

### 受理客户端连接请求

服务端的套接字是充当“门卫”的，如果和在客户端的交互中使用门卫，那么没有人守门，因此需要另一个套接字

accept()函数将自动创建套接字，并且连接到发起请求的客户端

```C
#include<sys/socket.h>
int accept(int sock,struct sockaddr* addr,socklen_t* addrlen);
/*
sock：服务器套接字的文件描述符
addr：保存发起连接请求的客户端地址信息的变量地址值，调用函数后向传递来的地址变量参数填充客户端地址信息
addrlen
*/
```

![image-20231016205650449](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231016205650449.png)

客户端与服务端相比，区别在于“请求连接”

```C++
#include<sys/socket.h>
int connect(int sock,struct sockaddr* servaddr,socklen_t addrlen);
/*
成功时返回0，失败时返回-1
sock：客户端套接字文件描述符
servaddr：保存目标服务器地址信息的变量地址
addrlen：以字节为单位传递给第二个参数的地址变量长度
*/
```

客户端调用connect函数后，发生以下情况之一才会返回：

* 服务器端接收连接请求
* 发生断网等异常情况而中断连接请求

所谓的“接受连接”并不意味着服务器端调用accept函数，而是把连接请求记录到等待队列。因此connect函数返回后不立即进行数据交换

客户端的IP地址和端口在调用connect函数时自动分配，无需调用bind函数

![image-20231016213034602](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231016213034602.png)

客户端只有等到服务端调用listen结束后才能调用connect

## 4.3 实现迭代服务器端/客户端

