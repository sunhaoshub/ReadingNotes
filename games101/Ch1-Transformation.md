# 二维变换

## 缩放变换

$$
x' = sx\\
y' = sy
$$

转换为矩阵形式：
$$
\begin{bmatrix}
        x' \\
        y' \\
 \end{bmatrix}
 =\begin{bmatrix} s&0\\0&s \end{bmatrix} \times\begin{bmatrix} x\\y \end{bmatrix}
$$

## 切变

![image-20231115210839992](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231115210839992.png)
$$
\begin{bmatrix}x'\\y'\end{bmatrix} = \begin{bmatrix}1&a\\0&1\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}
$$

## 旋转

![image-20231115211335201](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231115211335201.png)

默认按照原点逆时针旋转

通过（0，1），（1，0）两个特殊的点推导；



# 齐次坐标

![image-20231115215602146](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231115215602146.png)

平移变换，无法像之前一样写成通用的矩阵变换的形式

正常的坐标变换公式：
$$
\begin{bmatrix}x'\\y'\end{bmatrix} = \begin{bmatrix}a&b\\c&d\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix}+
\begin{bmatrix}t_x\\t_y\end{bmatrix}
$$
在二维坐标/向量的基础上增加一个维度
$$
2D\hspace{0.3cm} point = (x,y,1)^{T}
\\
2D\hspace{0.3cm} vector = (x,y,0)^{T}
$$
则
$$
\begin{bmatrix}x'\\y'\\w'\end{bmatrix}
=
\begin{bmatrix}
1&0&t_x\\
0&1&t_y\\
0&0&1
\end{bmatrix}
\begin{bmatrix}
x\\y\\1
\end{bmatrix}
=
\begin{bmatrix}
x+t_x\\
y+t_y\\
1
\end{bmatrix}
$$


为什么点的第三维坐标是1，而向量是0？

​	保证向量的平移不变性，如果向量的第三维是1，则方向可能变化；

# 逆变换

​	对应逆矩阵



# 3D Transformation

## Rotate

![image-20231116201739453](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116201739453.png) 

​	

​	将任何的三维旋转分解成绕x轴、y轴、z轴的旋转
$$
R_{xyz}(\alpha,\beta,\gamma)=R_x(\alpha)R_y(\beta)R_z(\gamma)
$$
​	绕任意轴旋转：先把物体移到原点，在原点进行旋转，把旋转后的结果移回去

## 罗德里格斯公式

# Viewing（观测） transformation

![image-20231116204324081](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116204324081.png)

模型-》视图-》投影变换

## View（视图）/Camera transformation

​	将三维空间中的物体转化成二维图片

​	1.规定场景，2.规定相机/人眼的位置

![image-20231116204459401](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116204459401.png)

​	Position：相机放置的位置

​	Look-at/gaze direction ：摄像头的方向

​	Up direction：相机的角度（竖着拍，横着拍，斜着拍····）

​	只要相机和物体之间没有相对运动，那么拍出来的照片永远是一样的，基于以上考虑，我们可以把相机的位置作为坐标系的原点，运动的永远是其他物体

![image-20231116210011471](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116210011471.png)

①把相机原本的点移动到原点，移动矩阵
$$
T_{view}=
\begin{bmatrix}
1&0&0&-x_e\\
0&1&0&-y_e\\
0&0&1&-z_e\\
0&0&0&1
\end{bmatrix}
$$
②把看的方向旋转到-Z方向，t旋转到y方向，e轴移动到x轴方向

​	**旋转矩阵是正交矩阵**；

​	逆向思考，把x轴旋转到（g x t），y轴旋转到t，z轴旋转到-g的矩阵容易求，又旋转矩阵是正交矩阵，所以逆矩阵就是其转置；

![image-20231116211310775](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116211310775.png)

## Projection（投影） transformation

![image-20231116213950236](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116213950236.png)

### Orthographic（正交） projection

没有“近大远小”的性质

![image-20231125221222360](C:\Users\sunha\Desktop\book\ReadingNotes\games101\transformation.assets\image-20231125221222360.png)

​	定义了六个点 x轴上的左、右（l，r），y轴上的上、下（t，b）z轴上的远近（n，f）

![image-20231116214822070](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116214822070.png)

### Perspective（透视） projection

有“近大远小”的性质

图形学中应用最广
$$
[
\left(\frac{kx}{k}, \frac{ky}{k}, \frac{kz}{k}, \frac{k}{k}\right) = \left(x, y, z, 1\right)
]
$$
只是表示方式不同

![image-20231116220842299](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116220842299.png)

​	先把远处的平面“挤”成和近处平面大小一样的（将棱台挤成长方体），然后再做正交变换；

规定：

​	1.近平面不变

​	2.远平面z值不变

​	3.远平面中心点不变

![image-20231125222704488](C:\Users\sunha\Desktop\book\ReadingNotes\games101\transformation.assets\image-20231125222704488.png)

沿x轴负方向看（从侧面看），得到y和z的对应关系，从y轴负方向看，得到x和z的对应关系









![image-20231116222254110](C:\Users\sunha\AppData\Roaming\Typora\typora-user-images\image-20231116222254110.png)

![image-20231125223725060](C:\Users\sunha\Desktop\book\ReadingNotes\games101\transformation.assets\image-20231125223725060.png)

![image-20231207215751427](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch1-Transformation.assets\image-20231207215751427.png)

![image-20231207215813879](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch1-Transformation.assets\image-20231207215813879.png)



![image-20231207215827136](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch1-Transformation.assets\image-20231207215827136.png)



![image-20231207215441356](C:\Users\sunha\Desktop\book\ReadingNotes\games101\Ch1-Transformation.assets\image-20231207215441356.png)
