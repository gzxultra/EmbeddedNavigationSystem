# Qt embedded software

基于ARM2410的生活信息推荐系统：
在s3c2410开发板上使用温湿度传感器采集数据，存入sqlite3，在触摸屏上进行数据可视化；
设计了一个软键盘提供支持在嵌入式设备触摸屏上的输入；
使用http协议和PlaceSuggestion，BaiduWeather等百度web api获取生活信息，并对xml进行解析，整理后在触摸屏上显示推荐。

To Do List:
* 利用GPS传感器获取当前位置信息；
* 利用百度地图api获取导航路线；
* 获取周边生活信息推荐。

Temporarily, it looks like that,
but I'm still working on it.


![snapshot](http://ww3.sinaimg.cn/large/bfe31badgw1ey1s1ij9flg211d0mqnpd.gif)
