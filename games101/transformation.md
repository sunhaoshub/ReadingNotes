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
