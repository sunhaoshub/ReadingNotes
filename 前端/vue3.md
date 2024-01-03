使用vite创建vue3项目：

vite：新的前端构建工具

命令：

```
npm create vue@latest
```

入口文件：index.html

/src/main.ts 整个项目的根基

通过createApp函数创建应用实例

```typescript
import './assets/main.css'

//创建App 盆
import { createApp } from 'vue'
//组件 根  其他的组件如A.vue，B.vue类似花的枝干
import App from './App.vue'

createApp(App).mount('#app')
```



App.vue

```vue
<template>
    <div id="app">
        Hello,World!
    </div>
</template>

<script lang="ts">
    export default{
        name: 'App'//暴露组件名
    }
</script>

<style>

</style>

```

# vue3核心语法

## setup

一个配置项，是组合式API“表演的舞台”，组件中用到的：数据、方法、计算属性等，均配置在setup中

setup并不维护this，this为undefined

```vue
<template>
    <div id="person">
        <h2>name: {{ a }}</h2>
        <h2>age: {{ b }}</h2>
        <!-- <button @click="ageAdd">增加年龄</button>
        <button @click="showTel">显示电话</button>
        <button @click="nameChange">修改姓名</button> -->
    </div>
</template>

<script lang="ts">
    export default{
        name: 'App',//暴露组件名
        setup(){
            //数据 此时数据不是响应式，修改后的数据不会在前台呈现
            let name = '张三';
            let age = 18;
            let tel = '12324543678';

            //方法

            return {a:name,b:age}
        }
    }
</script>

<style>
    .person{
        background-color: skyblue;
        box-shadow: 0 0  10px;
        border-radius: 10px;
        padding: 20px;
    }
</style>
```

