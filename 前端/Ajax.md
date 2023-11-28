XML：可扩展标记语言，被设计用来传输和存储数据，没有预定义标签，全是自定义标签；

目前使用JSON

请求报文：

![image-20231128103040603](C:\Users\sunha\Desktop\book\ReadingNotes\前端\Ajax.assets\image-20231128103040603.png)

响应报文：

![image-20231128103014326](C:\Users\sunha\Desktop\book\ReadingNotes\前端\Ajax.assets\image-20231128103014326.png)





Express基本使用：

```javascript
//1.引入express
const express = require('express');

//2.创建应用对象
const app = express();

//3.创建路由规则 request是对请求报文地封装，response是对响应报文的封装
app.get('/',(request,response)=>{
    response.secd('Hello,Express');
});
//4.监听端口启动服务
app.listen(8000,()=>{
   console.log("服务已启动，8000端口监听中......"); 
});
```

