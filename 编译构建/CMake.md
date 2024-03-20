			创建文件CMakeLists.txt，编写相关命令，执行make命令，生成makefile文件，
		再执行make命令。
			生成一系列库文件，引入到第三方项目；
## 检查是否安装CMake
	cmake --version命令
## CMake安装命令
	sudo apt install cmake
# 基本使用
## 注释
### 单行注释
	#注释
### 多行注释
	#[[
	xxxx
	xxxxxxxxxxxx
	xxxxxxxxxxxxxxxxxx
	]]
## 指定最低版本
	cmake_minimum_required
## 定义工程名称
	project(项目名称)
## 生成可执行程序
	add_exectuable(可执行程序名称   源文件名称)
## cmake命令
	cmke CMakeLists.txt所在路径
## CMake中set命令的使用
### 定义变量
		定义一个变量，将文件名对应的字符串存起来；

```cpp
set(VAR VALUE)
#例
set(SRC_LIST add.cpp div.cpp sub.cpp main.cpp)
add_executable(app ${SRC_LIST})
```
### 指定C++标准
#### 在CMakeLists.txt文件中使用
		例如使用C++11标准：
```cpp
set(CMAKE_CXX_STANDARD 11)
```
#### 在执行cmake命令时使用
		例如使用C++11标准
```cpp
cmake CMakeLists.txt路径 -DCMAKE_CXX_STANDARD=11
```
### 指定可执行文件的位置
		对应一个宏，叫做EXECUTABLE_PATH，例如：
```cpp
set(HOME /home/robin/Linux/Sort)
set(EXECUTABLE_PATH ${HOME}/bin)
```
	如果子目录不存在，会自动创建；如果使用相对路径，那么./对应的路径就是makefile文件所在的路径；
## 搜索文件
		当一个项目中文件很多的时候，在编写CMakeLists.txt文件时不可能全部将其列出来；
### aux_source_directory
		查找某个路径下的所有源文件，命令格式为：
```cpp
add_source_directory(<dir> <vairable>)
#<dir> 要查找的目录
#<variable> 将dir目录下的源文件列表存储到该变量中
```
### file

```cpp
file(GLOB/GLOB_RESOURCE 变量名 要搜索的文件路径和文件类型)
```
* GLOB：将指定目录下搜索到的满足条件的所有文件名生成一个列表，并将其存储到变量中
* GLOB_RESOURCE：递归搜索指定目录
	当前CMakeLists.txt所在目录的宏：${CMAKE_CURRENT_SOURCE_DIR} / ${PROJECT_SOURCE_DIR}
## 指定头文件目录
		有时候源文件和头文件不在一个目录下

```cpp
include_directories(xxx)
```
## 通过CMake制作库文件
	Linux下库：lib_xxx.so/a，so代表动态库，a代表静态库
	Windows下ku：lib_xxx.dll/lib dll代表动态库，lib代表静态库
	动态库是有可执行权限的
	发布给使用者两部分数据，一是库文件，二是头文件
### 指定库文件输出路径
	宏：LIBREAY_OUTPUT_PATH，使用set命令
## 链接库文件
### 链接静态库

```cpp
link_libraries(lib1 lib2 lib3 ... libn)
#可以链接多个静态库
#可以写全名libxxx.a，也可以写掐头去尾后的名字xxx
```
		如果是系统的库，可以直接写名字；但如果不是系统中库，则不知道路径，需要知道具体路径，使用命令：
```cpp
link_directories(path)
```
### 链接动态库
		命令如下：
```cpp
target_link_libraries(
	<target>
	<PRIVATE|PUBLIC|INTERFACE> <item>
	<PRIVATE|PUBLIC|INTERFACE> <item1>
	...
	<PRIVATE|PUBLIC|INTERFACE> <itemn>
)
#target 指定要加载动态库的文件的名字 可以是源文件、动态库文件、可执行
#PRIVATE|PUBLIC|INTERFACE 动态库访问权限，默认为PUBLIC
# 动态库链接具有传递性
# PUBLIC: 如A 链接了B和C，且B、C均声明为PUBLIC，D链接了A，那么在D中也可以调用B和C中的函数
# PRIVATE 若B和C均声明为PRIVATE，则只有A能调用B和C中的函数，D不能直接调用
# INTERFACE 若B和C均声明为INTERFACE，则不会被链接到A中，只会导出符号
```

