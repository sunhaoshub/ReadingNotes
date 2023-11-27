​	如何把多个三角形画在屏幕上，并且让其遮挡关系是正确的？（可见性/遮挡性）

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

# 漫反射（Diffuse Reflection）

​	一束光线打到物体上，会均匀地向四周反射

![image-20231127225300643](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch3-Shading.assets\image-20231127225300643.png)