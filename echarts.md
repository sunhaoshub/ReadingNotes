# 基本套路

```JavaScript
<script>
    //初始化实例
    var myChart = echarts.init(document.getElementById('xxx'));
	//指定图表的配置项和数据
	var option = {
        xAxis: {
        type: 'xxx',
        data: []
      },
      yAxis: {},
      series: [
        {
          type: '',
          name: '',
          data: []
      ]
    };
	//显示图表
	myChart.setOption(option);
</script>
```



# 图表及样式大小

```javascript
echarts.init(document.getelementbyid(""));
```

```javascript
xxx.resize();
//窗口自适应大小
```

# 数据集



1.在series中设置数据

2.在dataset中设置数据

