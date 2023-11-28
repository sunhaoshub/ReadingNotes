# 介绍

## html中引入

```html
<script src="https://cdn.jsdelivr.net/npm/vue@2/dist/vue.js"></script>
```

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
        var app = new Vue({
            //el ： 指定挂载地元素
            el: '#app',
            data:{
                message: 'Hello,World!'
            }
        });
    </script>
</html>
```

​	所有的东西都是响应式的，在控制台修改app.message，画面中的值也对应改变；

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

#### v-model

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

## 动态参数



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

## 侦听器

​	 Vue 通过 `watch` 选项提供了一个更通用的方法，来响应数据的变化。当需要在数据变化时执行异步或开销较大的操作时，这个方式是最有用的。

​	

# Vue3

