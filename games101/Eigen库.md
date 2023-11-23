# The Matrix Class

​	在Eigen库中，向量（vector）看作是矩阵（matrix）的特例，即n行一列的矩阵，它们都是Matrix模板类的对象；

# **Matrix and vector arithmetic**

1.创建一个三维向量

```C++
Eigen::Vector3f v(1.0f,2.0f,3.0f);
```

2.创建一个3*3的矩阵

```C++
Eigen::Matrix3f i;
i << 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0
```

3.创建一个3*4的矩阵

```c++
Eigen::Matrix<float,3,4> matrix_3x4 = Eigen::Matrix<float,3,4>::Constant(1.0f)
```



## Addition and subtraction

Eigen库不做自动类型推导

