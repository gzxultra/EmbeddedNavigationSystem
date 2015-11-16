# Qt embedded software


**Introduction:**
基于ARM2410的百度地图导航和生活信息推荐系统：
* 设计了支持触摸屏的软键盘，方便s3c2410的输入；
* 利用baidu placeSuggestion提供以用户键入字符为关键字的周边地址推荐；
* 搜索从北京工业大学到用户输入地址的公交/地铁线路，以web的形式显示在触摸屏上，支持拖拽和缩放；
* 用SUBMAIL API将获取到的线路信息推送到手机上。


**How to Build:**

```bash
git clone https://github.com/gzxultra/arm-thermometer-project.git
cd ./arm-thermometer-project/EmbeddedSystem
qmake
make
./EmbeddedSystem
```


**To Do List:**

* 利用GPS传感器获取当前位置信息，替换出发地；
* 获取周边生活信息推荐；
* 修改推送内容;
* 程序实现细节的修改（qrc路径，平台兼容性，etc.）
* linux系统由于换行符或者其他原因（还不清楚），xmlparser读写有问题，正在修改。


**snapshot:**

Temporarily, it looks like that,
but I'm still working on it.

![snapshot](http://ww1.sinaimg.cn/large/bfe31badgw1ey2mb2a2phg211d0mqhdu.gif)
