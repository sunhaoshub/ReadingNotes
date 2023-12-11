# 介绍

## html中引入

```html
<script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
```

## 数据代理

Object.defineProperty(添加属性的对象，属性名，{配置项})

![image-20231207154012584](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231207154012584.png)

获取数据：get，设置数据：set

![image-20231207161844708](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231207161844708.png)

## 声明式渲染

​	vue的核心就是允许用**模板语法**来**声明式**地将数据渲染到DOM中

```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app">
            {{message}}
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        //构造函数，参数是一个对象
        var app = new Vue({
            //el ： 指定挂载地元素，通常是id选择器
            el: '#app',
            //对象
            data:{
                message: 'Hello,World!'
            }
        });
    </script>
</html>
```

​	所有的东西都是响应式的，在控制台修改app.message，画面中的值也对应改变；

​	构造函数和容器是一一对应的关系

###  v-bind

```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app-2">
            <span v-bind:title="message">
                鼠标悬停几秒钟查看此处动态绑定的提示信息！
            </span>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var app2 = new Vue({
            el: '#app-2',
            data:{
                message: '页面加载于'+new Date().toLocaleDateString(),
            }
        });
    </script>
</html>
```



v-bind:title="message"的含义是将该元素节点的title与Vue实例的message绑定在一起；

### 条件与循环

#### v-if

```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app-3">
            <p v-if="seen"> You can see me </p>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var app3 = new Vue({
            el: '#app-3',
            data:{
                seen: true,
            }
        });
    </script>
</html>
```

#### v-for

```C++
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app-4">
            <ul>
                <li v-for="todo in todos">
                    {{todo.text}}
                </li>
            </ul>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var app4 = new Vue({
            el: '#app-4',
            data:{
                todos: [
                { text: '学习 JavaScript' },
                { text: '学习 Vue' },
                { text: '整个牛项目' }
                ]
            }
        });
    </script>
</html>
```

##### 遍历对象

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Vue Slot Demo</title>
  </head>
  <body>
    <div id="root">
      <h2>遍历数组</h2>
     <ul>
      <li v-for="(person,index) in perons"::key="index">{{ person.name }}------{{ person.age }}</li>
     </ul>
     <h2>遍历对象</h2>
     <ul>
      <li v-for="(value,key) in car":key="key">{{ key }}---------{{ value }}</li>
     </ul>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
      const vm = new Vue({
        el:'#root',
        data:{
          perons:[
            {id:'001',name:'张三',age:18},
            {id:'002',name:'李四',age:19},
            {id:'001',name:'王五',age:20},
          ],
          car:{
            name:'奥迪A8',
            price:'70w',
            color:'black'
          }
        },
        
      })
    </script>
  </body>
</html>
```





##### key

![image-20231211092109800](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231211092109800.png)

![image-20231211092124052](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231211092124052.png)

### 处理用户的输入

#### v-on

```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app-5">
            <p>
                {{message}}
            </p>
            <button v-on:click="reverseMessage">
                反转消息
            </button>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var app5 = new Vue({
            el: '#app-5',
            data:{
                message:'Hello Vue.js!',
            },
            methods:{
                reverseMessage:function(){
                    this.message = this.message.split('').reverse().join('');
                }
            }
        });
    </script>
</html>
```

v-on:click="xxx" == @click="xxx"

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Vue Slot Demo</title>
  </head>
  <body>
    <div id="root">
     <button v-on:click="showInfo($event,66)">test</button>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
      const vm = new Vue({
        el:'#root',
        data:{
          name:'尚硅谷',
          address:'鸿福科技园'
        },
        methods:{
          showInfo(event,number){
            console.log(event.target.innerHTML,number);
          }
        }
      })
    </script>
  </body>
</html>
```



#### v-model

实现双向数据据绑定，只能用在表单类型的数据

### 组件化应用

## Vue实例

​	只有一开始就在data中的property发生变化时才会有响应式的特性，如果是后面添加的，则不会有。如果你知道你会在晚些时候需要一个 property，但是一开始它为空或不存在，那么你仅需要设置一些初始值。

### Object.freeze()

​	阻止响应式

```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="app-5">
            <p>
                {{ foo }}
            </p>
            <button v-on:click="foo = 'b'">
                change
            </button>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var Obj = { foo : 'a'};
        Object.freeze(Obj);
        var app5 = new Vue({
            el: '#app-5',
            data:Obj,
            
        });
    </script>
</html>
```

### 生命周期钩子

![Vue 实例生命周期](https://v2.cn.vuejs.org/images/lifecycle.png)



# 模板语法

## 插值

{{  }}

一次性插值：v-once

把文本解析为HTML：v-html

## 指令语法

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Vue Slot Demo</title>
  </head>
  <body>
    <div id="root">
     <a :href="url">test</a>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
      new Vue({
        el:'#root',
        data:{
          url:'http://www.atguigu.com'
        }
      })
    </script>
  </body>
</html>
```



## 缩写

```html
<!-- 完整语法 -->
<a v-bind:href="url">...</a>

<!-- 缩写 -->
<a :href="url">...</a>

<!-- 完整语法 -->
<a v-on:click="doSomething">...</a>

<!-- 缩写 -->
<a @click="doSomething">...</a>
```

# 计算属性和侦听器

## 计算属性

​	data中的叫属性，计算属性是和data同级的；

​	是一个属性，不是方法

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Vue Slot Demo</title>
  </head>
  <body>
    <div id="root">
     姓：<input type="text" v-model="firstName"><br><br>
     名：<input type="text" v-model="lastName"><br><br>
     全名：<span>{{ fullName }}</span>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
      const vm = new Vue({
        el:'#root',
        data:{
          firstName:'张',
          lastName:'三'
        },
        computed:{
          fullName:{
            //get调用时机：初次调用fullNmae时，或所依赖的数据发生变化时
            get(){
              console.log('get被调用了');
              return this.firstName+'-'+this.lastName;
            },
            set(value){
              const arr = value.split('-');
              this.firstName = arr[0];
              this.lastName = arr[1];
            }
          }
        }
      })
    </script>
  </body>
</html>
```



```html
<!DOCTYPE html>
<html>
    <title>
        chapter1
    </title>
    <body>
        <div id="example">
            <p>Original message: "{{ message }}"</p>
            <p>Computed reversed message: "{{ reversedMessage }}"</p>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2"></script>
    <script>
        var app = new Vue({
            el: '#example',
            data:{
                message: 'Hello,World!'
            },
            computed:{
                reversedMessage:function(){
                    return this.message.split('').reverse().join('');
                }
            }
        });
    </script>
</html>
```

​		**计算属性是基于它们的响应式依赖进行缓存的**。只在相关响应式依赖发生改变时它们才会重新求值。这就意味着只要 `message` 还没有发生改变，多次访问 `reversedMessage` 计算属性会立即返回之前的计算结果。

### 简写

​	前提：确定计算属性只读不改

​	直接把get当成function来写

## 侦听器

​	 Vue 通过 `watch` 选项提供了一个更通用的方法，来响应数据的变化。当需要在数据变化时执行异步或开销较大的操作时，这个方式是最有用的。

# 生命周期

mounted（挂载完毕），Vue完成模板解析并把初始的真实的DOM元素放入页面后调用

![生命周期.png](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\生命周期.png)

# 组件基础

```html
<!DOCTYPE html>
<html>
    <title>

    </title>
    <body>
        <div id="components-demo">
            <button-counter></button-counter>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
        Vue.component(
            'button-counter',{
                data:function(){
                    return {
                        count:0,
                    }
                },
                template:'<button v-on:click="count++">You clicked me {{ count }} times.</button>'
            }
        )

        new Vue({ el: '#components-demo' })
    </script>
</html>
```

​	可以多次复用，每次复用都会创建新的实例

​	data必须是一个函数

​	全局注册的组件可以用在其被注册之后的任何 (通过 `new Vue`) 新创建的 Vue 根实例，也包括其组件树中的所有子组件的模板中。

## 通过Prop向子组件传递数据

​	Prop是你可以在组件上注册的一些自定义的attribute。当一个值传递给一个prop attribute时，它就变成了那个组件实例的一个property。

```html
<!DOCTYPE html>
<html>
    <title>

    </title>
    <body>
        <div id="components-demo">
            <blog-post title="My journey with Vue"></blog-post>
            <blog-post title="Blogging with Vue"></blog-post>
            <blog-post title="Why Vue is so fun"></blog-post>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
        Vue.component(
            'blog-post',{
                props:['title'],
                template:'<h3>{{ title }}</h3>'
        })

        new Vue({ el: '#components-demo' })
    </script>
</html>
```



![image-20231206095943200](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231206095943200.png)

```html
<!DOCTYPE html>
<html>
    <title>

    </title>
    <body>
        <div id="blog-post-demo">
            <blog-post
            v-for="post in posts"
            v-bind:key="post.id"
            v-bind:post="post"
            ></blog-post>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
        Vue.component(
            'blog-post',{
                props:['post'],
                template:
                `
                <div class="blog-post">
                <h3>{{ post.title }}</h3>
                <div v-html="post.content"></div>
                </div>
            `
        })

        new Vue({ 
            el: '#blog-post-demo',
            data:{
                posts:
                [
                { id: 1, title: 'My journey with Vue' 				  ,content:'111111111111111111111111111111111111111111111'},
                { id: 2, title: 'Blogging with Vue' , content:'22222222222222222222222222222222222222222'},
                { id: 3, title: 'Why Vue is so fun',content:'3333333333333333333333333333333333333333333' }
                ]
            } 
        })
    </script>
</html>
```

## 监听子组件事件

### 向事件抛出一个值

​	引入一个辅助功能来放大博文的字号，同时让页面的其它部分保持默认的字号。

```html
<!DOCTYPE html>
<html>
    <title>

    </title>
    <body>
        <div id="blog-post-demo">
            <div :style="{ fontSize: postFontSize + 'em' }">
                <blog-post
                v-for="post in posts"
                v-bind:key="post.id"
                v-bind:post="post"
                v-on:enlarge-text="postFontSize += 0.1"
                >
                </blog-post>
            </div>
        </div>
    </body>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
        Vue.component('blog-post',{
            props:['post'],
            template:`
            <div class="blog-post">
                <h3>{{ post.title }}</h3>
                <button  v-on:click="$emit('enlarge-text')">
                    Enlarge text
                </button>
                <div v-html="post.content"></div>
            </div>
            `
        })
        new Vue({
            el:'#blog-post-demo',
            data:{
                posts:[
                    {id:1, title:'My journey with Vue',content:'111111111111111111111111111111111111111'},
                    {id:2,title:'Blogging with Vue',content:'2222222222222222222222222222222222222222222'},
                    {id:3,title:'Why Vue is so fun',content:'3333333333333333333333333333333333333333333'}
                ],
                postFontSize:1,
            }
        })
    </script>
</html>vv
```

可能想让 `<blog-post>` 组件决定它的文本要放大多少。这时可以使用 `$emit` 的第二个参数来提供这个值，$event

### 通过插槽分发内容

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Vue Slot Demo</title>
  </head>
  <body>
    <div id="app">
      <alert-box>
        Something bad happened.
      </alert-box>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
    <script>
      Vue.component('alert-box', {
        template: `
          <div class="demo-alert-box">
            <strong>Error!</strong>
            <slot></slot>
          </div>
        `
      });

      new Vue({
        el: '#app'
      });
    </script>
  </body>
</html>
```

# 组件注册

## 全局注册

```html
Vue.component('component-a', { /* ... */ })
Vue.component('component-b', { /* ... */ })
Vue.component('component-c', { /* ... */ })

new Vue({ el: '#app' })
```

# Prop

## 大小写

Prop的大小写等价于驼峰命名

![image-20231206145357846](C:\Users\sunha\Desktop\book\ReadingNotes\前端\vue.assets\image-20231206145357846.png)

# Vue3

