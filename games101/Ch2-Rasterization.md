# 三角形光栅化

​	透视投影之后，将物体缩放到一个[-1,1]的立方体内；

​	如何定义一个棱台？

​		1.长宽比，类似于显示器的长宽比

​		2.垂直的可视角度（vertical field of view）从相机镜头出发，到上下两条平行边之间的角度

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118204538411.png)

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118204931871.png)

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118205137362.png)

把立方体画在屏幕上；

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118205422774.png)

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118205909207.png)

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118210012791.png)

![image-20231118210136914](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118210136914.png)



![image-20231118210435402](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231118210435402.png)

## 如何在成像设备上画东西？如何把三维空间中的多边形变到屏幕上？

### 判断一个像素的中心点和三角形的关系

​	显示的图像其实是内存中的一块区域（显存）

* 采样

![image-20231126212456686](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231126212456686.png)



```c++
for(int x = 0;x <x_max;x++)
    for(int y = 0; y < y_max;y++)
        imag[x][y] = inside(tri,x+0.5,y+0.5);
```







![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-2023111821541237.png)

恰好在边上的情况，自己定义一个标准



可能导致的问题：锯齿（走样）

# 反走样

采样产生的问题：锯齿、摩尔纹（拿手机去拍显示屏产生的不正常纹路）、车轮效应（向前行驶的汽车。轮子看起来向后）.....

产生以上问题的本质就是信号的变换太快了，以至于采样跟不上

在采样前先进行模糊操作；

## 频域（Frequency Domain）

![image-20231126222606312](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231126222606312.png)

​	通过傅里叶展开，我们可以中的任何一个函数可以拆解成不同的频率



![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122223040956.png)

走样：同样的采样频率去采样两个不同的函数，得到的结果无法区分

![image-20231122223419851](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122223419851.png)

滤波：去掉某些频段的点

傅里叶变换可以把一个函数从时域变到频域，中心定义为最低频的区域，周围定义为最高频的区域



高通滤波：只允许高频信号通过，获得图像边界（在边界处，信号变化得很快）

![image-20231126223901622](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231126223901622.png)











滤波 = 卷积（平均）

![image-20231122224817413](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122224817413.png)





卷积定理：时域上对两个信号卷积，其实对应到两个信号各自的频域上，是各自信号频域的乘积，再做逆傅里叶变换；

即：时域的卷积 = 频域的乘积；





![image-20231122224927662](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122224927662.png)

![image-20231122225200493](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225200493.png)

采样就是重复频域的内容

如何做采样？

​	给定原始信号a，再给定冲击函数b，两者相乘

![image-20231122225837319](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225837319.png)

![image-20231122225913572](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225913572.png)