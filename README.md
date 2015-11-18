# Qt embedded software Engineering

## **Features：**

基于ARM2410的百度地图导航和生活信息推荐系统：

* 默认使用外设键盘输入，方便s3c2410用户，设计了支持触摸操作软键盘；
* 使用了baidu placeSuggestion提供以用户输入字符为关键字的周边地址时实推荐；
* 搜索从北京工业大学到用户输入地址的公交/地铁线路，以html展示在触摸屏上，支持拖拽缩放导航路线；
* 用SUBMAIL API将获取到的线路信息（文字）推送到手机上。

## **Snapshot:**

> 主界面：

![picture](http://i12.tietuku.com/d3c9670ccee3e78e.jpg)

> 外设键盘/软键盘 输入拼音，提供周边地点推荐：

![picture](http://i12.tietuku.com/354a95e7b8538104.jpg)

> 支持中文字符关键字（UTF-8）

![picture](http://i12.tietuku.com/f7c5e7055deadf9d.jpg)

> 支持拼音关键字：

![picture](http://i12.tietuku.com/94b14d056cd96592.jpg)

> 软键盘示意图：

![picture](http://i12.tietuku.com/2ba6e28fa560856a.jpg)

> 给出以北京工业大学到指定地点的最佳乘车路线:

![picture](http://i12.tietuku.com/4c5d82a10cc60a76.jpg)

> Debug窗口显示每次HTTP请求Reply信息:

![picture](http://i12.tietuku.com/695de3a3161f61be.jpg)

> 浏览器窗口下拉给出详细公交路线文字说明:

![picture](http://i12.tietuku.com/9e9e2671adb5ae33.jpg)

> 如果输入为空或者号码不是11位则弹窗提示：

![picture](http://i12.tietuku.com/f8ee605314f5357e.jpg)

> 短信发送成功：

![picture](http://i12.tietuku.com/f677108c40b44d68.jpg)

> 导航信息推送到手机，示意图：

![picture](http://i12.tietuku.com/0c90dc0ea1fae4a4.jpg)



## **How to Build and Run:**

On Macintosh or Linux：

在终端里依次敲入如下命令：

``` bash
git clone https://github.com/gzxultra/arm-thermometer-project.git
cd ./arm-thermometer-project/EmbeddedSystem
qmake
make
./EmbeddedSystem
```

on s3c2410cl board:

首先需要搭建交叉编译环境：

确保你的host主机安装了`Qt（x64/x86 ）`，`GNU gcc（x86/x64 ）`，开发板安装了embedded linux，成功烧写了文件系统，并安装了`qmake(embedded)`， `arm-linux-gcc`，并将开发板连接至host主机。

第二步，为了使用web api，我们需要配置虚拟机和开发板之间的双网卡以共享网络连接，并设置DNS以提供http解析。

1. 修改物理机IP为`192.168.137.1`，做双网卡共享上网的网关使用;
   
2. 修改虚拟机IP和网关，并在GUI界面里设置通用的DNS（如`114.114.114.114`）;
   
   ``` bash
   ifconfig 192.168.137.2
   route add default gw 192.168.137.1
   ```
   
3. 在Xshell里修改开发板IP和DNS;
   
   ``` bash
   ifconfig 192.168.137.3
   vi etc/resolve.conf
   ```
   
   在vi打开的文件里添加DNS，如`114.114.114.114`，保存并退出。

第三步，进行交叉编译。

``` bash
# Type on Xshell, mount the path
mount -t nfs -o intr,nolock,rsize=1024,wsize=1024 192.168.137.2:/arm2410cl /mnt/nfs
# Type on Virtual Machine, compile it
/usr/local/Trolltech/embedded-4.4.0/bin/qmake
make
# Type on Xshell，run it
./EmbeddedSystem
```

