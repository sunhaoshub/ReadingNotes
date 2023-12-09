	如何把多个三角形画在屏幕上，并且让其遮挡关系是正确的？（可见性/遮挡性）

​		深度缓存/缓冲（Z-buffering）

Painter's Algorithm：先画远处的物体（光栅化），再由远到近逐次画

深度：观测点离我们的距离

画家算法的不足：如立方体，画好后面那个面之后，上下左右面的顺序不同，可能会多出来一条线；

![image-20231127210819178](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231127210819178.png)

环形关系，画家算法也不适用



深度缓存算法：每个像素存储离我们最近的一个元素

![image-20231127211235785](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231127211235785.png)

![image-20231127211423836](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231127211423836.png)

距离由远到近，颜色从白（255）到黑（0）

# Z-Buffer Algorithm

1.将深度缓存全部初始化为∞

2.在光栅化的过程中

```C++
for(each triangle T)
    for(each sample(x,y,z) in T)
        if(z < zbuffer[x,y])//当前z比之前的距离摄像机更近
        {
            framebuffer[x,y] = rgb;
            zbuffer[x,y] = z;
        }
		else
            do nothing;
```



Shading:对不同物体应用不同材质

# Blinn_Phong Reflectance Model	

一束光线打到物体上，会均匀地向四周反射



着色会形成三种不同的部分：**高光、漫反射、间接光照**

![image-20231130221321699](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130221321699.png)





目前不考虑阴影的生成



## 漫反射项

**法线和光线的夹角**决定了物体表面的亮度

![image-20231127225300643](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231127225300643.png)



假定能量是一个点光源，那么每一个时刻它所散发的能量一定集中在一个球壳上



![image-20231130222908196](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130222908196.png)





![image-20231130223136295](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130223136295.png)

shading point有颜色的原因：吸收颜色，反射自己不能吸收的颜色

漫反射系数kd：为1，表示不吸收任何颜色，即反光；0表示纯黑。用kd来表示明暗。

和观测方向无关

## 高光项

观察方向和**镜面反射方向**接近的时候可以看到高光；

![image-20231130230849596](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130230849596.png)

指数p：正常的向量夹角余弦容忍度太高，导致高光会很大



## 环境光（间接光照）

目前认为是一个常数

![image-20231203184536089](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203184536089.png)



## 结合



![image-20231130231533172](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130231533172.png)

# 着色频率

![image-20231130232820545](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130232820545.png)

逐个三角形-》逐个顶点-》逐个像素

![image-20231203190015002](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203190015002.png)

![image-20231203190038436](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203190038436.png)

![image-20231203190156492](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203190156492.png)







如何求顶点的法线？

![image-20231130233520496](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130233520496.png)

# 图形（实时渲染）管线

着色模型及着色模型的使用

Pipeline：从一个场景到一张图片经历了什么

![image-20231130234115524](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231130234115524.png)

现代GPU可以决定按像素着色还是按顶点着色（Shader）

Shader是通用的，适用于每一个顶点或像素

# 纹理映射

把一张图贴在物体表面，假设已经知道了三角形的对应关系

纹理是用来定义着色时各个不同点的属性

如何定义一个点的基本属性？

![image-20231201001852846](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231201001852846.png)

## 重心坐标

​	实现三角形内部**平滑的过度**；

![image-20231202151106708](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231202151106708.png)

​	三角形内部任意一点的重心坐标，可以通过面积比来计算

![image-20231202152147812](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231202152147812.png)

![image-20231203194946879](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203194946879.png)



三角形的重心，三个参数都是1/3

在三维空间中应该对三维空间做插值，再对应到二维结果上去

## 如何把纹理应用到实际的插值中？

![image-20231203200321455](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203200321455.png)

问题：分辨率高但是纹理小，导致纹理被拉大，这导致在一个范围内都是相同的纹理元素





## 双线性插值

给定非整数坐标如何得到值

![image-20231203200918348](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231203200918348.png)

![image-20231202163549756](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231202163549756.png)

## Mipmap

允许做近似的、正方形的快速范围查询

## Bump Mapping

法线贴图，可以定义一个复杂的纹理，而不改变几何形体；

把任何一个像素的法线，做一个扰动（纹理定义了相邻位置的相对高度移动）；

![image-20231209152432601](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231209152432601.png)

![image-20231209152905257](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231209152905257.png)

![image-20231209153139399](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231209153139399.png)

## DisplacementMapping

位移贴图

