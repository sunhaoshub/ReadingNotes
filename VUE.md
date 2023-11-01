# JavaScript基础知识

var 没有作用域限制，const，let 有作用域限制

对象：

```javascript
var obj1 = new Object();
obj = {
  name:"Simon",
  age:"20",
  email:"simon@gmail.com",
  contract:{
    phone:"1234567",
    Telegram:"@Simon"
    }
   };
   console.log(obj);
```

数组：

```javascript
var a = new Array();
var b = [];
```

在数组开头添加元素：unshift()



在html文件中引入vue

```html
<script src="引入的CDN路径">
	var vm = new Vue({
        el:"xxx".
        data:{
        
    }
    })
</script>
```





# vue七大属性

1.el属性

用于指示vue编译器从什么地方开始解析vue的语法，可以说是一个占位符

2.data属性

用于组织从vue中抽象出来的属性，可以说将视图的数据抽象出来存放在data中

3.template属性

用来设置模板，会替换页面元素，包括占位符

4.methods属性

放置页面中的业务逻辑，js方法一般都放置在methods中

5.render属性

创建真正的Virtual Dom

6.computed属性

用于计算Vue.js计算属性，计算属性在处理一些复杂逻辑时很有用

7.watch属性

Vue.js监听属性watch，我们可以通过watch来响应数据的变化 watch:function(new,old){}

监听data中数据的变化，一个返回新值，一个返回旧值

# 介绍

什么是响应式？

​	修改元素的值，不需要刷新，相应的值立刻改变

```html
<!DOCTYPE html>
<html lang="en" xmlns:v-binf="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<div id="app">
    {{message}}
</div>

<!--引入js文件-->
<script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
<script type="text/javascript">
   var app = new Vue({
        el:"#app",
        data:{
            message:"Hello,Vue!"
        }
   });
</script>
</body>
</html>

```

## 绑定元素v-bind

```html
<!DOCTYPE html>
<html lang="en" xmlns:v-binf="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    
</head>
<body>
<div id="app-2">
    <span v-bind:title="message">
        鼠标悬停几秒钟查看此处动态绑定的提示信息！
    </span>
</div>

<!--引入js文件-->
<script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
<script type="text/javascript">
   var app = new Vue({
        el:"#app-2",
        data:{
            message:"页面加载于"+new Date().toLocaleDateString()
        }
   });
</script>
</body>
</html>
```

 v-bind:title="message" 将元素节点的title与vue节点的message保持一致



# 基本语法

## v-if

```html
<!DOCTYPE html>
<html lang="en" xmlns:v-binf="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    
</head>
<body>
<div id="app2">
   <p v-if="seen">你现在看见我了</p>
</div>

<!--引入js文件-->
<script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
<script type="text/javascript">
   var app = new Vue({
        el:"#app2",
        data:{
            seen:true
        }
   });
</script>
</body>
</html>
```



## v-for

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <!-- view层 -->
        <div id="app">
            <li v-for="item in items">
                {{item.message}}
            </li>
        </div>
        <!--1.导入 vue.js-->
        <script src="https://cdn.jsdelivr.net/npm/vue@2.6.14"></script>
        <script>
            var vm = new Vue({
                el:"#app",
                //Model 数据
                data:{
                    items:[
                        {message:"vue2"},
                        {message:"vue3"}
                    ]
                }
            });
        </script>
    </body>
</html>
```

```html
<!DOCTYPE html>
<html lang="en" xmlns:v-binf="http://www.w3.org/1999/xhtml">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    
</head>
<body>
<div id="app">
   <p>{{message}}</p>
    <button v-on:click="reverseMessage">点我反转</button>
</div>

<!--引入js文件-->
<script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
<script type="text/javascript">
   var app = new Vue({
        el:"#app",
        data:{
            message:"Hello Vue.js!"
        },
        methods:{
            reverseMessage:function(){
                this.message = this.message.split('').reverse().join('');
            }
        }
   });
</script>
</body>
</html>

```



## 绑定事件

on

方法必须定义在vue的methods对象中，通过v-on去绑定事件

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <!-- view层 -->
        <div id="app">
            <button v-on:click="sayHi">click</button>
        </div>
        <!--1.导入 vue.js-->
        <script src="https://cdn.jsdelivr.net/npm/vue@2.6.14"></script>
        <script>
            var vm = new Vue({
                el:"#app",
                //Model 数据
                data:{
                    message:"hello,world"
                },
                methods:{
                    sayHi:function(event)
                    {
                        alert(this.message);
                    }
                }
            });
        </script>
    </body>
</html>
```

# 双向绑定

vue.js是一个MVVM框架，即数据双向绑定，当数据变化时，视图也发生变化；当视图发生变化时，数据发生变化

可以使用v-model指令在表单\<input\>,\<textarea\>及\<select\>元素上创建双向数据绑定。它会根据控件类型自动选取正确的方法更新元素。v-model本质上是语法糖。它负责监听用户的输入事件以更新数据，并对一些极端场景进行特殊处理

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <!-- view层 -->
        <div id="app">
            <!-- 效果： 在输入框输入的同时，在另一侧进行更新 -->
            输入的文本：<input type="text" v-model="message"> {{message}}
        </div>
        <!--1.导入 vue.js-->
        <script src="https://cdn.jsdelivr.net/npm/vue@2.6.14"></script>
        <script>
            var vm = new Vue({
                el:"#app",
                //Model 数据
                data:{
                    message:"test"
                }
            });
        </script>
    </body>
</html>
```



# vue组件

组件是可复用的vue实例，即一组可重复使用的模板

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <!-- view层 -->
        <div id="app">
            <test></test>
        </div>
        <!--1.导入 vue.js-->
        <script src="https://cdn.jsdelivr.net/npm/vue@2.6.14"></script>
        <script>
            Vue.component("test",{
                template:'<li>Hello</li>'
            });
            var vm = new Vue({
                el:"#app",
                //Model 数据
            });
        </script>
    </body>
</html>
```

# 网络通信

实现Ajax异步通信

出现跨域问题

# 计算属性

计算出来的结果，保存在属性中

可以想象成缓存

# 插槽