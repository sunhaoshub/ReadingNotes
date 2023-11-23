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

* 采样

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-2023111821541237.png)

恰好在边上的情况，自己定义一个标准



可能导致的问题：锯齿（走样）

# 反走样

采样产生的问题：锯齿、摩尔纹（拿手机去拍显示屏产生的不正常纹路）、车轮效应（向前行驶的汽车。轮子看起来向后）.....

产生以上问题的本质就是信号的变换太快了，以至于采样跟不上

在采样前先进行模糊操作；

## 频域（Frequency Domain）

![](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122223040956.png)

走样：同样的采样频率去采样两个不同的函数，得到的结果无法区分

![image-20231122223419851](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122223419851.png)

傅里叶变换可以把一个函数从时域变到频域

滤波 = 卷积（平均）

![image-20231122224817413](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122224817413.png)

![image-20231122224927662](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122224927662.png)

![image-20231122225200493](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225200493.png)

采样就是重复频率的内容

如何做采样？

​	给定原始信号a，再给定冲击函数b，两者相乘

![image-20231122225837319](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225837319.png)

![image-20231122225913572](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Rasterization.assets\image-20231122225913572.png)