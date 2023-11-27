在Sources（源码）位置打断点

比较运算符

```JavaScript
// = 赋值
// == 等于 类型不一样，值一样，也会判断相等，如1和'1'
// === 绝对等于 类型一样，值一样
```

尽量避免浮点数运算，防止出现精度问题

对象：

```JavaScript
var person = 
    {
        name:"1111",
        age:"2222",
        skills:[1,2,3,null,true,'333']
    }
```

严格检查模式strict

需要支持ES6，语法：

```javascript
'use strict'
```

且必须放在第一行



模板字符串

反引号:``

```javascript
const name = 'world';
console.log(`hello,${name}`)
```





字符串不可变,，长度不可变：

数组：

数组长度可变，给.length()赋新值即可

通过元素获取下标索引：

```javascript
a = ['a','b','c',]
a.indexOf('c');
```

slice():类似字符串的subString()，返回一个新的数组

push、pop

往后面拼接 contact，返回一个新的数组



对象中是否含有某个元素：in



forEach循环：

```javascript
a = [1,2,3,4,5,6,7,8,9];
a.forEach(function(value){console.log(value)});
```



函数：

定义方法一：

```javascript
function f(x)
{
    return "Hello,world"+x;
}
```

定义方法二：

```javascript
var a = fintion(x){
    return "hello,world"+x;
}
```

通过a(x)来调用



map()：

​	返回一个数组，数组内容为原始数组调用函数处理后的结果













操作BOM：

BOM：浏览器对象模型

window 浏览器窗口

screen 屏幕属性

location 当前页面的url信息

document：当前页面，html dom树

​	获取cookie：document.cookie















**操作dom**：

​	![image-20231126160902748](C:\Users\sunha\Desktop\book\ReadingNotes\JavaScript.assets\image-20231126160902748.png)



获取元素：

​	getElementByTagName/Id/ClassName()

获取子节点的值：

​	.children;

更新dom节点：

​	更新文本值：innerText

​	更新HTML元素：innerHTML = \'\<strong>123\</strong>';（加粗的123）

​	删除节点：先获取父元素（.parentElement），再通过父元素删除自己



# Reflect
