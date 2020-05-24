# XDU-OS-Course-Design

由于COVID-19的影响，操作系统课设不得不在家进行。按照惯例，应该是要在机房中进行的，因为机房的电脑经过了同学们的千锤百炼，应该是比较稳定的，而且机房的电脑一般是和老师提供的软件比较吻合。

但是，某在家中完成了这次课设，用的是自己早就已经安装好的VMware15和Ubuntu18.04，和课程视频的版本严重不匹配，踩了无数天坑，重装达十余次。现用自己的惨痛经历为众人填坑。

## Pre

正式实验前有几个小实验。一下是一些注意事项，你没遇到并不意味着后面的实验不会遇到：

+ 内存2~4G(如果开机常黑屏建议4G)、4个核心、硬盘至少35G(高手可以不要35G)、网络桥接模式；
+ **VMware使用14、15版本，Ubuntu18+版本**均能行稳致远，某**上面的文件提供了Ubuntu镜像**，VMware自行下载即可；
+ VMware Tools安装很有可能不起作用，请按上一条处理；
+ VMware Tools拖动文件很可能**卡死**，请kill进程重启，重复n次总有一次成功，此时记住截图写进报告；
+ VMware Tools频繁卡死怎么传文件，[文叔叔](https://www.wenshushu.cn/)走一波；
+ VMware在“墙内”速度缓慢请自行度娘，若在~~法外之地~~下载速度感人且本机可以进入~~法外之地~~参考上一条。
+ 虚拟机误删恢复：菜单栏—>文件—>扫描虚拟机(在你原来虚拟机的安装路径中扫描)

**为什么不要用学校的版本**：

* 你的电脑环境!=学校的电脑环境；
* 学校提供的软件及内核版本极其老旧，出现的问题不敢保证；
* 如果你部分采用了学校版本，部分采用的非学校版本，通常是会让你暴跳如雷难以压制情绪的。

## LAB1 内核编译

Tips：

+ 不要编译学校的提供的kernel，从[官网](https://www.kernel.org)下载最新的或者用我提供的(否则会出现gcc版本不一致、编译错误等情况)；
+ 建议先看完学校视频，**搞清楚步骤之后**，再参照[CSDN教程](https://blog.csdn.net/qq_36290650/article/details/83052315)完成内核编译；

+ 编译环境18.04Ubuntu下需要：

```
sudo apt-get install gcc make libncurses5-dev openssl libssl-dev 
sudo apt-get install build-essential 
sudo apt-get install pkg-config
sudo apt-get install libc6-dev
sudo apt-get install bison
sudo apt-get install flex
sudo apt-get install libelf-dev
```

+ **效率提升利器**：多线程编译(前提是你配置的时候有多个核心)，在make的时候请这样(4个核的话写-j4，x个核就写-jy，其中y≤x)：

```
sudo make -j4
```

—为什么编译不同的内核?

—学校提供的很难完整做下来，不同的内核版本有加分，新的内核版本简单。