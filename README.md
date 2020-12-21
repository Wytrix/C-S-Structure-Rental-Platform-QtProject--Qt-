# Client-Server-Structure-Rental-Platform-QtProject
Computer network course design of rental information publishing platform  
租房交流平台计算机网络编程Qt项目  
网络协议：TCP协议  
编程语言：C++面向对象  
IDE：Qt Creator  
框架：Qt开发框架  
采用Client-Server结构  
服务器：腾讯云服务器CVM  
## 1功能介绍
租房合租交流平台主要以用户登录的形式来进行具体功能的实现。在使用app前都需要注册账号，注册成功后需要用户完善基本个人信息。每个用户具有发布房源以及合租招租的权限。所有发布过的信息（房源信息、合租信息）都会在公共的平台上展示，以便于每个用户查看和咨询。用户之间可以进行线上聊天，聊天渠道是通过咨询的方式实现。用户还可以对个人信息进行修改，修改账户密码等操作。  
## 2概述
租房合租交流平台软件基于Qt开发框架使用了C++程序设计语言进行编写，采用了TCP的网络通信协议，能够保证消息传输的可靠性，而且对于文件传输而言，能够有效减少数据丢失，使得文件传输完整可靠。采用了Client-Server的结构，安全性得到保证，同时客户端和服务器端直接相连、相应速度较快，是常用的软件设计结构。对于云服务器而言，采用了腾讯云提供的云服务器CVM，提供1核1G内存1M网速的性能,可以满足当前程序服务的需要。  
## 3客户端设计
客户端也称为用户端，安装在客户本地机器上运行，需要和服务器端程序配合使用。  
客户端源文件类由4个CPP构成，Button类用于界面部件、Controller用于客户端交互和控制的实现、main创建主程序和主窗口、MainWindow用来设置初始化窗口。  
### 3.1界面设计
使用Qt图形视图框架进行编写，程序界面美观、可以实现众多的自定义效果，可以实现自定义的风格样式。  
创建应用程序和主窗口之后、主要由QGraphicsScene、QGraphicsView、QGraphicsItem来对界面进行构建。QGraphicsScene创建程序窗口的场景，所有在窗口上的部件QgraphicsItem类必须要添加在QGraphicsScene类上才能用QGraphicsView来显示出来，QGraphicsView是视图场景在窗口中显示的部分。在本客户端当中，我们使得QGraphicsScene的大小固定，显示窗口QGraphicsView和QGraphicsScene相同大小，并设置其固定不变，并将QGraphicsScene的背景颜色设置为浅蓝色。  
窗口上部件的设计。使用了Button类对QGraphicsObject类进行继承，实现自定义类。由于程序界面中的部件都主要由矩形框构成，而且所有部件都可以由QGraphicsObject类继承后自己实现得到。为了减少对类的创建，将所有类型的部件全部编写在Button类当中，通过对Button类的不同参数设置，来完成对于不同类型的部件的创建，包括大小、颜色、颜色是否变化、是否为圆角、是否可输入字符等。同时为了保证图形的显示效果美观，对部件加入了颜色横向线性渐变、部件阴影等，同时为了能实现一些动画效果，对Button类鼠标事件进行了重写，可以响应缩放动画。  
场景切换。在Controller类当中构建每个场景的函数，可以实现在不同场景中的切换。每个场景在调用之前有Scene.clear()，将场景清空，保证当前绘制的场景和函数中设计的场景相同。函数如图4所示，跳转关系如图所示。  
### 3.2动画效果
Qt中可以实现QPropertyAnimation属性动画，动画效果流畅自然，通过对相应的属性参数进行修改，就可以实现诸如大小位置变化的动画。其中内置了多种插值曲线，可以对属性参数进行流畅的变化。对每个场景开始时对每个部件加入属性动画、让其从小到大，并在函数开始时执行，部件就可以在界面出现时实现类似弹出的动画效果。  
### 3.3消息传输
客户端在启动时就会建立一个QTcpSocket对象，通过此对象向特定的IP地址和端口请求连接，如果连接失败则弹出“连接错误”的弹出框。  
由于存在多种多样的消息请求，所以将消息传输分为了两个部分，一个是消息类型，一个是消息内容。消息类型是一个16位大小的整数型，用来区分不同的请求，消息内容是一个字符串类型，用于传输具体的消息内容。为了便于消息的传输，创造了一个函数用于发送消息类型和内容。不过由于消息内容可能包含几条消息，如果分多次传输会影响效率，所以使用了特定标识符“::==”进行分隔，可以在一条消息内容中传输多条消息。  
同样，QTcpSocket需要接收消息，同样构造了一个函数用于接收消息，并将其绑定在QTcpSocket对象特定的信号readyRead上，在有消息准备接收时会触发readyRead信号，然后就会执行相关的接收消息函数，根据接收到的类型的不同，再执行不同的函数，这样就可以实现对不同类型函数的不同响应。  
### 3.4文件传输
文件传输不同于消息传输。一般消息传输内容较少，网络带宽足以满足其在短时间内完成传输，但由于文件一般较大，无法在一定时间内完成，如果传输时间过长可能会引起QTcpSocket断开连接，导致传输失败，所以我们需要对文件传输进行改进。  
将单个的文件进行拆分，每份大小为64KB，同时在接收方对每份文件进行组装，知道文件最后完成发送。首先传输整个字节流的总大小和文件名大小，然后传输文件名，最后发送文件数据，前三项内容为以此传输，发送文件数据为拆分后的传输。  
但由于在文件接收是，默认是绑定在消息接收的函数上，无法实现对文件的接收。所以在传输文件时，首先发送消息告诉对方将要发送文件，然后接收方将信号从接收消息的函数断开，连接上接收文件的函数，并发送准备就绪的信号给发送端，然后才开始发送消息。  
断开和连接信号的函数如下：  
```
disconnect(tcpSocket, &QTcpSocket::readyRead, this, &Controller::receivedata);
connect(tcpSocket, &QTcpSocket::readyRead, this, &Controller::fileReceive);
```

通过这样的设计可以保证文件的顺利传输。  
## 4服务器端设计
服务器端用于响应客户端的 请求，用来和多个客户端连接形成通信网络。  
服务器端源代码由4个CPP构成，main用于创建主程序和主窗口，Server用于创建程序界面，tcpClientSocket用于实现套接字通信连接，tcpServer用于监听端口并创建套接字连接。  
### 4.1界面设计
界面有一个消息框和一个数据库指令输入框构成，可用于显示当前服务器处理的请求状态和对数据库进行操作，界面简单。  
### 4.2消息传输和文件
消息传输与文件传输和客户端相同，同样由接收函数和发送函数构成，每个消息包含一个类型码和消息内容，用于传输消息，同样使用“::==”进行内容分隔，文件传输时会对信号进行重新绑定。  
### 4.3数据库实现
使用的是SQLite3数据库，因为其使用简单属于Qt框架自带并且拥有完整的基础功能。数据库拥有三个表格，分别是user、item、mesg表格。创建表格的SQL语句如下：  
```
query.exec("create table if not exists user (id varchar(20) primary key,password varchar(20),phone varchar(20),mail varchar(40))");
    query.exec("create table if not exists item (id int primary key,user varchar(20),title varchar(40),addr varchar(40),size varchar(20),louceng varchar(20),price varchar(20),ps varchar(40),time varchar(20),pic blob)");
    query.exec("create table if not exists mesg (id int primary key,receiver varchar(20),sender varchar(20),message varchar(40),time varchar(20),read int)");
}
```

通过select进行条目的选择，update进行修改、insert进行添加和delete对条目进行删除。  
## 5实现功能
实现了用户账号的注册和信息的维护、通知和对话消息的显示、用户间的交流、客户端更新、租房信息的发布和删除、租房内容的显示、各类消息的数据库存贮。  
## 6改进之处
目前制作完成的app能够实现以上基本功能，但尚存在以下不足之处，需要后续的改进：  
（1）文件传输时不能中断、也不能进行其他的消息传输，否则可能会引起程序出错。  
因为是和消息传输使用的同一个套接字，所以在文件传输是不能进行消息传输，也不能中断、否则无法回归正常的消息传输模式，造成服务器端或客户端不响应。  
可以通过文件传输时建立新的文件传输专用套接字完美解决此问题。新建套接字不会影响现有消息传输套接字的运行，同时也不存在信号的转接，不会造成消息传输失去响应，可以完美解决文件传输带来的问题。  
（2）过久没有消息传输会断开连接。  
因为是客户端开始运行时就连接客户端，如果太久没有进行消息传输会误认为连接失败从而断开连接。  
可以通过发送心跳包对服务器端定时进行冗余的通信，保证此连接不会断开。  
另一种解决方法是只在需要连接时连接、传输完成后断开，来保证数据传输时连接有效。  
