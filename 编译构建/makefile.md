文件名：Makefile，必须这么写

执行命令 make

基本语法:

```makefile
all:
	echo "hello,makefile"
```



```
目标：依赖（先决条件）
		命令
```



取消命令行：在命令前加@

```makefile
all:
        @echo "hello,makefile"
```



* 在构建目标时，必须保证先决条件先被构建；
* makefile通过先决条件的时间戳来确定多次执行时哪些文件需要重新编译

* 当可执行文件与目标不一致时，会导致make的时候找不到，也需要重新编译



## 假目标

解决目标文件与已存在文件冲突

make假目标时，所在规则的命令都会执行

.PHONY